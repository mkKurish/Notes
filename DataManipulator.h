#pragma once
#include "CustomStructures.h"
#include "json.hpp"
#include <fstream>
#include <string>

using std::to_string;
using std::ifstream;
using std::ofstream;
using json = nlohmann::json;

struct DataManipulator {
private:
	static NotesList mainData;
	static TopicsList topicsData;

	/*
	Updating colors of topic and color of topic for each note with this topic.
	*/
	static void updateTopicsColor(Topic topic) {
		for (int i = 0; i < topicsData.getExistingTopicsNotesList(topic.name)->getSize(); i++) {
			topicsData.getExistingTopicsNotesList(topic.name)->elementAt(i)->topic.colorARGB = topic.colorARGB;
		}
		topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
	}

	/*
	Linking topic in topicsData to the note in mainData.
	*/
	static void setTopicToNote(Note* note, Topic topic) {
		if (topicsData.isTopicExists(topic.name)) {
			topicsData.getExistingTopicsNotesList(topic.name)->add(note);
			topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
			updateTopicsColor(topic);
		}
		else {
			topicsData.add(topic);
			topicsData.lastTopicNotesList()->add(note);
		}
	}
public:
	/*
	Attempt to load saved notes data.

	If there is a file "notesData.json" and it is not empty,
	it is read and the downloaded data are installed.
	mainData and topicsData are being recovered.
	*/
	static void loadData() {
		json jsonHolder;
		ifstream inputFile;
		inputFile.open("notesData.json");
		if (inputFile.is_open()) {
			if (inputFile.peek() != ifstream::traits_type::eof()) {
				inputFile >> jsonHolder;
				for (int i = 0; i < jsonHolder.size(); i++) {
					Note newNote(jsonHolder["note" + to_string(i)]["header"],
						jsonHolder["note" + to_string(i)]["body"],
						Topic(jsonHolder["note" + to_string(i)]["topic"]["name"],
							jsonHolder["note" + to_string(i)]["topic"]["colorARGB"]));
					newNote.indexInMainList = mainData.getSize();
					newNote.creationTime = jsonHolder["note" + to_string(i)]["creationTime"];
					mainData.add(newNote);
					setTopicToNote(mainData.elementLast(), newNote.topic);
				}
			}
		}
		inputFile.close();
	}

	/*
	Saving notes data.

	Writing the settings values to the "notesData.json" file.
	*/
	static void saveData() {
		json jsonHolder;
		Note* n;
		for (int i = 0; i < mainData.getSize(); i++) {
			n = mainData.elementAt(i);
			jsonHolder["note" + to_string(i)] = {
				{"header", n->header},
				{"topic",
					{{"name", n->topic.name},
					{"colorARGB", n->topic.colorARGB}}
				},
				{"body", n->body},
				{"creationTime", n->creationTime}
			};
		}
		ofstream outputFile;
		outputFile.open("notesData.json");
		outputFile << jsonHolder.dump();
		outputFile.close();
	}

	/*
	Adding note to the mainData (list of notes) and
	linking this note to the topic in topicsData.
	*/
	static void addNote(Note note) {
		note.indexInMainList = mainData.getSize();
		mainData.add(note);
		setTopicToNote(mainData.elementLast(), note.topic);
		saveData();
	}

	/*
	Changing note and updating mainData and topicsData.
	*/
	static void changeNote(int index, Note newValues) {
		Note* changingNote = mainData.elementAt(index);
		if (newValues.topic.name != changingNote->topic.name) {
			topicsData.getExistingTopicsNotesList(changingNote->topic.name)->remove(changingNote);
			changingNote->topic.name = newValues.topic.name;
			setTopicToNote(changingNote, changingNote->topic);
		}
		changingNote->topic.colorARGB = newValues.topic.colorARGB;
		changingNote->header = newValues.header;
		changingNote->body = newValues.body;
		updateTopicsColor(changingNote->topic);
		saveData();
	}

	/*
	Removing note from mainData and topicsData.
	*/
	static void removeNote(int index) {
		Note* deletingNote = mainData.elementAt(index);
		topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->remove(deletingNote);
		if (topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->getSize() == 0)
			topicsData.removeByTopic(deletingNote->topic);
		mainData.remove(index);
		saveData();
	}

	/*
	Getting list of notes in order by date (mainData).
	*/
	static NotesList* getNotes() {
		return &mainData;
	}

	/*
	Getting list of topics (topicsData).
	*/
	static TopicsList* getTopics() {
		return &topicsData;
	}

	/*
	Getting count of existing notes.
	*/
	static int notesCount() {
		return mainData.getSize();
	}
};
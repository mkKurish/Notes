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
	static void updateTopicsColor(Topic topic) {
		for (int i = 0; i < topicsData.getExistingTopicsNotesList(topic.name)->getSize(); i++) {
			topicsData.getExistingTopicsNotesList(topic.name)->elementAt(i)->topic.colorARGB = topic.colorARGB;
		}
		topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
	}
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
					mainData.add(newNote);
					setTopicToNote(mainData.elementLast(), newNote.topic);
				}
			}
		}
		inputFile.close();
	}
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
	static void addNote(Note note) {
		note.indexInMainList = mainData.getSize();
		mainData.add(note);
		setTopicToNote(mainData.elementLast(), note.topic);
		saveData();
	}
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
	static void removeNote(int index) {
		Note* deletingNote = mainData.elementAt(index);
		topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->remove(deletingNote);
		if (topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->getSize() == 0)
			topicsData.removeByTopic(deletingNote->topic);
		mainData.remove(index);
		saveData();
	}
	static NotesList* getNotes() {
		return &mainData;
	}
	static TopicsList* getTopics() {
		return &topicsData;
	}
	static int notesCount() {
		return mainData.getSize();
	}
};
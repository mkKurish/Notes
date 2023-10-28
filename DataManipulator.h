#pragma once
#include "CustomStructures.h"

struct DataManipulator {
private:
	static NotesList mainData;
	static TopicsList topicsData;
	static void setTopicToNote(Note* note, Topic topic) {
		if (topicsData.isTopicExists(topic.name)) {
			topicsData.getExistingTopicsNotesList(topic.name)->add(note);
			topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
			for (int i = 0; i < topicsData.getExistingTopicsNotesList(topic.name)->getSize(); i++) {
				topicsData.getExistingTopicsNotesList(topic.name)->elementAt(i)->topic.colorARGB = topic.colorARGB;
			}
		}
		else {
			topicsData.add(topic);
			topicsData.lastTopicNotesList()->add(note);
		}
	}
public:
	static void loadData() {
		//TODO get data from files
		addNote(Note("Header of this note1", "Some text\nmaybe some other text", 
			Topic("Short topic", System::Drawing::Color::CadetBlue.ToArgb())));
		addNote(Note("Header of this note2", "Some text, but very-veryy long. C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights.\nIn 1982, Stroustrup started to develop a successor to C with Classes.",
			Topic("Short topic", System::Drawing::Color::HotPink.ToArgb())));
		addNote(Note("3Another header, but very long. So long, that it touches the topic", "3-lines text\nfor shure\nI don't lie",
			Topic("An example of a very long topic that you can't even imagine", System::Drawing::Color::YellowGreen.ToArgb())));
		addNote(Note("4Another header, but very long. So long, that it touches even the short the topic. (Actually I am an android-developer)", "Some text\nmaybe some other text",
			Topic("Short topic", System::Drawing::Color::SandyBrown.ToArgb())));
	}
	static void saveData() {
		//TODO saving data to files
	}
	static void addNote(Note note) {
		mainData.add(note);
		setTopicToNote(mainData.elementLast(), note.topic);
	}
	static void changeNote(int index, Note newValues) {
		Note* changingNote = mainData.elementAt(index);
		if (newValues.topic.name != changingNote->topic.name) {
			for (int i = 0; i < topicsData.getSize(); i++) {
				if (topicsData.topicAt(i).name == changingNote->topic.name) {
					topicsData.getExistingTopicsNotesList(changingNote->topic.name)->remove(changingNote);
					break;
				}
			}
			changingNote->topic.name = newValues.topic.name;
		}
		changingNote->topic.colorARGB = newValues.topic.colorARGB;
		changingNote->header = newValues.header;
		changingNote->body = newValues.body;
		setTopicToNote(changingNote, changingNote->topic);
	}
	static void removeNote(int index) {
		Note* deletingNote = mainData.elementAt(index);
		if (topicsData.isTopicExists(deletingNote->topic.name)) {
			topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->remove(deletingNote);
		}
		mainData.remove(index);
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
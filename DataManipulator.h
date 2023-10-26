#pragma once
#include "CustomStructures.h"

struct DataManipulator {
private:
	static NotesList mainData;
	static TopicsList topicsData;
	static void setTopicToNote(Note& note, Topic topic) {
		if (topicsData.isTopicExists(topic.name)) {
			topicsData.getExistingTopicsNotesList(topic.name).add(&note);
			topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
			for (int i = 0; i < topicsData.getExistingTopicsNotesList(topic.name).getSize(); i++) {
				topicsData.getExistingTopicsNotesList(topic.name).elementAt(i).topic.colorARGB = topic.colorARGB;
			}
		}
		else {
			topicsData.add(topic);
			topicsData.lastTopicNotesList().add(&note);
		}
	}
public:
	static void loadData() {
		//TODO get data from files
		mainData.add(Note("Header of this note1", "Some text\nmaybe some other text", 
			Topic("Short topic", System::Drawing::Color::CadetBlue.ToArgb())));
		mainData.add(Note("Header of this note2", "Some text, but very-veryy long. C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights.\nIn 1982, Stroustrup started to develop a successor to C with Classes.",
			Topic("Short topic", System::Drawing::Color::HotPink.ToArgb())));
		mainData.add(Note("3Another header, but very long. So long, that it touches the topic", "3-lines text\nfor shure\nI don't lie", 
			Topic("An example of a very long topic that you can't even imagine", System::Drawing::Color::YellowGreen.ToArgb())));
		mainData.add(Note("4Another header, but very long. So long, that it touches even the short the topic. (Actually I am an android-developer)", "Some text\nmaybe some other text",
			Topic("Short topic", System::Drawing::Color::SandyBrown.ToArgb())));
	}
	static void saveData() {
		//TODO saving data to files
	}
	static void addNote(Note note) {
		mainData.add(note);
		if (note.topic.name != "") {
			setTopicToNote(mainData.elementLast(), note.topic);
		}
	}
	static void changeNote(int index, Note newValues) {
		mainData.elementAt(index).header = newValues.header;
		mainData.elementAt(index).body = newValues.body;
		mainData.elementAt(index).topic = newValues.topic;
	}
	static void removeNote(int index) {
		mainData.remove(index);
	}
	static NotesList getNotes() {
		return mainData;
	}
	static TopicsList getTopics() {
		return topicsData;
	}
	static int notesCount() {
		return mainData.getSize();
	}
};
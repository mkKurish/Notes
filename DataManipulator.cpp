#include "DataManipulator.h"

NotesList DataManipulator::mainData;
TopicsList DataManipulator::topicsData;

void DataManipulator::updateTopicsColor(Topic topic) {
	for (int i = 0; i < topicsData.getExistingTopicsNotesList(topic.name)->getSize(); i++) {
		topicsData.getExistingTopicsNotesList(topic.name)->elementAt(i)->topic.colorARGB = topic.colorARGB;
	}
	topicsData.getExistingTopic(topic.name).colorARGB = topic.colorARGB;
}

void DataManipulator::setTopicToNote(Note* note, Topic topic) {
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

void DataManipulator::loadData() {
	json jsonHolder;
	ifstream inputFile;
	inputFile.open("notesData.json");
	if (inputFile.is_open()) {
		if (inputFile.peek() != ifstream::traits_type::eof()) {
			inputFile >> jsonHolder;
			for (int i = 0; i < jsonHolder.size(); i++) {
				Note newNote(unconvertUTF8(jsonHolder["note" + to_string(i)]["header"]),
					unconvertUTF8(jsonHolder["note" + to_string(i)]["body"]),
					Topic(unconvertUTF8(jsonHolder["note" + to_string(i)]["topic"]["name"]),
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

void DataManipulator::saveData() {
	json jsonHolder;
	Note* n;
	for (int i = 0; i < mainData.getSize(); i++) {
		n = mainData.elementAt(i);
		jsonHolder["note" + to_string(i)] = {
			{"header", convertUTF8(n->header)},
			{"topic",
				{{"name", convertUTF8(n->topic.name)},
				{"colorARGB", n->topic.colorARGB}}
			},
			{"body", convertUTF8(n->body)},
			{"creationTime", n->creationTime}
		};
	}
	ofstream outputFile;
	outputFile.open("notesData.json");
	outputFile << jsonHolder.dump();
	outputFile.close();
}

void DataManipulator::addNote(Note note) {
	note.indexInMainList = mainData.getSize();
	mainData.add(note);
	setTopicToNote(mainData.elementLast(), note.topic);
	saveData();
}

void DataManipulator::changeNote(int index, Note newValues) {
	Note* changingNote = mainData.elementAt(index);
	if (newValues.topic.name != changingNote->topic.name) {
		if (topicsData.getExistingTopicsNotesList(changingNote->topic.name)->getSize() == 1)
			topicsData.removeByTopic(changingNote->topic);
		else
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

void DataManipulator::removeNote(int index) {
	Note* deletingNote = mainData.elementAt(index);
	topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->remove(deletingNote);
	if (topicsData.getExistingTopicsNotesList(deletingNote->topic.name)->getSize() == 0)
		topicsData.removeByTopic(deletingNote->topic);
	mainData.remove(index);
	saveData();
}

NotesList* DataManipulator::getNotes() {
	return &mainData;
}

TopicsList* DataManipulator::getTopics() {
	return &topicsData;
}

int DataManipulator::notesCount() {
	return mainData.getSize();
}
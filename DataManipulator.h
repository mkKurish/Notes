#pragma once
#include "CustomStructures.h"
#include "json.hpp"
#include <fstream>
#include "StringCoding.h"
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
	static void updateTopicsColor(Topic topic);

	/*
	Linking topic in topicsData to the note in mainData.
	*/
	static void setTopicToNote(Note* note, Topic topic);
public:
	/*
	Attempt to load saved notes data.

	If there is a file "notesData.json" and it is not empty,
	it is read and the downloaded data are installed.
	mainData and topicsData are being recovered.
	*/
	static void loadData();

	/*
	Saving notes data.

	Writing the settings values to the "notesData.json" file.
	*/
	static void saveData();

	/*
	Adding note to the mainData (list of notes) and
	linking this note to the topic in topicsData.
	*/
	static void addNote(Note note);

	/*
	Changing note and updating mainData and topicsData.
	*/
	static void changeNote(int index, Note newValues);

	/*
	Removing note from mainData and topicsData.
	*/
	static void removeNote(int index);

	/*
	Getting list of notes in order by date (mainData).
	*/
	static NotesList* getNotes();

	/*
	Getting list of topics (topicsData).
	*/
	static TopicsList* getTopics();

	/*
	Getting count of existing notes.
	*/
	static int notesCount();
};
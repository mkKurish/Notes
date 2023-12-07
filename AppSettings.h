#pragma once
#include "json.hpp"
#include <fstream>
#include <string>
#include "StringCoding.h"


using std::string;
using std::to_string;
using std::ifstream;
using std::ofstream;
using json = nlohmann::json;

struct AppSettings {
private:
	static bool safeDelete;
	static bool displayByTopics;
	static string* selectedTopics;
	static int countOfSelectedTopics;
public:
	/*
	Setting default settings.
	*/
	static void defaultSettings();

	/*
	Attempt to load saved settings.

	If there is a file "appSettings.json" and it is not empty,
	it is read and the downloaded settings are installed.
	*/
	static void loadSettings();

	/*
	Saving settings.

	Writing the settings values to the "appSettings.json" file.
	*/
	static void saveSettings();

	/*
	Changing the safe deletion setting state.
	*/
	static void changeStateSafeDelete();

	/*
	Receiving the safe deletion setting state.
	*/
	static bool isSafeDelete();

	/*
	Setting state of the display mode by themes.
	*/
	static void setDisplayTopicsMode(bool state);

	/*
	Checking if the display mode set to display by topics.
	*/
	static bool isDisplayTopicsMode();

	/*
	Getting the array of selected topics.
	*/
	static string* getSelectedTopics();

	/*
	Adding the topic to the array of selected topics. 
	*/
	static void addTopicInSelected(string topic);

	/*
	Checking if topic is selected.
	*/
	static bool isTopicSelected(string topic);

	/*
	Unselecting the topic, if it is selected.
	*/
	static void unselectTopic(string topic);

	/*
	Unselecting all selected topics.
	*/
	static void unselectAllTopics();

	/*
	Receiving the count of selected topics.
	*/
	static int getCountOfSelectedTopics();
};
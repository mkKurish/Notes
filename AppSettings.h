#pragma once
#include "json.hpp"
#include <fstream>
#include <string>


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
	static void defaultSettings() {
		safeDelete = true;
		displayByTopics = false;
		selectedTopics = nullptr;
		countOfSelectedTopics = 0;
		saveSettings();
	}

	/*
	Attempt to load saved settings.

	If there is a file "appSettings.json" and it is not empty,
	it is read and the downloaded settings are installed.
	*/
	static void loadSettings() {
		ifstream inputFile;
		inputFile.open("appSettings.json");
		if (inputFile.is_open()) {
			json jsonHolder;
			inputFile >> jsonHolder;
			safeDelete = jsonHolder["safeDelete"];
			displayByTopics = jsonHolder["displayByTopics"];
			countOfSelectedTopics = jsonHolder["countOfSelectedTopics"];
			if (countOfSelectedTopics == 0)
				selectedTopics = nullptr;
			else {
				selectedTopics = new string[countOfSelectedTopics];
				for (int i = 0; i < countOfSelectedTopics; i++)
					selectedTopics[i] = jsonHolder["selectedTopic" + to_string(i)];
			}
		}else
			defaultSettings();
		inputFile.close();
	}

	/*
	Saving settings.

	Writing the settings values to the "appSettings.json" file.
	*/
	static void saveSettings() {
		json jsonHolder;
		jsonHolder["safeDelete"] = safeDelete;
		jsonHolder["displayByTopics"] = displayByTopics;
		for (int i = 0; i < countOfSelectedTopics; i++) {
			jsonHolder["selectedTopic" + to_string(i)] = selectedTopics[i];
		}
		jsonHolder["countOfSelectedTopics"] = countOfSelectedTopics;
		ofstream outputFile;
		outputFile.open("appSettings.json");
		outputFile << jsonHolder.dump();
		outputFile.close();
	}

	/*
	Changing the safe deletion setting state.
	*/
	static void changeStateSafeDelete() { safeDelete = !safeDelete; saveSettings(); }

	/*
	Receiving the safe deletion setting state.
	*/
	static bool isSafeDelete() { return safeDelete; }

	/*
	Setting state of the display mode by themes.
	*/
	static void setDisplayTopicsMode(bool state) { displayByTopics = state; saveSettings(); }

	/*
	Checking if the display mode set to display by topics.
	*/
	static bool isDisplayTopicsMode() { return displayByTopics; }

	/*
	Getting the array of selected topics.
	*/
	static string* getSelectedTopics() { return selectedTopics; }

	/*
	Adding the topic to the array of selected topics. 
	*/
	static void addTopicInSelected(string topic) { 
		countOfSelectedTopics++;
		string* temp = selectedTopics;
		selectedTopics = new string[countOfSelectedTopics];
		int i = 0;
		for (; i < countOfSelectedTopics - 1; i++) {
			selectedTopics[i] = temp[i];
		}
		selectedTopics[i] = topic;
		saveSettings();
	}

	/*
	Checking if topic is selected.
	*/
	static bool isTopicSelected(string topic) {
		for (int i = 0; i < countOfSelectedTopics; i++) {
			if (selectedTopics[i] == topic)
				return true;
		}
		return false;
	}

	/*
	Unselecting the topic, if it is selected.
	*/
	static void unselectTopic(string topic) {
		if (!isTopicSelected(topic))
			return;
		string* temp = selectedTopics;
		countOfSelectedTopics--;
		selectedTopics = new string[countOfSelectedTopics];
		// This flag is used to check that the chosen topic has not been unselected yet.
		bool notUnselected = true;
		for (int i = 0; i <= countOfSelectedTopics; i++) {
			if (notUnselected) {
				if (temp[i] == topic)
					notUnselected = false;
				else
					selectedTopics[i] = temp[i];
			}
			else {
				selectedTopics[i - 1] = temp[i];
			}
		}
		saveSettings();
	}

	/*
	Unselecting all selected topics.
	*/
	static void unselectAllTopics() {
		selectedTopics = nullptr;
		countOfSelectedTopics = 0;
		saveSettings();
	}

	/*
	Receiving the count of selected topics.
	*/
	static int getCountOfSelectedTopics() { return countOfSelectedTopics; }
};
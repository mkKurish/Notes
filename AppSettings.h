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
	static bool displayByThemes;
	static string* selectedTopics;
	static int countOfSelectedTopics;
public:
	static void defaultSettings() {
		safeDelete = true;
		displayByThemes = false;
		selectedTopics = nullptr;
		countOfSelectedTopics = 0;
		saveSettings();
	}
	static void loadSettings() {
		ifstream inputFile;
		inputFile.open("appSettings.json");
		if (inputFile.is_open()) {
			json jsonHolder;
			inputFile >> jsonHolder;
			safeDelete = jsonHolder["safeDelete"];
			displayByThemes = jsonHolder["displayByThemes"];
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
	static void saveSettings() {
		json jsonHolder;
		jsonHolder["safeDelete"] = safeDelete;
		jsonHolder["displayByThemes"] = displayByThemes;
		for (int i = 0; i < countOfSelectedTopics; i++) {
			jsonHolder["selectedTopic" + to_string(i)] = selectedTopics[i];
		}
		jsonHolder["countOfSelectedTopics"] = countOfSelectedTopics;
		ofstream outputFile;
		outputFile.open("appSettings.json");
		outputFile << jsonHolder.dump();
		outputFile.close();
	}
	static void setSafeDelete() { safeDelete = true; saveSettings(); }
	static void setUnsafeDelete() { safeDelete = false; saveSettings(); }
	static void changeStateSafeDelete() { safeDelete = !safeDelete; saveSettings(); }
	static bool isSafeDelete() { return safeDelete; }
	static void setDisplayThemesMode(bool state) { displayByThemes = state; saveSettings(); }
	static bool getDisplayThemesMode() { return displayByThemes; }
	static string* getSelectedTopics() { return selectedTopics; }
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
	static bool topicIsSelected(string topic) {
		for (int i = 0; i < countOfSelectedTopics; i++) {
			if (selectedTopics[i] == topic)
				return true;
		}
		return false;
	}
	static void unselectTopic(string topic) {
		if (!topicIsSelected(topic))
			return;
		string* temp = selectedTopics;
		countOfSelectedTopics--;
		selectedTopics = new string[countOfSelectedTopics];
		bool flag = true;
		for (int i = 0; i <= countOfSelectedTopics; i++) {
			if (flag) {
				if (temp[i] == topic)
					flag = false;
				else
					selectedTopics[i] = temp[i];
			}
			else {
				selectedTopics[i - 1] = temp[i];
			}
		}
		saveSettings();
	}
	static void unselectAllTopics() {
		selectedTopics = nullptr;
		countOfSelectedTopics = 0;
		saveSettings();
	}
	static int getCountOfSelectedTopics() { return countOfSelectedTopics; }
};
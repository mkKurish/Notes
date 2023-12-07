#include "AppSettings.h"

bool AppSettings::safeDelete;
bool AppSettings::displayByTopics;
std::string* AppSettings::selectedTopics;
int AppSettings::countOfSelectedTopics;

void AppSettings::defaultSettings() {
	safeDelete = true;
	displayByTopics = false;
	selectedTopics = nullptr;
	countOfSelectedTopics = 0;
	saveSettings();
}

void AppSettings::loadSettings() {
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
				selectedTopics[i] = unconvertUTF8(jsonHolder["selectedTopic" + to_string(i)]);
		}
	}
	else
		defaultSettings();
	inputFile.close();
}

void AppSettings::saveSettings() {
	json jsonHolder;
	jsonHolder["safeDelete"] = safeDelete;
	jsonHolder["displayByTopics"] = displayByTopics;
	for (int i = 0; i < countOfSelectedTopics; i++) {
		jsonHolder["selectedTopic" + to_string(i)] = convertUTF8(selectedTopics[i]);
	}
	jsonHolder["countOfSelectedTopics"] = countOfSelectedTopics;
	ofstream outputFile;
	outputFile.open("appSettings.json");
	outputFile << jsonHolder.dump();
	outputFile.close();
}

void AppSettings::changeStateSafeDelete() { safeDelete = !safeDelete; saveSettings(); }

bool AppSettings::isSafeDelete() { return safeDelete; }

void AppSettings::setDisplayTopicsMode(bool state) { displayByTopics = state; saveSettings(); }

bool AppSettings::isDisplayTopicsMode() { return displayByTopics; }

string* AppSettings::getSelectedTopics() { return selectedTopics; }

void AppSettings::addTopicInSelected(string topic) {
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

bool AppSettings::isTopicSelected(string topic) {
	for (int i = 0; i < countOfSelectedTopics; i++) {
		if (selectedTopics[i] == topic)
			return true;
	}
	return false;
}

void AppSettings::unselectTopic(string topic) {
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

void AppSettings::unselectAllTopics() {
	selectedTopics = nullptr;
	countOfSelectedTopics = 0;
	saveSettings();
}

int AppSettings::getCountOfSelectedTopics() { return countOfSelectedTopics; }
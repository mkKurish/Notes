#pragma once
#include <string>

struct AppSettings {
private:
	static bool safeDelete;
	static bool displayByThemes;
	static std::string* selectedTopics;
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
		//TODO: if () ... load from file
		// else
		defaultSettings();
	}
	static void saveSettings() {
		//TODO
	}
	static void setSafeDelete() { safeDelete = true; saveSettings(); }
	static void setUnsafeDelete() { safeDelete = false; saveSettings(); }
	static void changeStateSafeDelete() { safeDelete = !safeDelete; saveSettings(); }
	static bool isSafeDelete() { return safeDelete; }
	static void setDisplayThemesMode(bool state) { displayByThemes = state; }
	static bool getDisplayThemesMode() { return displayByThemes; }
	static std::string* getSelectedTopics() { return selectedTopics; }
	static void addTopicInSelected(std::string topic) { 
		countOfSelectedTopics++;
		std::string* temp = selectedTopics;
		selectedTopics = new std::string[countOfSelectedTopics];
		int i = 0;
		for (; i < countOfSelectedTopics - 1; i++) {
			selectedTopics[i] = temp[i];
		}
		selectedTopics[i] = topic;
	}
	static bool topicIsSelected(std::string topic) {
		for (int i = 0; i < countOfSelectedTopics; i++) {
			if (selectedTopics[i] == topic)
				return true;
		}
		return false;
	}
	static void unselectTopic(std::string topic) {
		if (!topicIsSelected(topic))
			return;
		std::string* temp = selectedTopics;
		countOfSelectedTopics--;
		selectedTopics = new std::string[countOfSelectedTopics];
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
	}
	static void unselectAllTopics() {
		selectedTopics = nullptr;
		countOfSelectedTopics = 0;
	}
	static int getCountOfSelectedTopics() { return countOfSelectedTopics; }
};
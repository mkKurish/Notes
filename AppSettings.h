#pragma once

struct AppSettings {
private:
	static bool safeDelete;
	static bool displayByThemes;
public:
	static void defaultSettings() {
		safeDelete = true;
		displayByThemes = false;
		saveSettings();
	}
	static void loadSettings() {
		//TODO: if () ... load from file
		// else
		safeDelete = true;
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
};
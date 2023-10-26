#include <Windows.h>
#include "MainForm.h"
#include "AppSettings.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	DataManipulator::loadData();
	AppSettings::loadSettings();
	Notes::MainForm mf;
	Application::Run(% mf);
}
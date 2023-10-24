#include "MainForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

extern DataManipulator controller;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	controller.loadData();
	Notes::MainForm mf;
	Application::Run(% mf);
}
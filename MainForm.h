#pragma once
#include "DataManipulator.h"
#include "CreationForm.h"
#include "AppSettings.h"
#include "DeletionConfirmationForm.h"
#include "SettingsForm.h"
#include "ChangingForm.h"
#include <msclr/marshal_cppstd.h>
#include "CertificateForm.h"

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ createBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ faqBtn;

	private: System::Windows::Forms::ToolStripMenuItem^ settingsBtn;

	private: System::Windows::Forms::ToolStripMenuItem^ displayMode;

	private: System::Windows::Forms::ToolStripMenuItem^ byDate;
	private: System::Windows::Forms::ToolStripMenuItem^ byTopic;
	private: System::Windows::Forms::ListBox^ notesListBox;
	private: System::Windows::Forms::ToolStripMenuItem^ choosingTopics;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	/*
	Updating all interface objects, linked to the notes data.
	*/
	private: System::Void updateNotesDataMainForm();

	/*
	Function called when createBtn button is pressed.
	*/
	private: System::Void createBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when deleteBtn button is pressed.
	*/
	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when settingsBtn button is pressed.
	*/
	private: System::Void settingsBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when faqBtn button is pressed.
	*/
	private: System::Void faqBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when loading MainForm.
	*/
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when drawing an object of the notesListBox list.
	*/
	private: System::Void notesListBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
		   
	/*
	Function called when measuring an object of the notesListBox list.
	*/
	private: System::Void notesListBox_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e);
		   
	/*
	Function called when resizing the notesListBox.
	*/
	private: System::Void notesListBox_Resize(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when list item is pressed twice.
	*/
	private: System::Void notesListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e);

	/*
	Function called when the byDate button is pressed.
	*/
	private: System::Void byDate_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when the byTopic button is pressed.
	*/
	private: System::Void byTopic_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function is called when item in the list of topics to select is pressed
	*/
	private: System::Void choosingTopicsItem_Click(System::Object^ sender, System::EventArgs^ e);

	/*
	Clearing list of chones topics.
	*/
	private: System::Void clearChosenTopics(System::Object^ sender, System::EventArgs^ e);
	};
}

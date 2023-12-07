#pragma once
#include <msclr/marshal_cppstd.h>
#include "DataManipulator.h"
#include "UIInstruments.h"
#include "AppSettings.h"

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ChangingForm
	/// </summary>
	public ref class ChangingForm : public System::Windows::Forms::Form
	{
	public:
		int selectedIndex;
		ChangingForm(void)
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
		~ChangingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ colorpickerBtn;
	private: System::Windows::Forms::Label^ labelColor;

	private: System::Windows::Forms::RichTextBox^ bodyTextBox;
	private: System::Windows::Forms::Label^ labelBody;

	private: System::Windows::Forms::Label^ labelTopic;

	private: System::Windows::Forms::Label^ labelHeader;

	private: System::Windows::Forms::Button^ confirmationBtn;

	private: System::Windows::Forms::Button^ cancelBnt;
	private: System::Windows::Forms::TextBox^ topicTextBox;
	private: System::Windows::Forms::TextBox^ headerTextBox;
	private: System::Windows::Forms::ColorDialog^ colorDialog;

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
	Function called when loading ChangingForm.
	*/
	private: System::Void ChangingForm_Load(System::Object^ sender, System::EventArgs^ e);

	/*
	Function called when colorpickerBtn button is pressed.
	*/
	private: System::Void colorpickerBtn_Click(System::Object^ sender, System::EventArgs^ e);

	/*
	Function called when cancelBnt button is pressed.
	*/
	private: System::Void cancelBnt_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when entering the headerTextBox text field.
	*/
	private: System::Void headerTextBox_Enter(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when leaving the headerTextBox text field.
	*/
	private: System::Void headerTextBox_Leave(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when entering the topicTextBox text field.
	*/
	private: System::Void topicTextBox_Enter(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when leaving the topicTextBox text field.
	*/
	private: System::Void topicTextBox_Leave(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when entering the bodyTextBox text field.
	*/
	private: System::Void bodyTextBox_Enter(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when leaving the bodyTextBox text field.
	*/
	private: System::Void bodyTextBox_Leave(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when confirmationBtn button is pressed.
	*/
	private: System::Void confirmationBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when the text in the headerTextBox text field changes.
	*/
	private: System::Void headerTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when the text in the topicTextBox text field changes.
	*/
	private: System::Void topicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
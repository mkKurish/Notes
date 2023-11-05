#pragma once
#include <msclr/marshal_cppstd.h>
#include "DataManipulator.h"
#include "UIInstruments.h"

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� CreationForm
	/// </summary>
	public ref class CreationForm : public System::Windows::Forms::Form
	{
	public:
		CreationForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~CreationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ headerTextBox;
	private: System::Windows::Forms::TextBox^ topicTextBox;

	private: System::Windows::Forms::Button^ cancelBnt;
	private: System::Windows::Forms::Button^ createBtn;
	private: System::Windows::Forms::Label^ labelHeader;
	private: System::Windows::Forms::Label^ labelTopic;
	private: System::Windows::Forms::Label^ labelBody;

	private: System::Windows::Forms::RichTextBox^ bodyTextBox;
	private: System::Windows::Forms::Label^ labelColor;

	private: System::Windows::Forms::Button^ colorpickerBtn;

	private: System::Windows::Forms::ColorDialog^ colorDialog;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->headerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->topicTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cancelBnt = (gcnew System::Windows::Forms::Button());
			this->createBtn = (gcnew System::Windows::Forms::Button());
			this->labelHeader = (gcnew System::Windows::Forms::Label());
			this->labelTopic = (gcnew System::Windows::Forms::Label());
			this->labelBody = (gcnew System::Windows::Forms::Label());
			this->bodyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->labelColor = (gcnew System::Windows::Forms::Label());
			this->colorpickerBtn = (gcnew System::Windows::Forms::Button());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->SuspendLayout();
			// 
			// headerTextBox
			// 
			this->headerTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->headerTextBox->Location = System::Drawing::Point(40, 43);
			this->headerTextBox->Name = L"headerTextBox";
			this->headerTextBox->Size = System::Drawing::Size(600, 35);
			this->headerTextBox->TabIndex = 0;
			this->headerTextBox->TextChanged += gcnew System::EventHandler(this, &CreationForm::headerTextBox_TextChanged);
			this->headerTextBox->Enter += gcnew System::EventHandler(this, &CreationForm::headerTextBox_Enter);
			this->headerTextBox->Leave += gcnew System::EventHandler(this, &CreationForm::headerTextBox_Leave);
			// 
			// topicTextBox
			// 
			this->topicTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->topicTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->topicTextBox->Location = System::Drawing::Point(40, 121);
			this->topicTextBox->Name = L"topicTextBox";
			this->topicTextBox->Size = System::Drawing::Size(470, 35);
			this->topicTextBox->TabIndex = 1;
			this->topicTextBox->TextChanged += gcnew System::EventHandler(this, &CreationForm::topicTextBox_TextChanged);
			this->topicTextBox->Enter += gcnew System::EventHandler(this, &CreationForm::topicTextBox_Enter);
			this->topicTextBox->Leave += gcnew System::EventHandler(this, &CreationForm::topicTextBox_Leave);
			// 
			// cancelBnt
			// 
			this->cancelBnt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->cancelBnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancelBnt->Location = System::Drawing::Point(12, 575);
			this->cancelBnt->Name = L"cancelBnt";
			this->cancelBnt->Size = System::Drawing::Size(150, 57);
			this->cancelBnt->TabIndex = 3;
			this->cancelBnt->Text = L"������";
			this->cancelBnt->UseVisualStyleBackColor = true;
			this->cancelBnt->Click += gcnew System::EventHandler(this, &CreationForm::cancelBnt_Click);
			// 
			// createBtn
			// 
			this->createBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->createBtn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->createBtn->Enabled = false;
			this->createBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->createBtn->Location = System::Drawing::Point(516, 575);
			this->createBtn->Name = L"createBtn";
			this->createBtn->Size = System::Drawing::Size(150, 58);
			this->createBtn->TabIndex = 4;
			this->createBtn->Text = L"�������";
			this->createBtn->UseVisualStyleBackColor = false;
			this->createBtn->Click += gcnew System::EventHandler(this, &CreationForm::createBtn_Click);
			// 
			// labelHeader
			// 
			this->labelHeader->AutoSize = true;
			this->labelHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelHeader->ForeColor = System::Drawing::SystemColors::GrayText;
			this->labelHeader->Location = System::Drawing::Point(39, 15);
			this->labelHeader->Name = L"labelHeader";
			this->labelHeader->Size = System::Drawing::Size(108, 25);
			this->labelHeader->TabIndex = 5;
			this->labelHeader->Text = L"���������";
			// 
			// labelTopic
			// 
			this->labelTopic->AutoSize = true;
			this->labelTopic->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTopic->ForeColor = System::Drawing::SystemColors::GrayText;
			this->labelTopic->Location = System::Drawing::Point(39, 93);
			this->labelTopic->Name = L"labelTopic";
			this->labelTopic->Size = System::Drawing::Size(62, 25);
			this->labelTopic->TabIndex = 6;
			this->labelTopic->Text = L"����";
			// 
			// labelBody
			// 
			this->labelBody->AutoSize = true;
			this->labelBody->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBody->ForeColor = System::Drawing::SystemColors::GrayText;
			this->labelBody->Location = System::Drawing::Point(39, 171);
			this->labelBody->Name = L"labelBody";
			this->labelBody->Size = System::Drawing::Size(130, 25);
			this->labelBody->TabIndex = 7;
			this->labelBody->Text = L"����������";
			// 
			// bodyTextBox
			// 
			this->bodyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bodyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bodyTextBox->Location = System::Drawing::Point(44, 199);
			this->bodyTextBox->Name = L"bodyTextBox";
			this->bodyTextBox->Size = System::Drawing::Size(600, 360);
			this->bodyTextBox->TabIndex = 8;
			this->bodyTextBox->Text = L"";
			this->bodyTextBox->WordWrap = false;
			this->bodyTextBox->Enter += gcnew System::EventHandler(this, &CreationForm::bodyTextBox_Enter);
			this->bodyTextBox->Leave += gcnew System::EventHandler(this, &CreationForm::bodyTextBox_Leave);
			// 
			// labelColor
			// 
			this->labelColor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelColor->AutoSize = true;
			this->labelColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelColor->ForeColor = System::Drawing::SystemColors::GrayText;
			this->labelColor->Location = System::Drawing::Point(585, 93);
			this->labelColor->Name = L"labelColor";
			this->labelColor->Size = System::Drawing::Size(59, 25);
			this->labelColor->TabIndex = 9;
			this->labelColor->Text = L"����";
			// 
			// colorpickerBtn
			// 
			this->colorpickerBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->colorpickerBtn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->colorpickerBtn->Enabled = false;
			this->colorpickerBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->colorpickerBtn->Location = System::Drawing::Point(516, 121);
			this->colorpickerBtn->Name = L"colorpickerBtn";
			this->colorpickerBtn->Size = System::Drawing::Size(124, 40);
			this->colorpickerBtn->TabIndex = 10;
			this->colorpickerBtn->Text = L"��� �����";
			this->colorpickerBtn->UseVisualStyleBackColor = false;
			this->colorpickerBtn->Click += gcnew System::EventHandler(this, &CreationForm::colorpickerBtn_Click);
			// 
			// colorDialog
			// 
			this->colorDialog->ShowHelp = true;
			this->colorDialog->SolidColorOnly = true;
			// 
			// CreationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 644);
			this->Controls->Add(this->colorpickerBtn);
			this->Controls->Add(this->labelColor);
			this->Controls->Add(this->bodyTextBox);
			this->Controls->Add(this->labelBody);
			this->Controls->Add(this->labelTopic);
			this->Controls->Add(this->labelHeader);
			this->Controls->Add(this->createBtn);
			this->Controls->Add(this->cancelBnt);
			this->Controls->Add(this->topicTextBox);
			this->Controls->Add(this->headerTextBox);
			this->MinimumSize = System::Drawing::Size(700, 700);
			this->Name = L"CreationForm";
			this->Text = L"�������� �������";
			this->Load += gcnew System::EventHandler(this, &CreationForm::CreationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	Function called when loading CreationForm.
	*/
	private: System::Void CreationForm_Load(System::Object^ sender, System::EventArgs^ e) {
		setHintToTextBox(headerTextBox, "������� ���������", Color::Red);
		setHintToTextBox(topicTextBox, "������� ����", Color::Gray);
		setHintToTextBox(bodyTextBox, "������� ����������", Color::Gray);
	}
		   
	/*
	Function called when colorpickerBtn buton is pressed.
	*/
	private: System::Void colorpickerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog->ShowDialog();
		if (colorDialog->Color != Drawing::Color::Black) {
			colorpickerBtn->BackColor = colorDialog->Color;
		}
	}
		   
	/*
	Function called when cancelBtn button is pressed.
	*/
	private: System::Void cancelBnt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
		   
	/*
	Function called when entering the headerTextBox text field.
	*/
	private: System::Void headerTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(headerTextBox, Color::Red);
	}
		   
	/*
	Function called when leaving the headerTextBox text field.
	*/
	private: System::Void headerTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(headerTextBox->Text)) {
			createBtn->BackColor = SystemColors::ControlDark;
			createBtn->Enabled = false;
		}
		else {
			createBtn->BackColor = SystemColors::Control;
			createBtn->Enabled = true;
		}
		setHintToTextBox(headerTextBox, "������� ���������", Color::Red);
	}
		   
	/*
	Function called when entering the topicTextBox text field.
	*/
	private: System::Void topicTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(topicTextBox, Color::Gray);
	}
		   
	/*
	Function called when leaving the topicTextBox text field.
	*/
	private: System::Void topicTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(topicTextBox->Text)) {
			colorpickerBtn->BackColor = SystemColors::ControlDark;
			colorpickerBtn->Enabled = false;
			colorpickerBtn->Text = gcnew String("��� �����");
		}
		else {
			if (colorpickerBtn->BackColor == SystemColors::ControlDark)
				colorpickerBtn->BackColor = SystemColors::Control;
			colorpickerBtn->Enabled = true;
			colorpickerBtn->Text = gcnew String("");
		}
		setHintToTextBox(topicTextBox, "������� ����", Color::Gray);
	}
		   
	/*
	Function called when entering the bodyTextBox text field.
	*/
	private: System::Void bodyTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(bodyTextBox, Color::Gray);
	}
		   
	/*
	Function called when leaving the bodyTextBox text field.
	*/
	private: System::Void bodyTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		setHintToTextBox(bodyTextBox, "������� ����������", Color::Gray);
	}
		   
	/*
	Function called when createBtn button is pressed.
	*/
	private: System::Void createBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(headerTextBox->Text))
			return;
		std::string header = msclr::interop::marshal_as<std::string>(headerTextBox->Text);
		std::string body = msclr::interop::marshal_as<std::string>(bodyTextBox->Text);
		std::string topic = msclr::interop::marshal_as<std::string>(topicTextBox->Text);
		if (topicTextBox->ForeColor == Color::Gray)
			topic = "";
		if (bodyTextBox->ForeColor == Color::Gray)
			body = "";
		DataManipulator::addNote(Note(header, body, Topic(topic, colorpickerBtn->BackColor.ToArgb())));
		this->Close();
	}
		   
	/*
	Function called when the text in the headerTextBox text field changes.
	*/
	private: System::Void headerTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (headerTextBox->Focused) {
			if (String::IsNullOrWhiteSpace(headerTextBox->Text)) {
				createBtn->BackColor = SystemColors::ControlDark;
				createBtn->Enabled = false;
			}
			else {
				createBtn->BackColor = SystemColors::Control;
				createBtn->Enabled = true;
			}
		}
	}
		   
	/*
	Function called when the text in the topicTextBox text field changes.
	*/
	private: System::Void topicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (topicTextBox->Focused) {
			if (String::IsNullOrWhiteSpace(topicTextBox->Text)) {
				colorpickerBtn->BackColor = SystemColors::ControlDark;
				colorpickerBtn->Enabled = false;
				colorpickerBtn->Text = gcnew String("��� �����");
			}
			else {
				if (colorpickerBtn->BackColor == SystemColors::ControlDark)
					colorpickerBtn->BackColor = SystemColors::Control;
				colorpickerBtn->Enabled = true;
				colorpickerBtn->Text = gcnew String("");
			}
		}
	}
	};
}

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
	/// ������ ��� ChangingForm
	/// </summary>
	public ref class ChangingForm : public System::Windows::Forms::Form
	{
	public:
		int selectedIndex;
		ChangingForm(void)
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
		~ChangingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ colorpickerBtn;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ bodyTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ confirmationBtn;

	private: System::Windows::Forms::Button^ cancelBnt;
	private: System::Windows::Forms::TextBox^ topicTextBox;
	private: System::Windows::Forms::TextBox^ headerTextBox;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;

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
			this->colorpickerBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bodyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->confirmationBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBnt = (gcnew System::Windows::Forms::Button());
			this->topicTextBox = (gcnew System::Windows::Forms::TextBox());
			this->headerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->SuspendLayout();
			// 
			// colorpickerBtn
			// 
			this->colorpickerBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->colorpickerBtn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->colorpickerBtn->Enabled = false;
			this->colorpickerBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->colorpickerBtn->Location = System::Drawing::Point(516, 119);
			this->colorpickerBtn->Name = L"colorpickerBtn";
			this->colorpickerBtn->Size = System::Drawing::Size(124, 40);
			this->colorpickerBtn->TabIndex = 20;
			this->colorpickerBtn->Text = L"��� �����";
			this->colorpickerBtn->UseVisualStyleBackColor = false;
			this->colorpickerBtn->Click += gcnew System::EventHandler(this, &ChangingForm::colorpickerBtn_Click);
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label4->Location = System::Drawing::Point(585, 91);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 25);
			this->label4->TabIndex = 19;
			this->label4->Text = L"����";
			// 
			// bodyTextBox
			// 
			this->bodyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bodyTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bodyTextBox->Location = System::Drawing::Point(44, 197);
			this->bodyTextBox->Name = L"bodyTextBox";
			this->bodyTextBox->Size = System::Drawing::Size(600, 360);
			this->bodyTextBox->TabIndex = 18;
			this->bodyTextBox->Text = L"";
			this->bodyTextBox->WordWrap = false;
			this->bodyTextBox->Enter += gcnew System::EventHandler(this, &ChangingForm::bodyTextBox_Enter);
			this->bodyTextBox->Leave += gcnew System::EventHandler(this, &ChangingForm::bodyTextBox_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label3->Location = System::Drawing::Point(39, 169);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 25);
			this->label3->TabIndex = 17;
			this->label3->Text = L"����������";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label2->Location = System::Drawing::Point(39, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 25);
			this->label2->TabIndex = 16;
			this->label2->Text = L"����";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label1->Location = System::Drawing::Point(39, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 25);
			this->label1->TabIndex = 15;
			this->label1->Text = L"���������";
			// 
			// confirmationBtn
			// 
			this->confirmationBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->confirmationBtn->BackColor = System::Drawing::SystemColors::Control;
			this->confirmationBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->confirmationBtn->Location = System::Drawing::Point(516, 573);
			this->confirmationBtn->Name = L"confirmationBtn";
			this->confirmationBtn->Size = System::Drawing::Size(150, 58);
			this->confirmationBtn->TabIndex = 14;
			this->confirmationBtn->Text = L"���������";
			this->confirmationBtn->UseVisualStyleBackColor = false;
			this->confirmationBtn->Click += gcnew System::EventHandler(this, &ChangingForm::confirmationBtnBtn_Click);
			// 
			// cancelBnt
			// 
			this->cancelBnt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->cancelBnt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancelBnt->Location = System::Drawing::Point(12, 573);
			this->cancelBnt->Name = L"cancelBnt";
			this->cancelBnt->Size = System::Drawing::Size(150, 57);
			this->cancelBnt->TabIndex = 13;
			this->cancelBnt->Text = L"������";
			this->cancelBnt->UseVisualStyleBackColor = true;
			this->cancelBnt->Click += gcnew System::EventHandler(this, &ChangingForm::cancelBnt_Click);
			// 
			// topicTextBox
			// 
			this->topicTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->topicTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->topicTextBox->Location = System::Drawing::Point(40, 119);
			this->topicTextBox->Name = L"topicTextBox";
			this->topicTextBox->Size = System::Drawing::Size(470, 35);
			this->topicTextBox->TabIndex = 12;
			this->topicTextBox->Enter += gcnew System::EventHandler(this, &ChangingForm::topicTextBox_Enter);
			this->topicTextBox->Leave += gcnew System::EventHandler(this, &ChangingForm::topicTextBox_Leave);
			// 
			// headerTextBox
			// 
			this->headerTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->headerTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->headerTextBox->Location = System::Drawing::Point(40, 41);
			this->headerTextBox->Name = L"headerTextBox";
			this->headerTextBox->Size = System::Drawing::Size(600, 35);
			this->headerTextBox->TabIndex = 11;
			this->headerTextBox->Enter += gcnew System::EventHandler(this, &ChangingForm::headerTextBox_Enter);
			this->headerTextBox->Leave += gcnew System::EventHandler(this, &ChangingForm::headerTextBox_Leave);
			// 
			// colorDialog1
			// 
			this->colorDialog1->SolidColorOnly = true;
			// 
			// ChangingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 644);
			this->Controls->Add(this->colorpickerBtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->bodyTextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->confirmationBtn);
			this->Controls->Add(this->cancelBnt);
			this->Controls->Add(this->topicTextBox);
			this->Controls->Add(this->headerTextBox);
			this->MinimumSize = System::Drawing::Size(700, 700);
			this->Name = L"ChangingForm";
			this->Text = L"ChangingForm";
			this->Load += gcnew System::EventHandler(this, &ChangingForm::ChangingForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangingForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Note* currNote = DataManipulator::getNotes()->elementAt(selectedIndex);
		headerTextBox->Text = gcnew String(currNote->header.c_str());
		if (currNote->topic.name != "") {
			topicTextBox->Text = gcnew String(currNote->topic.name.c_str());
			colorpickerBtn->BackColor = Color::FromArgb(currNote->topic.colorARGB);
			colorpickerBtn->Text = gcnew String("");
		}
		bodyTextBox->Text = gcnew String(currNote->body.c_str());

		setHintToTextBox(bodyTextBox, "������� ����������", Color::Gray);

		if (! String::IsNullOrWhiteSpace(topicTextBox->Text)) {
			if (colorpickerBtn->BackColor == SystemColors::ControlDark)
				colorpickerBtn->BackColor = SystemColors::Control;
			colorpickerBtn->Enabled = true;
			colorpickerBtn->Text = gcnew String("");
		}
		setHintToTextBox(topicTextBox, "������� ����", Color::Gray);
	}
	private: System::Void colorpickerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (colorDialog1->ShowDialog() != System::Windows::Forms::DialogResult::Cancel)
		//if (colorDialog1->Color != Drawing::Color::Black) {
			colorpickerBtn->BackColor = colorDialog1->Color;
		//}
	}
	private: System::Void cancelBnt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void headerTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(headerTextBox, Color::Red);
	}
	private: System::Void headerTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(headerTextBox->Text)) {
			confirmationBtn->BackColor = SystemColors::ControlDark;
			confirmationBtn->Enabled = false;
		}
		else {
			confirmationBtn->BackColor = SystemColors::Control;
			confirmationBtn->Enabled = true;
		}
		setHintToTextBox(headerTextBox, "������� ���������", Color::Red);
	}
	private: System::Void topicTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(topicTextBox, Color::Gray);
	}
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
	private: System::Void bodyTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(bodyTextBox, Color::Gray);
	}
	private: System::Void bodyTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		setHintToTextBox(bodyTextBox, "������� ����������", Color::Gray);
	}
	private: System::Void confirmationBtnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(headerTextBox->Text))
			return;
		std::string header = msclr::interop::marshal_as<std::string>(headerTextBox->Text);
		std::string body = msclr::interop::marshal_as<std::string>(bodyTextBox->Text);
		std::string topic = msclr::interop::marshal_as<std::string>(topicTextBox->Text);
		if (topicTextBox->ForeColor == Color::Gray)
			topic = "";
		if (bodyTextBox->ForeColor == Color::Gray)
			body = "";
		DataManipulator::changeNote(selectedIndex, Note(header, body, Topic(topic, colorpickerBtn->BackColor.ToArgb())));
		this->Close();
	}
	};
}

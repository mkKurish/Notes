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
	/// Сводка для CreationForm
	/// </summary>
	public ref class CreationForm : public System::Windows::Forms::Form
	{
	public:
		CreationForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	protected:

	protected:

	private: System::Windows::Forms::Button^ cancelBnt;
	private: System::Windows::Forms::Button^ createBtn;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ bodyTextBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ colorpickerBtn;

	private: System::Windows::Forms::ColorDialog^ colorDialog1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->headerTextBox = (gcnew System::Windows::Forms::TextBox());
			this->topicTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cancelBnt = (gcnew System::Windows::Forms::Button());
			this->createBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bodyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->colorpickerBtn = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
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
			this->cancelBnt->Text = L"Отмена";
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
			this->createBtn->Text = L"Создать";
			this->createBtn->UseVisualStyleBackColor = false;
			this->createBtn->Click += gcnew System::EventHandler(this, &CreationForm::createBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label1->Location = System::Drawing::Point(39, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Заголовок";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label2->Location = System::Drawing::Point(39, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Тема";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label3->Location = System::Drawing::Point(39, 171);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Содержание";
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
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label4->Location = System::Drawing::Point(585, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 25);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Цвет";
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
			this->colorpickerBtn->Text = L"нет цвета";
			this->colorpickerBtn->UseVisualStyleBackColor = false;
			this->colorpickerBtn->Click += gcnew System::EventHandler(this, &CreationForm::colorpickerBtn_Click);
			// 
			// colorDialog1
			// 
			this->colorDialog1->ShowHelp = true;
			this->colorDialog1->SolidColorOnly = true;
			// 
			// CreationForm
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
			this->Controls->Add(this->createBtn);
			this->Controls->Add(this->cancelBnt);
			this->Controls->Add(this->topicTextBox);
			this->Controls->Add(this->headerTextBox);
			this->MinimumSize = System::Drawing::Size(700, 700);
			this->Name = L"CreationForm";
			this->Text = L"CreationForm";
			this->Load += gcnew System::EventHandler(this, &CreationForm::CreationForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void CreationForm_Load(System::Object^ sender, System::EventArgs^ e) {
		setHintToTextBox(headerTextBox, "Введите заголовок", Color::Red);
		setHintToTextBox(topicTextBox, "Введите тему", Color::Gray);
		setHintToTextBox(bodyTextBox, "Введите содержание", Color::Gray);
	}
	private: System::Void colorpickerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		colorDialog1->ShowDialog();
		if (colorDialog1->Color != Drawing::Color::Black) {
			colorpickerBtn->BackColor = colorDialog1->Color;
		}
	}
	private: System::Void cancelBnt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void headerTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(headerTextBox, Color::Red);
	}
	private: System::Void headerTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(headerTextBox->Text)) {
			createBtn->BackColor = SystemColors::ControlDark;
			createBtn->Enabled = false;
		}
		else {
			createBtn->BackColor = SystemColors::Control;
			createBtn->Enabled = true;
		}
		setHintToTextBox(headerTextBox, "Введите заголовок", Color::Red);
	}
	private: System::Void topicTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(topicTextBox, Color::Gray);
	}
	private: System::Void topicTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(topicTextBox->Text)) {
			colorpickerBtn->BackColor = SystemColors::ControlDark;
			colorpickerBtn->Enabled = false;
			colorpickerBtn->Text = gcnew String("нет цвета");
		}
		else {
			if (colorpickerBtn->BackColor == SystemColors::ControlDark)
				colorpickerBtn->BackColor = SystemColors::Control;
			colorpickerBtn->Enabled = true;
			colorpickerBtn->Text = gcnew String("");
		}
		setHintToTextBox(topicTextBox, "Введите тему", Color::Gray);
	}
	private: System::Void bodyTextBox_Enter(System::Object^ sender, System::EventArgs^ e) {
		removeHintFromTextBox(bodyTextBox, Color::Gray);
	}
	private: System::Void bodyTextBox_Leave(System::Object^ sender, System::EventArgs^ e) {
		setHintToTextBox(bodyTextBox, "Введите содержание", Color::Gray);
	}
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
	private: System::Void topicTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (topicTextBox->Focused) {
			if (String::IsNullOrWhiteSpace(topicTextBox->Text)) {
				colorpickerBtn->BackColor = SystemColors::ControlDark;
				colorpickerBtn->Enabled = false;
				colorpickerBtn->Text = gcnew String("нет цвета");
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

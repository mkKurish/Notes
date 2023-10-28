#pragma once
#include "AppSettings.h"

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
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
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBoxSafeDeletion;


	private: System::Windows::Forms::Button^ resetBtn;

	protected:


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBoxSafeDeletion = (gcnew System::Windows::Forms::CheckBox());
			this->resetBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(260, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�������� ���������";
			// 
			// checkBoxSafeDeletion
			// 
			this->checkBoxSafeDeletion->AutoSize = true;
			this->checkBoxSafeDeletion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxSafeDeletion->Location = System::Drawing::Point(25, 59);
			this->checkBoxSafeDeletion->Name = L"checkBoxSafeDeletion";
			this->checkBoxSafeDeletion->Size = System::Drawing::Size(239, 29);
			this->checkBoxSafeDeletion->TabIndex = 1;
			this->checkBoxSafeDeletion->Text = L"���������� ��������";
			this->checkBoxSafeDeletion->UseVisualStyleBackColor = true;
			this->checkBoxSafeDeletion->CheckedChanged += gcnew System::EventHandler(this, &SettingsForm::checkBoxSafeDeletion_CheckedChanged);
			// 
			// resetBtn
			// 
			this->resetBtn->BackColor = System::Drawing::Color::Red;
			this->resetBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->resetBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->resetBtn->Location = System::Drawing::Point(155, 257);
			this->resetBtn->Name = L"resetBtn";
			this->resetBtn->Size = System::Drawing::Size(166, 75);
			this->resetBtn->TabIndex = 3;
			this->resetBtn->Text = L"�������� ���������";
			this->resetBtn->UseVisualStyleBackColor = false;
			this->resetBtn->Click += gcnew System::EventHandler(this, &SettingsForm::resetBtn_Click);
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 344);
			this->Controls->Add(this->resetBtn);
			this->Controls->Add(this->checkBoxSafeDeletion);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(700, 700);
			this->MinimumSize = System::Drawing::Size(500, 400);
			this->Name = L"SettingsForm";
			this->Text = L"SettingsForm";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void redrawSettings() {
		if (AppSettings::isSafeDelete())
			checkBoxSafeDeletion->CheckState = CheckState::Checked;
	}
	private: System::Void checkBoxSafeDeletion_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (AppSettings::isSafeDelete() != checkBoxSafeDeletion->Checked)
			AppSettings::changeStateSafeDelete();
	}
	private: System::Void resetBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AppSettings::defaultSettings();
		redrawSettings();
	}
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		redrawSettings();
	}
	};
}
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

	private: System::Windows::Forms::CheckBox^ checkBoxSafeDeletion;

	private: System::Windows::Forms::Button^ resetBtn;
	private: System::Windows::Forms::Label^ labelInfo;

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
			this->checkBoxSafeDeletion = (gcnew System::Windows::Forms::CheckBox());
			this->resetBtn = (gcnew System::Windows::Forms::Button());
			this->labelInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBoxSafeDeletion
			// 
			this->checkBoxSafeDeletion->AutoSize = true;
			this->checkBoxSafeDeletion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxSafeDeletion->Location = System::Drawing::Point(93, 38);
			this->checkBoxSafeDeletion->Name = L"checkBoxSafeDeletion";
			this->checkBoxSafeDeletion->Size = System::Drawing::Size(295, 33);
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
			this->resetBtn->Location = System::Drawing::Point(93, 182);
			this->resetBtn->Name = L"resetBtn";
			this->resetBtn->Size = System::Drawing::Size(295, 50);
			this->resetBtn->TabIndex = 3;
			this->resetBtn->Text = L"�������� ���������";
			this->resetBtn->UseVisualStyleBackColor = false;
			this->resetBtn->Click += gcnew System::EventHandler(this, &SettingsForm::resetBtn_Click);
			// 
			// labelInfo
			// 
			this->labelInfo->AutoSize = true;
			this->labelInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelInfo->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->labelInfo->Location = System::Drawing::Point(88, 104);
			this->labelInfo->Name = L"labelInfo";
			this->labelInfo->Size = System::Drawing::Size(305, 75);
			this->labelInfo->TabIndex = 4;
			this->labelInfo->Text = L"������ ���������� ��������, \r\n����� ������� �� �����, \r\n����������� �� �����/����"
				L"�";
			this->labelInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(478, 244);
			this->Controls->Add(this->labelInfo);
			this->Controls->Add(this->resetBtn);
			this->Controls->Add(this->checkBoxSafeDeletion);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(500, 300);
			this->MinimumSize = System::Drawing::Size(500, 300);
			this->Name = L"SettingsForm";
			this->Text = L"���������";
			this->Load += gcnew System::EventHandler(this, &SettingsForm::SettingsForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	Updating state of interface objects linked to the settings data.
	*/
	private: System::Void redrawSettings() {
		if (AppSettings::isSafeDelete())
			checkBoxSafeDeletion->CheckState = CheckState::Checked;
	}

	/*
	Function called when checkBoxSafeDeletion checkbox changes the value.
	*/
	private: System::Void checkBoxSafeDeletion_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (AppSettings::isSafeDelete() != checkBoxSafeDeletion->Checked)
			AppSettings::changeStateSafeDelete();
	}

	/*
	Function called when the resetBtn button is pressed.
	*/
	private: System::Void resetBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AppSettings::defaultSettings();
		redrawSettings();
	}

	/*
	Function called when loading the SettingsForm.
	*/
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		redrawSettings();
	}
	};
}

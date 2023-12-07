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
		void InitializeComponent(void);
#pragma endregion
	/*
	Updating state of interface objects linked to the settings data.
	*/
	private: System::Void redrawSettings();

	/*
	Function called when checkBoxSafeDeletion checkbox changes the value.
	*/
	private: System::Void checkBoxSafeDeletion_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	/*
	Function called when the resetBtn button is pressed.
	*/
	private: System::Void resetBtn_Click(System::Object^ sender, System::EventArgs^ e);

	/*
	Function called when loading the SettingsForm.
	*/
	private: System::Void SettingsForm_Load(System::Object^ sender, System::EventArgs^ e);
	};
}

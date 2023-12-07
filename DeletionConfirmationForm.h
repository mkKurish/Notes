#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� DeletionConfirmation
	/// </summary>
	public ref class DeletionConfirmationForm : public System::Windows::Forms::Form
	{
	public:
		DeletionConfirmationForm(void)
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
		~DeletionConfirmationForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ cancelBtn;

	private: System::Windows::Forms::Button^ confirmBtn;
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
	Function called when loading DeletionConfirmationForm.
	*/
	private: System::Void DeletionConfirmationForm_Load(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when cancelBtn button is pressed.
	*/
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   
	/*
	Function called when confirmBtn button is pressed.
	*/
	private: System::Void confirmBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

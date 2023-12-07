#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� CertificateForm
	/// </summary>
	public ref class CertificateForm : public System::Windows::Forms::Form
	{
	public:
		CertificateForm(void)
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
		~CertificateForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ returnBtn;
	private: System::Windows::Forms::RichTextBox^ faqListBox;


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
	Function called when the resetBtn button is pressed.
	*/
	private: System::Void returnBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

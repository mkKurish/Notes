#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ CertificateForm
	/// </summary>
	public ref class CertificateForm : public System::Windows::Forms::Form
	{
	public:
		CertificateForm(void)
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
	Function called when the resetBtn button is pressed.
	*/
	private: System::Void returnBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}

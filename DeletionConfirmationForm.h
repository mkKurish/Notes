#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ DeletionConfirmation
	/// </summary>
	public ref class DeletionConfirmationForm : public System::Windows::Forms::Form
	{
	public:
		DeletionConfirmationForm(void)
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

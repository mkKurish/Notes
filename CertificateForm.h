#pragma once
#include <math.h>

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CertificateForm
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
		/// Освободить все используемые ресурсы.
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CertificateForm::typeid));
			this->returnBtn = (gcnew System::Windows::Forms::Button());
			this->faqListBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// returnBtn
			// 
			this->returnBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->returnBtn->AutoSize = true;
			this->returnBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->returnBtn->Location = System::Drawing::Point(12, 375);
			this->returnBtn->Name = L"returnBtn";
			this->returnBtn->Size = System::Drawing::Size(150, 57);
			this->returnBtn->TabIndex = 0;
			this->returnBtn->Text = L"Вернуться";
			this->returnBtn->UseVisualStyleBackColor = true;
			this->returnBtn->Click += gcnew System::EventHandler(this, &CertificateForm::returnBtn_Click);
			// 
			// faqListBox
			// 
			this->faqListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->faqListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->faqListBox->Location = System::Drawing::Point(13, 12);
			this->faqListBox->Name = L"faqListBox";
			this->faqListBox->ReadOnly = true;
			this->faqListBox->Size = System::Drawing::Size(453, 357);
			this->faqListBox->TabIndex = 1;
			this->faqListBox->Text = resources->GetString(L"faqListBox.Text");
			// 
			// CertificateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(478, 444);
			this->Controls->Add(this->faqListBox);
			this->Controls->Add(this->returnBtn);
			this->MinimumSize = System::Drawing::Size(500, 500);
			this->Name = L"CertificateForm";
			this->Text = L"Справка";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	Function called when the resetBtn button is pressed.
	*/
	private: System::Void returnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}

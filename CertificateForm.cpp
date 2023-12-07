#include "CertificateForm.h"

namespace Notes {
	void CertificateForm::InitializeComponent(void)
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
	System::Void CertificateForm::returnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
}
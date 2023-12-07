#include "DeletionConfirmationForm.h"

namespace Notes {
	void DeletionConfirmationForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeletionConfirmationForm::typeid));
		this->cancelBtn = (gcnew System::Windows::Forms::Button());
		this->confirmBtn = (gcnew System::Windows::Forms::Button());
		this->labelInfo = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// cancelBtn
		// 
		this->cancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->cancelBtn->Location = System::Drawing::Point(12, 175);
		this->cancelBtn->Name = L"cancelBtn";
		this->cancelBtn->Size = System::Drawing::Size(150, 57);
		this->cancelBtn->TabIndex = 1;
		this->cancelBtn->Text = L"Отмена";
		this->cancelBtn->UseVisualStyleBackColor = true;
		this->cancelBtn->Click += gcnew System::EventHandler(this, &DeletionConfirmationForm::cancelBtn_Click);
		// 
		// confirmBtn
		// 
		this->confirmBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->confirmBtn->Location = System::Drawing::Point(316, 175);
		this->confirmBtn->Name = L"confirmBtn";
		this->confirmBtn->Size = System::Drawing::Size(150, 57);
		this->confirmBtn->TabIndex = 2;
		this->confirmBtn->Text = L"Удалить";
		this->confirmBtn->UseVisualStyleBackColor = true;
		this->confirmBtn->Click += gcnew System::EventHandler(this, &DeletionConfirmationForm::confirmBtn_Click);
		// 
		// labelInfo
		// 
		this->labelInfo->AutoSize = true;
		this->labelInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->labelInfo->Location = System::Drawing::Point(85, 67);
		this->labelInfo->Name = L"labelInfo";
		this->labelInfo->Size = System::Drawing::Size(307, 58);
		this->labelInfo->TabIndex = 3;
		this->labelInfo->Text = L"Вы уверены, что\r\n хотите удалить заметку\?";
		this->labelInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// DeletionConfirmationForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(478, 244);
		this->Controls->Add(this->labelInfo);
		this->Controls->Add(this->confirmBtn);
		this->Controls->Add(this->cancelBtn);
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(500, 300);
		this->MinimumSize = System::Drawing::Size(500, 300);
		this->Name = L"DeletionConfirmationForm";
		this->Text = L"Подтверждение";
		this->Load += gcnew System::EventHandler(this, &DeletionConfirmationForm::DeletionConfirmationForm_Load);
		this->ResumeLayout(false);
		this->PerformLayout();
	}

	System::Void DeletionConfirmationForm::DeletionConfirmationForm_Load(System::Object^ sender, System::EventArgs^ e) {}

	System::Void DeletionConfirmationForm::cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = Windows::Forms::DialogResult::No;
	}

	System::Void DeletionConfirmationForm::confirmBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = Windows::Forms::DialogResult::Yes;
	}
}
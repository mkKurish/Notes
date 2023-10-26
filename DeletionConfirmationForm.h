#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DeletionConfirmation
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Label^ label1;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->confirmBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->confirmBtn->Location = System::Drawing::Point(216, 175);
			this->confirmBtn->Name = L"confirmBtn";
			this->confirmBtn->Size = System::Drawing::Size(150, 57);
			this->confirmBtn->TabIndex = 2;
			this->confirmBtn->Text = L"Удалить";
			this->confirmBtn->UseVisualStyleBackColor = true;
			this->confirmBtn->Click += gcnew System::EventHandler(this, &DeletionConfirmationForm::confirmBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(35, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(307, 58);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Вы уверены, что\r\n хотите удалить заметку\?";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DeletionConfirmationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(378, 244);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->confirmBtn);
			this->Controls->Add(this->cancelBtn);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 300);
			this->MinimumSize = System::Drawing::Size(400, 300);
			this->Name = L"DeletionConfirmationForm";
			this->Text = L"DeletionConfirmation";
			this->Load += gcnew System::EventHandler(this, &DeletionConfirmationForm::DeletionConfirmation_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DeletionConfirmation_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = Windows::Forms::DialogResult::No;
	}
private: System::Void confirmBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = Windows::Forms::DialogResult::Yes;
}
};
}

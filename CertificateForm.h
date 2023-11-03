#pragma once

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using System::Collections::Generic::List;
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
	private: System::Windows::Forms::ListBox^ faqListBox;
	protected:



	protected:

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
			this->returnBtn = (gcnew System::Windows::Forms::Button());
			this->faqListBox = (gcnew System::Windows::Forms::ListBox());
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
			this->faqListBox->FormattingEnabled = true;
			this->faqListBox->ItemHeight = 20;
			this->faqListBox->Location = System::Drawing::Point(12, 5);
			this->faqListBox->Name = L"faqListBox";
			this->faqListBox->Size = System::Drawing::Size(454, 344);
			this->faqListBox->TabIndex = 1;
			this->faqListBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &CertificateForm::faqListBox_DrawItem);
			this->faqListBox->MeasureItem += gcnew System::Windows::Forms::MeasureItemEventHandler(this, &CertificateForm::faqListBox_MeasureItem);
			this->faqListBox->Resize += gcnew System::EventHandler(this, &CertificateForm::faqListBox_Resize);
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
			this->Text = L"CertificateForm";
			this->Load += gcnew System::EventHandler(this, &CertificateForm::CertificateForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: String^ CHAPTER_TYPE = gcnew String("chapter");
	private: String^ TOPIC_TYPE = gcnew String("topic");
	private: String^ BODY_TYPE = gcnew String("body");

	private: System::Void CertificateForm_Load(System::Object^ sender, System::EventArgs^ e) {

		// String#1 - type (chapter, topic, body); String#2 - content
		List<Tuple<String^, String^>^>^ faqData = gcnew List<Tuple<String^, String^>^>();

		faqData->Add(gcnew Tuple<String^, String^>(CHAPTER_TYPE, gcnew String("Программа \"Заметки\"")));
		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Эта программа создана для того, чтобы ....\nВы сможете...")));

		faqData->Add(gcnew Tuple<String^, String^>(CHAPTER_TYPE, gcnew String("Главный экран")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(CHAPTER_TYPE, gcnew String("Экран создания заметки")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));

		faqData->Add(gcnew Tuple<String^, String^>(TOPIC_TYPE, gcnew String("Кнопка \"Добавить\"")));
		faqData->Add(gcnew Tuple<String^, String^>(BODY_TYPE, gcnew String("-делает .. способом ..\n-можно воспользоваться для ...")));


		faqListBox->DataSource = faqData;

		faqListBox->DrawMode = DrawMode::OwnerDrawVariable;
	}
	private: System::Void faqListBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected) 
			e = gcnew DrawItemEventArgs(e->Graphics, e->Font, e->Bounds,
				e->Index, e->State ^ DrawItemState::Selected, e->ForeColor, SystemColors::Window);
		Brush^ brush = Brushes::Black;
		Tuple<String^, String^>^ currentItem = (Tuple<String^, String^>^) faqListBox->Items[e->Index];
		Drawing::StringFormat^ format = gcnew Drawing::StringFormat();
		Drawing::Font^ font;
		if (currentItem->Item1 == CHAPTER_TYPE) {
			font = gcnew Drawing::Font("Microsoft Sans Serif", 16, FontStyle::Bold);
			format->Alignment = StringAlignment::Center;
		}
		else if (currentItem->Item1 == TOPIC_TYPE) {
			font = gcnew Drawing::Font("Microsoft Sans Serif", 13, FontStyle::Bold);
		}
		else {
			font = gcnew Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular);
		}
		Drawing::SizeF^ size = e->Graphics->MeasureString(currentItem->Item2, font);
		Drawing::RectangleF^ rect = gcnew Drawing::RectangleF(e->Bounds.Left, e->Bounds.Top, faqListBox->Width-15, size->Height);
		e->DrawBackground();
		e->Graphics->DrawString(currentItem->Item2, font, brush, *rect, format);
	}
	private: System::Void faqListBox_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e) {
		if (faqListBox->Items->Count <= 0)
			return;
		Tuple<String^, String^>^ currentItem = dynamic_cast<Tuple<String^, String^>^>(faqListBox->Items[e->Index]);
		Drawing::Font^ font;
		if (currentItem->Item1 == CHAPTER_TYPE) 
			font = gcnew Drawing::Font("Microsoft Sans Serif", 16, FontStyle::Bold);
		else if (currentItem->Item1 == TOPIC_TYPE) 
			font = gcnew Drawing::Font("Microsoft Sans Serif", 13, FontStyle::Bold);
		else 
			font = gcnew Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular);
		Drawing::SizeF^ size = e->Graphics->MeasureString(currentItem->Item2, font);
		e->ItemHeight = size->Height;
	}
private: System::Void faqListBox_Resize(System::Object^ sender, System::EventArgs^ e) {
	faqListBox->Invalidate();
}
private: System::Void returnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}

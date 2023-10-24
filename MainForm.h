#pragma once
#include <string>
#include "DataManipulator.h"

DataManipulator controller;

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ createBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ faqBtn;
	protected:





	private: System::Windows::Forms::ToolStripMenuItem^ settingsBtn;

	private: System::Windows::Forms::ToolStripMenuItem^ displayMode;
	private: System::Windows::Forms::ToolStripMenuItem^ choosingTopics;



	private: System::Windows::Forms::ToolStripMenuItem^ byDate;
	private: System::Windows::Forms::ToolStripMenuItem^ byTheme;
	private: System::Windows::Forms::ListBox^ notesListBox;




	protected:

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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->displayMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byDate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byTheme = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->choosingTopics = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->faqBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->notesListBox = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->displayMode, this->choosingTopics,
					this->createBtn, this->deleteBtn, this->faqBtn, this->settingsBtn
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1078, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// displayMode
			// 
			this->displayMode->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->byDate,
					this->byTheme
			});
			this->displayMode->Name = L"displayMode";
			this->displayMode->Size = System::Drawing::Size(141, 29);
			this->displayMode->Text = L"�����������";
			// 
			// byDate
			// 
			this->byDate->Name = L"byDate";
			this->byDate->Size = System::Drawing::Size(194, 34);
			this->byDate->Text = L"�� �����";
			// 
			// byTheme
			// 
			this->byTheme->Name = L"byTheme";
			this->byTheme->Size = System::Drawing::Size(194, 34);
			this->byTheme->Text = L"�� �����";
			// 
			// choosingTopics
			// 
			this->choosingTopics->Name = L"choosingTopics";
			this->choosingTopics->Size = System::Drawing::Size(117, 29);
			this->choosingTopics->Text = L"����� ���";
			// 
			// createBtn
			// 
			this->createBtn->Name = L"createBtn";
			this->createBtn->Size = System::Drawing::Size(93, 29);
			this->createBtn->Text = L"�������";
			this->createBtn->Click += gcnew System::EventHandler(this, &MainForm::createBtn_Click);
			// 
			// deleteBtn
			// 
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(92, 29);
			this->deleteBtn->Text = L"�������";
			this->deleteBtn->Click += gcnew System::EventHandler(this, &MainForm::deleteBtn_Click);
			// 
			// faqBtn
			// 
			this->faqBtn->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->faqBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"faqBtn.Image")));
			this->faqBtn->Name = L"faqBtn";
			this->faqBtn->Size = System::Drawing::Size(40, 29);
			this->faqBtn->Click += gcnew System::EventHandler(this, &MainForm::faqBtn_Click);
			// 
			// settingsBtn
			// 
			this->settingsBtn->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->settingsBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsBtn.Image")));
			this->settingsBtn->Name = L"settingsBtn";
			this->settingsBtn->Size = System::Drawing::Size(40, 29);
			this->settingsBtn->Click += gcnew System::EventHandler(this, &MainForm::settingsBtn_Click);
			// 
			// notesListBox
			// 
			this->notesListBox->BackColor = System::Drawing::SystemColors::Window;
			this->notesListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->notesListBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->notesListBox->FormattingEnabled = true;
			this->notesListBox->ItemHeight = 20;
			this->notesListBox->Location = System::Drawing::Point(0, 33);
			this->notesListBox->Name = L"notesListBox";
			this->notesListBox->Size = System::Drawing::Size(1078, 611);
			this->notesListBox->TabIndex = 1;
			this->notesListBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::notesListBox_DrawItem);
			this->notesListBox->Resize += gcnew System::EventHandler(this, &MainForm::notesListBox_Resize);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 644);
			this->Controls->Add(this->notesListBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(1100, 700);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO
	}
	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO
	}
	private: System::Void settingsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO
	}
	private: System::Void faqBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//TODO
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		notesListBox->DrawMode = DrawMode::OwnerDrawVariable;
		notesListBox->ItemHeight = 60;

		List<Tuple<String^, String^, String^, Color>^>^ dataSet = gcnew List<Tuple<String^, String^, String^, Color>^>();
		NotesList notes = controller.getNotes();
		for (int i = 0; i < notes.getSize(); i++) {
			Color currTopicColor = Color::FromArgb(notes.elementAt(i).topic.colorARGB);
			dataSet->Add(gcnew Tuple<String^, String^, String^, Color>(gcnew String(notes.elementAt(i).header.c_str()),
				gcnew String(notes.elementAt(i).body.c_str()),
				gcnew String(notes.elementAt(i).topic.name.c_str()), currTopicColor));
		}

		notesListBox->DataSource = dataSet;
	}

	private: System::Void notesListBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
		Tuple<String^, String^, String^, Color>^ dataItem = (Tuple<String^, String^, String^, Color>^)notesListBox->Items[e->Index];

		Brush^ brush;
		Brush^ solidBrush = gcnew SolidBrush(dataItem->Item4);

		if ((e->State & DrawItemState::Selected) == DrawItemState::Selected) {
			e = gcnew DrawItemEventArgs(e->Graphics, e->Font, e->Bounds,
				e->Index, e->State ^ DrawItemState::Selected, e->ForeColor, SystemColors::ControlLight);
			brush = Brushes::Black;
		}
		else {
			brush = Brushes::Black;
		}

		Drawing::Font^ headerFont = gcnew Drawing::Font("Microsoft Sans Serif", 11, FontStyle::Bold);
		Drawing::Font^ bodyFont = gcnew Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Regular);
		Drawing::Font^ topicFont = gcnew Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Bold);

		Drawing::SizeF^ headerSize = gcnew Drawing::SizeF();
		Drawing::SizeF^ bodySize = gcnew Drawing::SizeF();
		Drawing::SizeF^ topicSize = gcnew Drawing::SizeF();
		String^ simpleOneLine = gcnew String("a");
		headerSize = e->Graphics->MeasureString(simpleOneLine, headerFont);
		bodySize = e->Graphics->MeasureString(simpleOneLine, bodyFont);
		topicSize = e->Graphics->MeasureString(dataItem->Item3, topicFont);

		Drawing::Rectangle^ bodyRect = gcnew Drawing::Rectangle(e->Bounds.Left + 10, e->Bounds.Top + 8 + headerSize->Height, notesListBox->Width - 20, bodySize->Height * 2);
		Drawing::Rectangle^ topicRect;
		if (topicSize->Width > 280)
			topicRect = gcnew Drawing::Rectangle(e->Bounds.Right - 10 - 280, e->Bounds.Top + 4, 280 + 2, topicSize->Height + 2);
		else {
			topicRect = gcnew Drawing::Rectangle(e->Bounds.Right - 10 - topicSize->Width, e->Bounds.Top + 4, topicSize->Width + 2, topicSize->Height + 2);
		}
		Drawing::Rectangle^ headerRect = gcnew Drawing::Rectangle(e->Bounds.Left + 10, e->Bounds.Top + 4, notesListBox->Width - 40 - topicRect->Width, headerSize->Height);


		Drawing::StringFormat^ topicFormat = gcnew Drawing::StringFormat();
		topicFormat->Alignment = StringAlignment::Center;
		topicFormat->LineAlignment = StringAlignment::Center;
		topicFormat->Trimming = StringTrimming::EllipsisCharacter;
		topicFormat->FormatFlags = StringFormatFlags::LineLimit;

		Drawing::StringFormat^ headerFormat = gcnew Drawing::StringFormat();
		headerFormat->Trimming = StringTrimming::EllipsisCharacter;

		Drawing::StringFormat^ bodyFormat = gcnew Drawing::StringFormat();
		bodyFormat->FormatFlags = StringFormatFlags::LineLimit;
		bodyFormat->Trimming = StringTrimming::EllipsisWord;

		Point^ leftTop = gcnew Point(e->Bounds.Left, e->Bounds.Top);
		Point^ rightTop = gcnew Point(e->Bounds.Right, e->Bounds.Top);
		Point^ leftBottom = gcnew Point(e->Bounds.Left, e->Bounds.Bottom);
		Point^ rightBottom = gcnew Point(e->Bounds.Right, e->Bounds.Bottom);
		Pen^ simpleLine = gcnew Pen(Color().Black, 1);
		Pen^ fatLine = gcnew Pen(Color().Black, 6);

		e->DrawBackground();

		if ((e->State & DrawItemState::Focus) == DrawItemState::Focus) {
			e->Graphics->DrawLine(fatLine, *leftBottom, *leftTop);
			e->Graphics->DrawLine(fatLine, *rightBottom, *rightTop);
		}
		e->Graphics->DrawLine(simpleLine, *leftBottom, *rightBottom);
		e->Graphics->DrawLine(simpleLine, *leftTop, *rightTop);


		e->Graphics->FillRectangle(solidBrush, *topicRect);

		e->Graphics->DrawString(dataItem->Item1, headerFont, brush, *headerRect, headerFormat);
		e->Graphics->DrawString(dataItem->Item2, bodyFont, brush, *bodyRect, bodyFormat);
		e->Graphics->DrawString(dataItem->Item3, topicFont, brush, *topicRect, topicFormat);
	}
	private: System::Void notesListBox_Resize(System::Object^ sender, System::EventArgs^ e) {
		notesListBox->Invalidate();
	}
	};
}

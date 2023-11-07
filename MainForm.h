#pragma once
#include "DataManipulator.h"
#include "CreationForm.h"
#include "AppSettings.h"
#include "DeletionConfirmationForm.h"
#include "SettingsForm.h"
#include "ChangingForm.h"
#include <msclr/marshal_cppstd.h>
#include "CertificateForm.h"

namespace Notes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ createBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteBtn;
	private: System::Windows::Forms::ToolStripMenuItem^ faqBtn;

	private: System::Windows::Forms::ToolStripMenuItem^ settingsBtn;

	private: System::Windows::Forms::ToolStripMenuItem^ displayMode;

	private: System::Windows::Forms::ToolStripMenuItem^ byDate;
	private: System::Windows::Forms::ToolStripMenuItem^ byTopic;
	private: System::Windows::Forms::ListBox^ notesListBox;
	private: System::Windows::Forms::ToolStripMenuItem^ choosingTopics;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->displayMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byDate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byTopic = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->choosingTopics = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->faqBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsBtn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->notesListBox = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->displayMode, this->choosingTopics,
					this->createBtn, this->deleteBtn, this->faqBtn, this->settingsBtn
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(1078, 36);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// displayMode
			// 
			this->displayMode->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->byDate,
					this->byTopic
			});
			this->displayMode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->displayMode->Name = L"displayMode";
			this->displayMode->Size = System::Drawing::Size(156, 32);
			this->displayMode->Text = L"Отображение";
			// 
			// byDate
			// 
			this->byDate->Name = L"byDate";
			this->byDate->ShowShortcutKeys = false;
			this->byDate->Size = System::Drawing::Size(189, 36);
			this->byDate->Text = L"По датам";
			this->byDate->Click += gcnew System::EventHandler(this, &MainForm::byDate_Click);
			// 
			// byTopic
			// 
			this->byTopic->Name = L"byTopic";
			this->byTopic->ShowShortcutKeys = false;
			this->byTopic->Size = System::Drawing::Size(189, 36);
			this->byTopic->Text = L"По темам";
			this->byTopic->Click += gcnew System::EventHandler(this, &MainForm::byTopic_Click);
			// 
			// choosingTopics
			// 
			this->choosingTopics->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->choosingTopics->Name = L"choosingTopics";
			this->choosingTopics->Size = System::Drawing::Size(126, 32);
			this->choosingTopics->Text = L"Выбор тем";
			// 
			// createBtn
			// 
			this->createBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->createBtn->Name = L"createBtn";
			this->createBtn->Size = System::Drawing::Size(100, 32);
			this->createBtn->Text = L"Создать";
			this->createBtn->Click += gcnew System::EventHandler(this, &MainForm::createBtn_Click);
			// 
			// deleteBtn
			// 
			this->deleteBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(101, 32);
			this->deleteBtn->Text = L"Удалить";
			this->deleteBtn->Click += gcnew System::EventHandler(this, &MainForm::deleteBtn_Click);
			// 
			// faqBtn
			// 
			this->faqBtn->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->faqBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"faqBtn.Image")));
			this->faqBtn->Name = L"faqBtn";
			this->faqBtn->Size = System::Drawing::Size(40, 32);
			this->faqBtn->Click += gcnew System::EventHandler(this, &MainForm::faqBtn_Click);
			// 
			// settingsBtn
			// 
			this->settingsBtn->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->settingsBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsBtn.Image")));
			this->settingsBtn->Name = L"settingsBtn";
			this->settingsBtn->Size = System::Drawing::Size(40, 32);
			this->settingsBtn->Click += gcnew System::EventHandler(this, &MainForm::settingsBtn_Click);
			// 
			// notesListBox
			// 
			this->notesListBox->BackColor = System::Drawing::SystemColors::Window;
			this->notesListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->notesListBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->notesListBox->FormattingEnabled = true;
			this->notesListBox->IntegralHeight = false;
			this->notesListBox->ItemHeight = 20;
			this->notesListBox->Location = System::Drawing::Point(0, 36);
			this->notesListBox->Name = L"notesListBox";
			this->notesListBox->Size = System::Drawing::Size(1078, 608);
			this->notesListBox->TabIndex = 1;
			this->notesListBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::notesListBox_DrawItem);
			this->notesListBox->MeasureItem += gcnew System::Windows::Forms::MeasureItemEventHandler(this, &MainForm::notesListBox_MeasureItem);
			this->notesListBox->DoubleClick += gcnew System::EventHandler(this, &MainForm::notesListBox_DoubleClick);
			this->notesListBox->Resize += gcnew System::EventHandler(this, &MainForm::notesListBox_Resize);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 644);
			this->Controls->Add(this->notesListBox);
			this->Controls->Add(this->menuStrip);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(1100, 700);
			this->Name = L"MainForm";
			this->Text = L"Заметки";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
	Updating all interface objects, linked to the notes data.
	*/
	private: System::Void updateNotesDataMainForm() {
		choosingTopics->DropDownItems->Clear();
		choosingTopics->DropDownItems->Add(gcnew Windows::Forms::ToolStripMenuItem(gcnew String("Очистить выбор")));
		choosingTopics->DropDownItems[0]->Click += gcnew System::EventHandler(this, &MainForm::clearChosenTopics);
		TopicsList* topicsForMenu = DataManipulator::getTopics();
		for (int i = topicsForMenu->getSize() - 1; i >= 0; i--) {
			int realIndex = topicsForMenu->getSize() - i;
			std::string topicName = topicsForMenu->topicAt(i).name;
			Drawing::Image^ colorImg = gcnew Drawing::Bitmap(3, 3);
			Graphics^ imgGraphics = Graphics::FromImage(colorImg);
			imgGraphics->FillRectangle(gcnew SolidBrush(Color::FromArgb(topicsForMenu->topicAt(i).colorARGB)), 0, 0, 3, 3);
			if (topicName != "")
				choosingTopics->DropDownItems->Add(gcnew Windows::Forms::ToolStripMenuItem(gcnew String(topicName.c_str()), colorImg));
			else {
				imgGraphics->FillRectangle(gcnew SolidBrush(Color::Black), 0, 0, 3, 3);
				choosingTopics->DropDownItems->Add(gcnew Windows::Forms::ToolStripMenuItem(gcnew String("-без темы-"), colorImg));
			}
			choosingTopics->DropDownItems[realIndex]->Click += gcnew System::EventHandler(this, &MainForm::choosingTopicsItem_Click);
			((ToolStripMenuItem^)choosingTopics->DropDownItems[realIndex])->Checked = AppSettings::isTopicSelected(topicName);
		}
		// Tuple of next values: header, body, topic name, topic color, time, index in mainList
		List<Tuple<String^, String^, String^, Color, String^, int>^>^ dataSet = gcnew List<Tuple<String^, String^, String^, Color, String^, int>^>();
		if (AppSettings::isDisplayTopicsMode()) {
			TopicsList* topics = DataManipulator::getTopics();
			for (int i = topics->getSize() - 1; i >= 0; i--) {
				NotesPointersList* notes = topics->topicNotesListAt(i);
				for (int j = 0; j < notes->getSize(); j++) {
					Note* curNote = notes->elementAt(j);
					if (AppSettings::isTopicSelected(curNote->topic.name) ||
						AppSettings::getCountOfSelectedTopics() == 0) {
						dataSet->Add(gcnew Tuple<String^, String^, String^, Color, String^, int>(
							gcnew String(curNote->header.c_str()),
							gcnew String(curNote->body.c_str()),
							gcnew String(curNote->topic.name.c_str()),
							Color::FromArgb(curNote->topic.colorARGB),
							gcnew String(curNote->getTime()),
							curNote->indexInMainList));
					}
				}
			}
		}
		else {
			NotesList* notes = DataManipulator::getNotes();
			for (int i = notes->getSize() - 1; i >= 0; i--) {
				Note* curNote = notes->elementAt(i);
				if (AppSettings::isTopicSelected(curNote->topic.name) ||
					AppSettings::getCountOfSelectedTopics() == 0) {
					dataSet->Add(gcnew Tuple<String^, String^, String^, Color, String^, int>(
						gcnew String(curNote->header.c_str()),
						gcnew String(curNote->body.c_str()),
						gcnew String(curNote->topic.name.c_str()),
						Color::FromArgb(curNote->topic.colorARGB),
						gcnew String(curNote->getTime()),
						curNote->indexInMainList));
				}
			}
		}
		int lastSelectedIndex = notesListBox->SelectedIndex;
		notesListBox->DataSource = dataSet;
		if (lastSelectedIndex != -1) {
			if (lastSelectedIndex >= notesListBox->Items->Count)
				lastSelectedIndex = notesListBox->Items->Count - 1;
			notesListBox->SelectedIndex = lastSelectedIndex;
		}
	}

	/*
	Function called when createBtn button is pressed.
	*/
	private: System::Void createBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		CreationForm cform;
		cform.ShowDialog();
		updateNotesDataMainForm();
	}
		   
	/*
	Function called when deleteBtn button is pressed.
	*/
	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int ind = notesListBox->SelectedIndex;
		if (ind == -1)
			return;
		if (AppSettings::isSafeDelete()) {
			DeletionConfirmationForm dform;
			if (dform.ShowDialog() != System::Windows::Forms::DialogResult::Yes) {
				return;
			}
		}
		// Tuple of next values: header, body, topic name, topic color, time, index in mainList
		ind = ((Tuple<String^, String^, String^, Color, String^, int>^)notesListBox->Items[notesListBox->SelectedIndex])->Item6;
		if (DataManipulator::getTopics()->getExistingTopicsNotesList(DataManipulator::getNotes()->elementAt(ind)->topic.name)->getSize() == 1)
			AppSettings::unselectTopic(DataManipulator::getNotes()->elementAt(ind)->topic.name);
		DataManipulator::removeNote(ind);
		updateNotesDataMainForm();
	}
		   
	/*
	Function called when settingsBtn button is pressed.
	*/
	private: System::Void settingsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		SettingsForm sform;
		sform.ShowDialog();
		updateNotesDataMainForm();
		if (AppSettings::isDisplayTopicsMode()) {
			this->byTopic->Checked = true;
			this->byTopic->CheckState = System::Windows::Forms::CheckState::Checked;
			this->byDate->Checked = false;
			this->byDate->CheckState = System::Windows::Forms::CheckState::Unchecked;
		}
		else {
			this->byTopic->Checked = false;
			this->byTopic->CheckState = System::Windows::Forms::CheckState::Unchecked;
			this->byDate->Checked = true;
			this->byDate->CheckState = System::Windows::Forms::CheckState::Checked;
		}
	}
		   
	/*
	Function called when faqBtn button is pressed.
	*/
	private: System::Void faqBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		CertificateForm cfform;
		cfform.ShowDialog();
	}
		   
	/*
	Function called when loading MainForm.
	*/
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (AppSettings::isDisplayTopicsMode()) {
			this->byTopic->Checked = true;
			this->byTopic->CheckState = System::Windows::Forms::CheckState::Checked;
			this->byDate->Checked = false;
			this->byDate->CheckState = System::Windows::Forms::CheckState::Unchecked;
		}
		else {
			this->byTopic->Checked = false;
			this->byTopic->CheckState = System::Windows::Forms::CheckState::Unchecked;
			this->byDate->Checked = true;
			this->byDate->CheckState = System::Windows::Forms::CheckState::Checked;
		}
		updateNotesDataMainForm();
	}
		   
	/*
	Function called when drawing an object of the notesListBox list.
	*/
	private: System::Void notesListBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
		if (e->Index == -1)
			return;
		// Tuple of next values: header, body, topic name, topic color, time, index in mainList
		Tuple<String^, String^, String^, Color, String^, int>^ dataItem = (Tuple<String^, String^, String^, Color, String^, int>^)notesListBox->Items[e->Index];

		Color topicColor = dataItem->Item4;

		Brush^ brush;
		Brush^ solidBrush = gcnew SolidBrush(topicColor);

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
		Drawing::Font^ timeFont = gcnew Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Regular);

		Drawing::SizeF^ headerSize = gcnew Drawing::SizeF();
		Drawing::SizeF^ bodySize = gcnew Drawing::SizeF();
		Drawing::SizeF^ topicSize = gcnew Drawing::SizeF();
		Drawing::SizeF^ timeSize = gcnew Drawing::SizeF();
		String^ simpleOneLine = gcnew String("a");
		headerSize = e->Graphics->MeasureString(simpleOneLine, headerFont);
		bodySize = e->Graphics->MeasureString(simpleOneLine, bodyFont);
		topicSize = e->Graphics->MeasureString(dataItem->Item3, topicFont);
		timeSize = e->Graphics->MeasureString(dataItem->Item5, timeFont);

		Drawing::RectangleF^ topicRect;
		Drawing::RectangleF^ timeRect = gcnew Drawing::RectangleF(e->Bounds.Right - timeSize->Width, e->Bounds.Top + 8 + headerSize->Height, timeSize->Width + 2, timeSize->Height);
		Drawing::RectangleF^ bodyRect = gcnew Drawing::RectangleF(e->Bounds.Left + 10, e->Bounds.Top + 8 + headerSize->Height, notesListBox->Width - 15 - timeSize->Width, bodySize->Height * 2);
		if (topicSize->Width > 280)
			topicRect = gcnew Drawing::RectangleF(e->Bounds.Right - 10 - 280, e->Bounds.Top + 4, 280 + 2, topicSize->Height + 2);
		else if (topicSize->Width < 100) {
			topicRect = gcnew Drawing::RectangleF(e->Bounds.Right - 10 - 100, e->Bounds.Top + 4, 100 + 2, topicSize->Height + 2);
		}
		else {
			topicRect = gcnew Drawing::RectangleF(e->Bounds.Right - 10 - topicSize->Width, e->Bounds.Top + 4, topicSize->Width + 2, topicSize->Height + 2);
		}
		Drawing::RectangleF^ headerRect = gcnew Drawing::RectangleF(e->Bounds.Left + 10, e->Bounds.Top + 4, notesListBox->Width - 40 - topicRect->Width, headerSize->Height);

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

		e->Graphics->DrawString(dataItem->Item1, headerFont, brush, *headerRect, headerFormat);
		e->Graphics->DrawString(dataItem->Item2, bodyFont, brush, *bodyRect, bodyFormat);
		e->Graphics->DrawString(dataItem->Item5, timeFont, brush, *timeRect);

		if (!String::IsNullOrWhiteSpace(dataItem->Item3)) {
			e->Graphics->FillRectangle(solidBrush, *topicRect);
			if (topicColor.GetBrightness() < 0.4)
				e->Graphics->DrawString(dataItem->Item3, topicFont, Brushes::White, *topicRect, topicFormat);
			else
				e->Graphics->DrawString(dataItem->Item3, topicFont, Brushes::Black, *topicRect, topicFormat);
		}
	}
		   
	/*
	Function called when measuring an object of the notesListBox list.
	*/
	private: System::Void notesListBox_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e) {
		Drawing::Font^ headerFont = gcnew Drawing::Font("Microsoft Sans Serif", 11, FontStyle::Bold);
		Drawing::Font^ bodyFont = gcnew Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Regular);
		Drawing::SizeF^ headerSize = gcnew Drawing::SizeF();
		Drawing::SizeF^ bodySize = gcnew Drawing::SizeF();
		String^ simpleOneLine = gcnew String("a");
		headerSize = e->Graphics->MeasureString(simpleOneLine, headerFont);
		bodySize = e->Graphics->MeasureString(simpleOneLine, bodyFont);
		e->ItemHeight = 4 + headerSize->Height + 4 + bodySize->Height * 2 + 4;
	}
		   
	/*
	Function called when resizing the notesListBox.
	*/
	private: System::Void notesListBox_Resize(System::Object^ sender, System::EventArgs^ e) {
		notesListBox->Invalidate();
	}
		   
	/*
	Function called when list item is pressed twice.
	*/
	private: System::Void notesListBox_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		if (notesListBox->SelectedIndex == -1)
			return;
		ChangingForm chform;
		// Tuple of next values: header, body, topic name, topic color, time, index in mainList
		chform.selectedIndex = ((Tuple<String^, String^, String^, Color, String^, int>^)notesListBox->Items[notesListBox->SelectedIndex])->Item6;
		chform.ShowDialog();
		updateNotesDataMainForm();
	}

	/*
	Function called when the byDate button is pressed.
	*/
	private: System::Void byDate_Click(System::Object^ sender, System::EventArgs^ e) {
		AppSettings::setDisplayTopicsMode(false);
		updateNotesDataMainForm();
		byDate->Checked = true;
		byTopic->Checked = false;
	}
		   
	/*
	Function called when the byTopic button is pressed.
	*/
	private: System::Void byTopic_Click(System::Object^ sender, System::EventArgs^ e) {
		AppSettings::setDisplayTopicsMode(true);
		updateNotesDataMainForm();
		byDate->Checked = false;
		byTopic->Checked = true;
	}
		   
	/*
	Function is called when item in the list of topics to select is pressed
	*/
	private: System::Void choosingTopicsItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ToolStripMenuItem^ realSender = (ToolStripMenuItem^)sender;
		std::string topic = msclr::interop::marshal_as<std::string>(realSender->Text);
		if (topic == "-без темы-" && Bitmap(realSender->Image).GetPixel(0, 0).ToArgb() == Color::Black.ToArgb())
			topic = "";
		if (AppSettings::isTopicSelected(topic)) {
			AppSettings::unselectTopic(topic);
			realSender->Checked = false;
		}
		else {
			AppSettings::addTopicInSelected(topic);
			realSender->Checked = true;
		}
		updateNotesDataMainForm();
	}

	/*
	Clearing list of chones topics.
	*/
	private: System::Void clearChosenTopics(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < choosingTopics->DropDownItems->Count; i++) {
			((ToolStripMenuItem^)choosingTopics->DropDownItems[i])->Checked = false;
		}
		AppSettings::unselectAllTopics();
		updateNotesDataMainForm();
	}
	};
}

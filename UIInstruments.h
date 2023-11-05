#pragma once

using System::Drawing::Color;
using System::Void;
using System::Windows::Forms::TextBox;
using System::Windows::Forms::RichTextBox;
using System::String;

/*
Setting hint to the textbox if textbox is empty.
*/
static System::Void setHintToTextBox(TextBox^ tb, char* hint, Color fc) {
	if (String::IsNullOrWhiteSpace(tb->Text)) {
		tb->Text = gcnew String(hint);
		tb->ForeColor = fc;
	}
}

/*
Removing hint to the textbox if textbox has hint.
*/
static System::Void removeHintFromTextBox(TextBox^ tb, Color colorOfHint) {
	if (tb->ForeColor == colorOfHint) {
		tb->ForeColor = Color::Black;
		tb->Text = gcnew String("");
	}
}

/*
Setting hint to the richTextBox if textbox is empty.
*/
static System::Void setHintToTextBox(RichTextBox^ tb, char* hint, Color fc) {
	if (String::IsNullOrWhiteSpace(tb->Text)) {
		tb->Text = gcnew String(hint);
		tb->ForeColor = fc;
	}
}

/*
Removing hint to the richTextBox if textbox has hint.
*/
static System::Void removeHintFromTextBox(RichTextBox^ tb, Color colorOfHint) {
	if (tb->ForeColor == colorOfHint) {
		tb->ForeColor = Color::Black;
		tb->Text = gcnew String("");
	}
}
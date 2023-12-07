#include "UIInstruments.h"

System::Void setHintToTextBox(TextBox^ tb, char* hint, Color fc) {
	if (String::IsNullOrWhiteSpace(tb->Text)) {
		tb->Text = gcnew String(hint);
		tb->ForeColor = fc;
	}
}

System::Void removeHintFromTextBox(TextBox^ tb, Color colorOfHint) {
	if (tb->ForeColor == colorOfHint) {
		tb->ForeColor = Color::Black;
		tb->Text = gcnew String("");
	}
}

System::Void setHintToTextBox(RichTextBox ^ tb, char* hint, Color fc) {
	if (String::IsNullOrWhiteSpace(tb->Text)) {
		tb->Text = gcnew String(hint);
		tb->ForeColor = fc;
	}
}

System::Void removeHintFromTextBox(RichTextBox ^ tb, Color colorOfHint) {
	if (tb->ForeColor == colorOfHint) {
		tb->ForeColor = Color::Black;
		tb->Text = gcnew String("");
	}
}
#pragma once

using System::Drawing::Color;
using System::Void;
using System::Windows::Forms::TextBox;
using System::Windows::Forms::RichTextBox;
using System::String;

/*
Setting hint to the textbox if textbox is empty.
*/
System::Void setHintToTextBox(TextBox^ tb, char* hint, Color fc);

/*
Removing hint to the textbox if textbox has hint.
*/
System::Void removeHintFromTextBox(TextBox^ tb, Color colorOfHint);

/*
Setting hint to the richTextBox if textbox is empty.
*/
System::Void setHintToTextBox(RichTextBox^ tb, char* hint, Color fc);

/*
Removing hint to the richTextBox if textbox has hint.
*/
System::Void removeHintFromTextBox(RichTextBox^ tb, Color colorOfHint);
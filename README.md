# Notes
3-rd semester coursework

### About

An application that helps the user to organize notes. The following functions are available:
- creating a note
- deleting a note
- editing a note
- choosing the way to display notes
- selection of displayed themes
- safe removal

The application has an intuitive visual interface\
Supported menu language: **Russian**

### Overview

> On the main screen there is a list of notes, buttons for managing them, and so on\
> In the picture below, the lists are displayed in the order of creation (new ones on top)

<img src="https://github.com/mkKurish/Notes/blob/main/demonstration/sh1.png" alt="drawing" width="450"/>

> You can change the display mode to display "by topic"

<img src="https://github.com/mkKurish/Notes/blob/main/demonstration/sh2.png" alt="drawing" width="100"/>

> Here's what you'll get

<img src="https://github.com/mkKurish/Notes/blob/main/demonstration/sh3.png" alt="drawing" width="450"/>

> The form for creating a note looks simple\
> Hints help you understand how to fill out the form

<img src="https://github.com/mkKurish/Notes/blob/main/demonstration/sh4.png" alt="drawing" width="300"/>

> When you change a note (to do this, click on the note in the list twice), you have a similar form in front of you

<img src="https://github.com/mkKurish/Notes/blob/main/demonstration/sh5.png" alt="drawing" width="300"/>

### Development

Used in the development
- C++
- C++/CLI
- OOP
- WinForms
- MVP architecture
- nlohmann json c++

### Code

The following **variable naming** convention is used in the project code:\
- variable names have the style “camel case” together with “lower case", for example, “mainData“ or ”SolidBrush"
- function names also have the style “camel case” together with “lower case”, for example, “removeByTopic“ or ”loadData"
- the names of classes (structures) have the style “camel case” together with “lower case”, except for the first letter, it is capitalized. An example is “DataManipulator" and “Note"

The general **design style of the program code** corresponds to the following points:\
- each nested block of code is one indent “tab" above the parent block
- there are line gaps between lines of code in logically justified places to improve code readability
- comments in the code are written in English
- multi-line comments are written before functions and contain a brief description of their work
- one-line comments are used in special cases if it is difficult to understand the meaning of certain code elements or algorithms without them
- the program code is divided into files according to the grouping of functionality:
  * each form should be contained in a single file, where only the code of this form should be located
  * each developed entity (a block of strongly interconnected entities) should be contained in a separate file
  * it is not prohibited to have two files if they are files with the extensions “.h” and “.cpp” created for the appropriate purpose

### Future

The program has perspectives of development. A small list of future functionality:
- setting up to enable/disable synchronization of themes by colors
- popup hint when hovering over the abbreviated text
- setting the font size and type change in the entire application or in its individual parts
- setting up the change of the general graphic theme of the application (light theme and dark theme)
- deleting notes to the “trash”
- expanding the number of supported menu languages
- data synchronization using a system of accounts and remote servers

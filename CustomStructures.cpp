#include "CustomStructures.h"

char* Note::getTime() {
	char* buff = new char[17];
	tm* creation_tm;
	creation_tm = localtime(&creationTime);
	strftime(buff, 17 * sizeof(char), "%H:%M %d.%m.%Y", creation_tm);
	return buff;
}

bool Note::equals(Note* anotherNote) {
	if (this->header != anotherNote->header)
		return false;
	if (this->body != anotherNote->body)
		return false;
	if (this->creationTime != anotherNote->creationTime)
		return false;
	if (this->topic.name != anotherNote->topic.name)
		return false;
	return true;
}

void NotesList::add(Note value, int index) {
	if (index < 0 || index > size)
		return;
	NotesNode* temp = head;
	NotesNode* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	NotesNode* additional = new NotesNode(value, temp);
	if (prev != nullptr)
		prev->next = additional;
	if (index == 0)
		head = additional;
	size++;
}

void NotesList::add(Note value) {
	add(value, size);
}

void NotesList::remove(int index) {
	if (isEmpty() || index >= size || index < 0)
		return;
	NotesNode* temp = head;
	NotesNode* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	if (prev != nullptr)
		prev->next = temp->next;
	if (index == 0)
		head = temp->next;
	NotesNode* allNext = temp->next;
	while (allNext != nullptr) {
		allNext->note.indexInMainList--;
		allNext = allNext->next;
	}
	delete temp;
	size--;
}

void NotesList::remove() {
	remove(size - 1);
}

Note* NotesList::elementAt(int index) {
	if (index >= size || isEmpty() || index < 0)
		return new Note("Error", "Error", Topic());
	NotesNode* curr = head;
	while (index != 0) {
		curr = curr->next;
		index--;
	}
	return &curr->note;
}

Note* NotesList::elementLast() {
	return elementAt(size - 1);
}

void NotesList::clear() {
	while (!isEmpty())
		remove();
}

int NotesList::getSize() {
	return size;
}

bool NotesList::isEmpty() {
	return size == 0;
}

void NotesPointersList::add(Note* value, int index) {
	if (index < 0 || index > size)
		return;
	NotesNode* temp = head;
	NotesNode* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	NotesNode* additional = new NotesNode(value, temp);
	if (prev != nullptr)
		prev->next = additional;
	if (index == 0)
		head = additional;
	size++;
}

void NotesPointersList::add(Note* value) {
	int i = 0;
	NotesNode* curr = head;
	while (i < this->size) {
		if (curr->note->creationTime < value->creationTime)
			break;
		i++;
		curr = curr->next;
	}
	add(value, i);
}

void NotesPointersList::addLast(Note* value) {
	add(value, size);
}

void NotesPointersList::remove(int index) {
	if (isEmpty() || index >= size || index < 0)
		return;
	NotesNode* temp = head;
	NotesNode* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	if (prev != nullptr)
		prev->next = temp->next;
	if (index == 0)
		head = temp->next;
	delete temp;
	size--;
}

void NotesPointersList::remove(Note* specifiedNote) {
	int index = indexOf(specifiedNote);
	if (index == -1)
		return;
	if (isEmpty() || index >= size || index < 0)
		return;
	NotesNode* temp = head;
	NotesNode* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	if (prev != nullptr)
		prev->next = temp->next;
	if (index == 0)
		head = temp->next;
	delete temp;
	size--;
}

void NotesPointersList::remove() {
	remove(size - 1);
}

Note* NotesPointersList::elementAt(int index) {
	if (index >= size || isEmpty())
		return new Note("Error", "Error", Topic());
	NotesNode* curr = head;
	while (index != 0) {
		curr = curr->next;
		index--;
	}
	return curr->note;
}

int NotesPointersList::indexOf(Note* specificNote) {
	NotesNode* curr = head;
	int i = 0;
	while (curr != nullptr) {
		if (curr->note->equals(specificNote))
			return i;
		curr = curr->next;
		i++;
	}
	return -1;
}

Note* NotesPointersList::elementLast() {
	return elementAt(size - 1);
}

void NotesPointersList::clear() {
	while (!isEmpty())
		remove();
}

int NotesPointersList::getSize() {
	return size;
}

bool NotesPointersList::isEmpty() {
	return size == 0;
}

void TopicsList::add(Topic value, int index) {
	if (index < 0 || index > size)
		return;
	Node* temp = head;
	Node* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	Node* additional = new Node(value, temp);
	if (prev != nullptr)
		prev->next = additional;
	if (index == 0)
		head = additional;
	size++;
}

void TopicsList::add(Topic value) {
	add(value, size);
}

void TopicsList::remove(int index) {
	if (isEmpty() || index >= size || index < 0)
		return;
	Node* temp = head;
	Node* prev = nullptr;
	for (int i = 0; i < index; i++) {
		if (i == index - 1)
			prev = temp;
		temp = temp->next;
	}
	if (prev != nullptr)
		prev->next = temp->next;
	if (index == 0)
		head = temp->next;
	delete temp;
	size--;
}

void TopicsList::remove() {
	remove(size - 1);
}

void TopicsList::removeByTopic(Topic topic) {
	Node* curr = head;
	Node* prev = nullptr;
	while (curr != nullptr) {
		if (curr->topic.name == topic.name) {
			if (prev != nullptr)
				prev->next = curr->next;
			else
				head = curr->next;
			delete curr;
			size--;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

Topic& TopicsList::topicAt(int index) {
	if (index >= size || isEmpty())
		return Topic();
	Node* curr = head;
	while (index != 0) {
		curr = curr->next;
		index--;
	}
	return curr->topic;
}

Topic& TopicsList::lastTopic() {
	return topicAt(size - 1);
}

Topic& TopicsList::getExistingTopic(std::string topic) {
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->topic.name == topic)
			return curr->topic;
		curr = curr->next;
	}
	return *(new Topic());
}

NotesPointersList* TopicsList::getExistingTopicsNotesList(std::string topic) {
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->topic.name == topic)
			return &curr->notes;
		curr = curr->next;
	}
	return new NotesPointersList();
}

NotesPointersList* TopicsList::topicNotesListAt(int index) {
	if (index >= size || isEmpty())
		return new NotesPointersList();
	Node* curr = head;
	while (index != 0) {
		curr = curr->next;
		index--;
	}
	return &curr->notes;
}

NotesPointersList* TopicsList::lastTopicNotesList() {
	return topicNotesListAt(size - 1);
}

bool TopicsList::isTopicExists(std::string topic) {
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->topic.name == topic)
			return true;
		curr = curr->next;
	}
	return false;
}

void TopicsList::clear() {
	while (!isEmpty())
		remove();
}

int TopicsList::getSize() {
	return size;
}

bool TopicsList::isEmpty() {
	return size == 0;
}


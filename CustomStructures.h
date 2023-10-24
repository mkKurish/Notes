#pragma once
#include <string>
#include <ctime>

struct Topic {
	std::string name;
	int colorARGB;
	Topic() {
		name = "";
		colorARGB = 0;
	}
	Topic(std::string name, int colorARGB) {
		this->name = name;
		this->colorARGB = colorARGB;
	}
};

struct Note {
	std::string header;
	std::string body;
	Topic topic;
	time_t creationTime;
	Note() {
		creationTime = time(NULL);
	}
	Note(std::string header, std::string body, Topic topic) {
		this->header = header;
		this->body = body;
		this->topic = topic;
		creationTime = time(NULL);
	}
	char* getTime() {
		return ctime(&creationTime);
	}
};

/*
Sigle-linked list of notes.
*/
struct NotesList {
	struct NotesNode {
		Note note;
		NotesNode* next;
		NotesNode(Note note, NotesNode* next = nullptr) {
			this->note = note;
			this->next = next;
		}
	};
private:
	int size;
	NotesNode* head;
public:
	/**
	The default constructor, that set head of the 
	list to nullptr and size of the list to 0.
	*/
	NotesList() {
		head = nullptr;
		size = 0;
	}
	/**
	Use to add an element (Note) to specified index in the list.
	*/
	void add(Note value, int index) {
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
	/**
	Use to add an element (Note) as the last one in the list.
	*/
	void add(Note value) {
		add(value, size);
	}
	/**
	Use to delete specified element from the list.
	*/
	void remove(int index) {
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
	/*
	Use to delete the last element from the list.
	*/
	void remove() {
		remove(size - 1);
	}
	/*
	Use to get an element of the list at specified index.
	*/
	Note& elementAt(int index) {
		if (index >= size || isEmpty())
			return Note("Error", "Error", Topic());
		NotesNode* curr = head;
		while (index != 0) {
			curr = curr->next;
			index--;
		}
		return curr->note;
	}
	/*
	Use to get the last element of the list.
	*/
	Note& elementLast() {
		return elementAt(size - 1);
	}
	/*
	Use to delete all the elements from list.
	*/
	void clear() {
		while (!isEmpty())
			remove();
	}
	/*
	Use to get size of the list.
	*/
	int getSize() {
		return size;
	}
	/*
	Use to check if list is empty.
	*/
	bool isEmpty() {
		return size == 0;
	}
	/*
	The default destructor.
	*/
	~NotesList() {
		clear();
	}
};

/*
Sigle-linked list of pointers to notes.
*/
struct NotesPointersList {
	struct NotesNode {
		Note* note;
		NotesNode* next;
		NotesNode(Note* note, NotesNode* next = nullptr) {
			this->note = note;
			this->next = next;
		}
	};
private:
	int size;
	NotesNode* head;
public:
	/**
	The default constructor, that set head of the
	list to nullptr and size of the list to 0.
	*/
	NotesPointersList() {
		head = nullptr;
		size = 0;
	}
	/**
	Use to add an element (pointer to Note) to specified index in the list.
	*/
	void add(Note* value, int index) {
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
	/**
	Use to add an element (pointer to Note) as the last one in the list.
	*/
	void add(Note* value) {
		add(value, size);
	}
	/**
	Use to delete specified element from the list.
	*/
	void remove(int index) {
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
	/*
	Use to delete the last element from the list.
	*/
	void remove() {
		remove(size - 1);
	}
	/*
	Use to get an element of the list at specified index.
	*/
	Note& elementAt(int index) {
		if (index >= size || isEmpty())
			return Note("Error", "Error", Topic());
		NotesNode* curr = head;
		while (index != 0) {
			curr = curr->next;
			index--;
		}
		return *curr->note;
	}
	/*
	Use to get the last element of the list.
	*/
	Note& elementLast() {
		return elementAt(size - 1);
	}
	/*
	Use to delete all the elements from list.
	*/
	void clear() {
		while (!isEmpty())
			remove();
	}
	/*
	Use to get size of the list.
	*/
	int getSize() {
		return size;
	}
	/*
	Use to check if list is empty.
	*/
	bool isEmpty() {
		return size == 0;
	}
	/*
	The default destructor.
	*/
	~NotesPointersList() {
		clear();
	}
};

/*
Sigle-linked list of notes.
*/
struct TopicsList {
private:
	struct Node {
		Topic topic;
		NotesPointersList notes;
		Node* next;
		Node(Topic topic, Node* next = nullptr) {
			this->topic = topic;
			this->next = next;
		}
	};
	Node* head;
	int size;
public:
	/**
	The default constructor, that set head of the
	list to nullptr and size of the list to 0.
	*/
	TopicsList() {
		head = nullptr;
		size = 0;
	}
	/**
	Use to add an element (Topic) to specified index in the list.
	*/
	void add(Topic value, int index) {
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
	/**
	Use to add an element (Topic) as the last one in the list.
	*/
	void add(Topic value) {
		add(value, size);
	}
	/**
	Use to delete specified element from the list.
	*/
	void remove(int index) {
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
	/*
	Use to delete the last element from the list.
	*/
	void remove() {
		remove(size - 1);
	}
	/*
	Use to remove an existing topic.
	*/
	void removeByTopic(Topic topic) {
		Node* curr = head;
		Node* prev = nullptr;
		while (curr != nullptr) {
			if (curr->topic.name == topic.name) {
				if (prev != nullptr)
					prev->next = curr->next;
				else
					head = curr->next;
				delete curr;
				return;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	/*
	Use to get an element of the list at specified index.
	*/
	Topic& topicAt(int index) {
		if (index >= size || isEmpty())
			return Topic();
		Node* curr = head;
		while (index != 0) {
			curr = curr->next;
			index--;
		}
		return curr->topic;
	}
	/*
	Use to get the last element of the list.
	*/
	Topic& lastTopic() {
		return topicAt(size - 1);
	}
	/*
	Use to get an existing topic.
	*/
	Topic& getExistingTopic(std::string topic) {
		Node* curr = head;
		while (curr != nullptr) {
			if (curr->topic.name == topic)
				return curr->topic;
			curr = curr->next;
		}
		return Topic();
	}
	/*
	Use to get an existing topic's notes list.
	*/
	NotesPointersList& getExistingTopicsNotesList(std::string topic) {
		Node* curr = head;
		while (curr != nullptr) {
			if (curr->topic.name == topic)
				return curr->notes;
			curr = curr->next;
		}
		return NotesPointersList();
	}
	/*
	Use to get an element of the list at specified index.
	*/
	NotesPointersList& topicNotesListAt(int index) {
		if (index >= size || isEmpty())
			return NotesPointersList();
		Node* curr = head;
		while (index != 0) {
			curr = curr->next;
			index--;
		}
		return curr->notes;
	}
	/*
	Use to get the last element of the list.
	*/
	NotesPointersList& lastTopicNotesList() {
		return topicNotesListAt(size - 1);
	}
	/*
	Use to find out if the topic exists
	*/
	bool isTopicExists(std::string topic) {
		Node* curr = head;
		while (curr != nullptr) {
			if (curr->topic.name == topic)
				return true;
			curr = curr->next;
		}
		return false;
	}
	/*
	Use to delete all the elements from list.
	*/
	void clear() {
		while (!isEmpty())
			remove();
	}
	/*
	Use to get size of the list.
	*/
	int getSize() {
		return size;
	}
	/*
	Use to check if list is empty.
	*/
	bool isEmpty() {
		return size == 0;
	}
	/*
	The default destructor.
	*/
	~TopicsList() {
		clear();
	}
};
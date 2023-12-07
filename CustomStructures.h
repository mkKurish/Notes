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
	int indexInMainList;

	Note() {
		creationTime = time(NULL);
	}

	Note(std::string header, std::string body, Topic topic, int mainIndex = -1) {
		this->header = header;
		this->body = body;
		this->topic = topic;
		this->indexInMainList = mainIndex;
		creationTime = time(NULL);
	}

	/*
	Getting a string representation of the creation time.
	Format "HH:MM dd.mm.YY".
	*/
	char* getTime();

	/*
	Ñhecking for equality of notes.
	*/
	bool equals(Note* anotherNote);
};


// Sigle-linked list of notes.
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
	/*
	The default constructor, that set head of the
	list to nullptr and size of the list to 0.
	*/
	NotesList() {
		head = nullptr;
		size = 0;
	}

	/*
	Use to add an element (Note) to specified index in the list.
	*/
	void add(Note value, int index);

	/*
	Use to add an element (Note) as the last one in the list.
	*/
	void add(Note value);

	/*
	Use to delete specified element from the list.
	*/
	void remove(int index);

	/*
	Use to delete the last element from the list.
	*/
	void remove();

	/*
	Use to get an element of the list at specified index.
	*/
	Note* elementAt(int index);

	/*
	Use to get the last element of the list.
	*/
	Note* elementLast();

	/*
	Use to delete all the elements from list.
	*/
	void clear();

	/*
	Use to get size of the list.
	*/
	int getSize();

	/*
	Use to check if list is empty.
	*/
	bool isEmpty();

	/*
	The default destructor.
	*/
	~NotesList() {
		clear();
	}
};


// Sigle-linked list of pointers to notes.
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
	/*
	The default constructor, that set head of the
	list to nullptr and size of the list to 0.
	*/
	NotesPointersList() {
		head = nullptr;
		size = 0;
	}

	/*
	Use to add an element (pointer to Note) to specified index in the list.
	*/
	void add(Note* value, int index);

	/*
	Use to add an element (pointer to Note) in correct position by date.
	*/
	void add(Note* value);

	/*
	Use to add an element (pointer to Note) as the last one in the list.
	*/
	void addLast(Note* value);

	/*
	Use to delete specified element from the list.
	*/
	void remove(int index);

	/*
	Use to delete specified element from the list.
	*/
	void remove(Note* specifiedNote);

	/*
	Use to delete the last element from the list.
	*/
	void remove();

	/*
	Use to get an element of the list at specified index.
	*/
	Note* elementAt(int index);

	/*
	Use to find index of Note in NotesList.
	Returns -1 if the Note wasn't found.
	*/
	int indexOf(Note* specificNote);

	/*
	Use to get the last element of the list.
	*/
	Note* elementLast();

	/*
	Use to delete all the elements from list.
	*/
	void clear();

	/*
	Use to get size of the list.
	*/
	int getSize();

	/*
	Use to check if list is empty.
	*/
	bool isEmpty();

	/*
	The default destructor.
	*/
	~NotesPointersList() {
		clear();
	}
};


// Sigle-linked list of topics.
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
	/*
	The default constructor, that set head of the
	list to nullptr and size of the list to 0.
	*/
	TopicsList() {
		head = nullptr;
		size = 0;
	}

	/*
	Use to add an element (Topic) to specified index in the list.
	*/
	void add(Topic value, int index);

	/*
	Use to add an element (Topic) as the last one in the list.
	*/
	void add(Topic value);

	/*
	Use to delete specified Topic from the list.
	*/
	void remove(int index);

	/*
	Use to delete the last Topic from the list.
	*/
	void remove();

	/*
	Use to remove an existing topic.
	*/
	void removeByTopic(Topic topic);

	/*
	Use to get an element of the list at specified index.
	*/
	Topic& topicAt(int index);

	/*
	Use to get the last element of the list.
	*/
	Topic& lastTopic();

	/*
	Use to get an existing topic.
	*/
	Topic& getExistingTopic(std::string topic);

	/*
	Use to get an existing topic's notes list.
	*/
	NotesPointersList* getExistingTopicsNotesList(std::string topic);

	/*
	Use to get an element of the list at specified index.
	*/
	NotesPointersList* topicNotesListAt(int index);

	/*
	Use to get the last element of the list.
	*/
	NotesPointersList* lastTopicNotesList();

	/*
	Use to find out if the topic exists
	*/
	bool isTopicExists(std::string topic);

	/*
	Use to delete all the elements from list.
	*/
	void clear();

	/*
	Use to get size of the list.
	*/
	int getSize();

	/*
	Use to check if list is empty.
	*/
	bool isEmpty();

	/*
	The default destructor.
	*/
	~TopicsList() {
		clear();
	}
};
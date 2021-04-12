#include <string>
#include <iostream>

using namespace std;

int getInt();

class obj {
public:
	void writePointers();
	void setName(string name);
	void setPointers(obj* pointer1, obj* pointer2);
private:
	string name;
	obj* pointer1, * pointer2;
};

void obj::writePointers() {
	if (pointer1 && pointer2)
		cout << "I " << name << " have pointer to " << pointer1->name << " and to " << pointer2->name << endl;
	else if (pointer1 && !pointer2)
		cout << "I " << name << " have pointer to " << pointer1->name << endl;
	else if (!pointer1 && pointer2)
		cout << "I " << name << " have pointer to " << pointer2->name << endl;
	else
		cout << "I " << name << " dont have any pointers." << endl;
}

void obj::setName(string name) {
	this->name = name;
}

void obj::setPointers(obj* pointer1, obj* pointer2) {
	this->pointer1 = pointer1;
	this->pointer2 = pointer2;
}

class Tree {
public:
	void setNumberOfBlocks();
	void printPointers();
private:
	void setNames();
	void setConnections();
	obj* objects;
	int numberOfObjects, numberOfBlocks;
};

void Tree::setNumberOfBlocks() {
	cout << "Input numbers of blocks: ";
	while (true) {
		numberOfBlocks = getInt();
		if (numberOfBlocks < 0) {
			cout << "Number of blocks must be > 0: ";
			continue;
		}
		else
			break;
	}
	numberOfObjects = 3 * numberOfBlocks + 1;
	objects = new obj[numberOfObjects];
}

void Tree::printPointers() {
	setNames();
	setConnections();
	for (int i = 0; i < numberOfObjects; i++)
		objects[i].writePointers();
}

void Tree::setNames() {
	for (int i = 0; i < numberOfObjects; i++)
		objects[i].setName("object" + to_string(i + 1));
}

void Tree::setConnections() {
	objects[numberOfObjects - 1].setPointers(nullptr, nullptr);
	for (int i = 0; i < numberOfObjects - 1; i++) {
		if (i % 3 == 0)
			objects[i].setPointers(&objects[i + 1], &objects[i + 2]);
		else if (i % 3 == 1)
			objects[i].setPointers(&objects[i + 1], &objects[i + 2]);
		else if (i % 3 == 2)
			objects[i].setPointers(&objects[i - 1], &objects[i + 1]);
	}
}

int getInt()
{
	int number;
	while (true) {
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Do input again." << endl;
		}
		else
			return number;
	}
}

int main() {
	Tree tree;
	tree.setNumberOfBlocks();
	tree.printPointers();
	return 0;
}

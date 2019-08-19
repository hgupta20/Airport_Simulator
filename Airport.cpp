#include "proj6Decl.h"

Airport::Airport() {
	isvisited = false;
	destination = new List();
}

void Airport::setIsvisited(bool n) {
	isvisited = n;
}
List* Airport::getList() {
	return destination;
}
bool Airport::getIsvisited() {
	return isvisited;
}

void Airport::pushPort(int n) {
	destination->addValue(n);

}

void Airport::deletePort(int n) {
	destination->remove(n);

}

void Airport::display() {
	destination->printList();
}

void Airport::clear() {
	destination->clearList();
}


MyLnode::MyLnode() {
	elem = 0;
	next = NULL;
}
MyLnode::MyLnode(int n) {
	elem = n;
	next = NULL;
}
int MyLnode::getNum() {
	return elem;
}
void MyLnode::setNum(int n) {
	elem = n;
}
MyLnode* MyLnode::getNext() {
	return next;
}
void MyLnode::setNext(MyLnode *tmp) {
	next = tmp;
}

List::List() {
	head = NULL;
}
void List::addValue(int n) {
	MyLnode *nxt = new MyLnode(n);

	if (head == NULL) {
		head = nxt;
		return;
	}
	else {
		nxt->setNext(head->getNext());
		head->setNext(nxt);
	}
}

void List::remove(int n) {
	MyLnode *temp = new MyLnode();
	temp = head;

	MyLnode *prev;
	prev = new MyLnode();
	prev = temp;

	if (head->getNum() == n) {
		head = NULL;
		return;
	}

	while (temp != NULL) {
		if (temp->getNum() == n) {
			prev->setNext(temp->getNext());
			break;
		}
		prev = temp;
		temp = temp->getNext();
	}
	if (temp == NULL) {
		printf("One of the expected destinations is not part of the flight schedule.\n");
	}
	delete temp;
}

void List::printList() {
	MyLnode *temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->getNum());
		temp = temp->getNext();
	}
}

void List::deleteHead() {
	MyLnode *temp = new MyLnode();
	temp = head;
	head = head->getNext();
	delete temp;
}

void List::clearList() {
	while (head != NULL) {
		deleteHead();
	}
}

int List::getLength() {
	int counter = 0;
	MyLnode *temp = head;
	while (temp != NULL) {
		counter++;
		temp = temp->getNext();
	}
	return counter;
}

int List::getNthElement(int n) {
	int length = getLength();
	if (length < n) {
		printf("Error: There are not that many elements.");
		return -1;
	}
	MyLnode *temp = head;
	for (int i = 0; i < n; i++) {
		temp = temp->getNext();
	}
	return temp->getNum();
}
bool List::numExist(int a) {
	bool exist = false;
	MyLnode *temp = head;
	while (temp != NULL) {
		if (a == temp->getNum())
			exist = true;
		temp = temp->getNext();
	}
	return exist;
}
bool List::canGetToPort(int n) {
	MyLnode* temp = head;
	bool possible = false;
	while (temp != NULL) {
		if (temp->getNum() == n) {
			possible = true;
			return possible;
		}
		temp = temp->getNext();
	}
	return possible;
}




strnode::strnode() {
	next = NULL;
	flnm = "a";
}
strnode::strnode(string a) {
	next = NULL;
	flnm = a;
}
string strnode::getName() {
	return flnm;
}
void strnode::setName(string a) {
	flnm = a;
}
strnode* strnode::getNext() {
	return next;
}
void strnode::setNext(strnode *nxt) {
	next = nxt;
}

StrList::StrList() {
	head = NULL;
}
void StrList::addName(string n) {
	strnode *nxt = new strnode(n);

	if (head == NULL) {
		head = nxt;
		return;
	}
	else {
		nxt->setNext(head->getNext());
		head->setNext(nxt);
	}
}

bool StrList::nameExist(string a) {
	bool exist = false;
	strnode *temp = head;
	while (temp != NULL) {
		if (!a.compare(temp->getName()))
			exist = true;
		temp = temp->getNext();
	}
	return exist;
}

void StrList::remove(string a) {
	strnode *temp;
	temp = new strnode();
	temp = head;

	strnode *prev;
	prev = new strnode();
	prev = temp;

	if (!(head->getName()).compare(a)) {
		head = NULL;
		return;
	}

	while (temp != NULL) {
		if (!(temp->getName()).compare(a)) {
			prev->setNext(temp->getNext());
			break;
		}
		prev = temp;
		temp = temp->getNext();
	}
	delete temp;
}


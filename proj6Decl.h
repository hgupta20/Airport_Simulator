#include <cstdio>
#include <string.h>
#include <iostream>
#include <cstdlib>
using namespace std;

class MyLnode {
private:
	int elem;
	MyLnode *next;
public:
	MyLnode();
	MyLnode(int n);
	int getNum();
	void setNum(int n);
	MyLnode* getNext();
	void setNext(MyLnode *tmp);
};

class List
{
private:
	MyLnode * head;
public:


	List();
	void addValue(int n);
	void remove(int n);

	void printList();

	void deleteHead();
	void clearList();

	int getLength();
	int getNthElement(int n);
	bool numExist(int a);
	bool canGetToPort(int n);

};

class strnode {
private:
	string flnm;
	strnode *next;
public:
	strnode();
	strnode(string a);
	string getName();
	void setName(string a);
	strnode *getNext();
	void setNext(strnode *nxt);
};

class StrList
{
private:
	strnode* head;
public:


	StrList();
	void addName(string n);
	bool nameExist(string a);
	void remove(string a);
};

class Airport
{
private:
	List* destination;
	bool isvisited;

public:
	Airport();

	void setIsvisited(bool n);
	List* getList();
	bool getIsvisited();

	void pushPort(int n);
	void deletePort(int n);
	void display();
	void clear();
};



class TravelNetwork
{
private:
	StrList* files;
	Airport** network;
	int length;
public:

	// Use a constructor to initialize the Data Members for Travel Network
	TravelNetwork();

	// The main loop for reading in input
	void processCommandLoop(FILE* inFile);

	void showCommands();

	void doTravel();

	bool dfs(int a, int b);

	void doResize();

	void doInsert();

	void doDelete();

	void doList();

	void doFile();
};

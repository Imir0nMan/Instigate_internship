#include <iostream>
struct Node
{
	double data;
	Node *next;
	
	Node(double d = 0){
		this->data = d;
		this->next = nullptr;
	}
};

class LinkedList
{
private:	
	Node* m_head;
public:
	int lenght();
	void append(double data);
	void remove();
	void add_start(double data);
	void rm_start();
	void add_at(double data, int p);
	void rm_at(int p);
	void print();
	LinkedList();
	
};

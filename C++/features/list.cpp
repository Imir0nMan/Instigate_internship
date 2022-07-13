#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* link;
};
 
Node* head;
void insert(int a, int n)
{
	Node* temp1 = new Node();
	temp1->data = a;
	temp1->link = NULL;	

	if (n == 1) {
		temp1->link = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for(int i =0; i< n-2; i++)
	{
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}
 
void Print()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->link;
	}
}

void Delete(int n)
{
	Node* temp1 = new Node();
	Node* temp2 = new Node();
	temp1 = head;
	if (n == 1)
	{
		head = temp1->link;
		delete(temp1);
		return;
	}
	for(int i = 0; i < n-2; i++) 
	{
		temp1 = temp1->link;
	}
	temp2 = temp1->link;
	temp1->link = temp2->link;
	delete(temp2);
}

int main()
{
	head = NULL;
	insert(5,1);
	insert(3,2);
	insert(9,3);
	Print();
}

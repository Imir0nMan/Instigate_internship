#include "list.h"

LinkedList::LinkedList(){
	m_head = nullptr;
}

//////////
int LinkedList::lenght()
{
	int size = 0;
	Node *temp = m_head;

	while(temp->next != nullptr){
		temp = temp->next;
		size++;
	}
	size++;
	return size;
}

///////////////////////
void LinkedList::append(double data)
{
	Node *last = new Node(data);
	Node *temp = m_head;
	if(m_head == nullptr){
		m_head = last;
	
		return;
	}
	while(temp->next != nullptr){
		temp = temp->next;
	}
	temp->next = last;
}

/////////////////
void LinkedList::add_start(double data){
	Node* temp = m_head;
	Node* elem = new Node(data);
	//m_head->next = temp;
	m_head = elem;
	m_head->next = temp;
}

/////////////
void LinkedList::add_at(double data, int p)
{
	int size = lenght();
	Node *temp = m_head;
	Node *elem = new Node(data); 
	if(p <= 0 || p > size+1){
		std::cout<<"outofrange ";
		return;
	}
	else if(p == size+1){
		append(data);
		return;
	}
	else if(p == 1){
		add_start(data);
		return;
	}
	while(p-2){
		temp = temp->next;
		p--;
	}
	elem->next = temp->next;
	temp->next = elem;
}
////////////////////////
//////////////////////////////////////////
void LinkedList::print(){
	if(m_head == nullptr){
		std::cout<<"list is empty\n";
		return;
	}
	Node *temp = m_head;
	while(temp->next != nullptr){
		std::cout<<temp->data<<"->";
		temp = temp->next;
	}
	std::cout<<temp->data<<"\n";
}


//////main Kampf

int main(){
	LinkedList list;
	list.append(23);
	list.append(75);
	list.append(65);
	list.append(43);
	list.append(88);
	list.print();
	list.add_at(900, 6);
	list.add_at(1239, 1);
	list.print();
	return 0;
}

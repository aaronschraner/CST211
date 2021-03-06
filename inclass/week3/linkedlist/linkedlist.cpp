#include <iostream>

using namespace std;


template <typename T>
struct list_node
{
	T contents;
	list_node<T>* next;
};

template <typename T>
struct linked_list
{
	list_node<T>* start_node;
	list_node<T>* end_node;
};

template <typename T>
linked_list<T>* create_list (T first_element)
{
	list_node<T>* ln = new list_node<T>;
	ln->contents=first_element;
	ln->next=0;
	linked_list<T>* list = new linked_list<T>;
	list->start_node = ln;
	list->end_node = ln;
	return list;
}

template <typename T>
void add_node(linked_list<T>* list, T node_value)
{
	list_node<T>* node = new list_node<T>;
	node->contents = node_value;
	list_node<T>* tail = list->end_node;
	tail->next = node;
	node->next = 0;
	list->end_node = node;
}

template <typename T>
void remove_node(linked_list<T>* list)
{
	list_node<T>* sec_to_last = list->start_node; //second to last node
	while(sec_to_last->next != list->end_node)
		sec_to_last = sec_to_last->next;
	delete sec_to_last -> next; //last node 
	sec_to_last -> next = 0;
	list -> end_node = sec_to_last;
}

template <typename T>
void clear_list(linked_list<T>* list)
{
	list_node<T>* iter = list->start_node;

	while(iter != list->end_node)
	{
		list_node<T>* prev = iter;
		iter = iter -> next;
		delete prev;
	}
	delete iter;
	list->start_node = 0;
	list->end_node = 0;
}

template <typename T>
void print_list(linked_list<T>* list)
{
	list_node<T>* pos = list->start_node;
	if(pos == 0)
		cout << "<empty list>";
	while(pos != 0)
	{
		cout << pos->contents << ", ";
		pos = pos->next;
	}
	cout << endl;
}
int main()
{
	linked_list<int>* myList = create_list(100);
	list_node<int>* pos = myList -> start_node;
	add_node(myList, 300);
	add_node(myList, 400);
	print_list(myList);
	remove_node(myList);
	print_list(myList);
	add_node(myList, 500);
	clear_list(myList);
	print_list(myList);
	delete myList;

}


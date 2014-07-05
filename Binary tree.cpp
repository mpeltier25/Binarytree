#include "node.h"
#include "Binary tree.h"
#include <iostream>
using namespace std;

Node::Node(string nomen, int val): data(val), name (nomen)
{
next = NULL;
}
Node::~Node(){
if (next)
delete next;
}
Binarytree::Binarytree(){
rootpointer=NULL;
leftpointer=NULL;
rightpointer=NULL;
}
Binarytree::~Binarytree(){
if(rootpointer)
delete rootpointer;
if(leftpointer)
delete leftpointer;
if(rightpointer)
delete rightpointer;
}
//will remove the first element with the string toGo
void Binarytree::remove(string toGo){
//first if there is nothing in the tree, delete nothing
	if (!rootpointer){
		cout<<"Error: tried to delete from empty tree" <<endl;
	return;
	}
	Node* toDelete=NULL;
	//now lets find the string toGo-lets look at the first one as a special case and from then on do so with look arootpointer so we can use
	//just one pointer.
	if(!toGo.compare(rootpointer->getName())){//recall that compare returns 0 for equal
		toDelete=rootpointer;
		rootpointer=rootpointer->next;
	}
else
	{
	Node* current=rootpointer;
	while(current->next){
	if(!toGo.compare(current->next->getName()))
	{//we found it
	toDelete=current->next;
	//remove current -> next from the tree since it is the one to delete
	current->next=current->next->next;
	break;
	}
	}
	if(!toGo.compare(leftpointer->getName())){//recall that compare returns 0 for equal
		toDelete=leftpointer;
		leftpointer=leftpointer->next;
	}
	if(!toGo.compare(rightpointer->getName())){//recall that compare returns 0 for equal
		toDelete=rightpointer;
		rightpointer=rightpointer->next;
	}
	}
//if we didn't find the node then toDelete is NULL, so just return
	if(!toDelete){
	cout<<"You wanted me to delete "<<toGo<<"But its not in the tree"<<endl;
	return;
	}
	//now delete it
	toDelete->next=NULL; //important because of how I'm implementing memory management using the node destructor
	delete toDelete;
}
void Binarytree::insert(Node* newNode){
//if there is nothing in the tree now, then add to the beginning
	if(!rootpointer){
	rootpointer=newNode;
	return;
	}
	if(!leftpointer){
	leftpointer=newNode;
	return;
	}
	if(!rightpointer){
	rightpointer=newNode;
	return;
	}
	/* otherwise look for the right spot. There are two possibilities 
	1. the new item belongs at the beginning of the tree or
	2. the new item begins somewhere else in the tree.
	*/
	string newName=newNode->getName();
	Node* temp=rootpointer;
	//While there is a nextNode
	while(temp->next){
	//if the one we are looking for is alphabetically after the one we have
		if(newName.compare(temp->next->getName())>0)
		break; //we found where to put the new node
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}
	void Binarytree::printData(){
	Node* temp=rootpointer;
	while (temp){ //same as while (temp!=NULL0
		cout<<"Node with name"<<temp->getName()<<"and number" <<temp->getData()<<endl;
		temp=temp->next;
	Node*temp=leftpointer;
	while (temp){ //same as while (temp!=NULL0
		cout<<"Node with name"<<temp->getName()<<"and number" <<temp->getData()<<endl;
		temp=temp->next;
	Node*temp=rightpointer;
	while (temp){ //same as while (temp!=NULL0
		cout<<"Node with name"<<temp->getName()<<"and number" <<temp->getData()<<endl;
		temp=temp->next;
	}
	}
	}
	}
	int main(){
	Binarytree tree; //This is called the Binarytree constructor.
	int choice=0;
	string name;
	int data;
	Node* newNode=NULL;
	//loop forever with the menu
	while(true){
	//print the menu
		cout<<"What would you like to do? Please enter one of the numbers below:"<<endl;
		cout<<"1) Add a new tree item."<<endl;
		cout<<"2) remove a tree item."<<endl;
		cout<<"3) print the tree"<<endl;
		cout<<"4) Quit the program"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
			cout<<" Enter the name for the new item: ";
			cin>>name;
			cout<<" Enter the number for the new item: ";
			cin>>data;
			newNode=new Node (name, data);
			tree.insert(newNode);
			break;
		case 2:
			cout<<"Enter name of node to delete:";
			cin>>name;
			tree.remove(name);
			break;
		case 3:
			cout<<" The tree contains: "<<endl;
			tree.printData();
			break;
		case 4: 
			cout<<"Goodbye";
			return 0;
		default:
		cout<<"That was invalid input, please choose a value from 1-4 from the tree"<<endl;
		}
	}
	return 0;
	}

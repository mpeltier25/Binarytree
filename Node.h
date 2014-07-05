#ifndef _NODE_H_
#define _NODE_H_
#include <string>
using namespace std;
class Node{
private:
	string name;
	int data;
public:
Node* next;
string getName() {return name;}
int getData(){return data;}
Node (string nomen, int value);
~Node();

};
#endif

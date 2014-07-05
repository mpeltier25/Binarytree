#ifndef  _Binarytree_H_
#define _Binarytree_H_
#include "node.h"
using namespace std;
class Binarytree{
private:
Node* rootpointer;
Node*leftpointer;
Node*rightpointer;
public:
	void insert (Node* newNode);
	void remove (string toGo);
	void printData();
	Binarytree();
	~Binarytree();

};
#endif

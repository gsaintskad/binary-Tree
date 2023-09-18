//sorted binary tree
#include<iostream>
#include<string>
#include"BinTree.h"
using namespace std;


int main() {

	BinTree t;


	t.insert(5);
	t.insert(2);
	t.insert(7);
	t.insert(6);
	t.insert(3);
	
	t.insert(9);


	t.DeleteTarget(5);
	t.DeleteTarget(7);

	return 0;
}

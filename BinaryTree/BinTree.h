#pragma once
#include<string>
#include<iostream>
using namespace std;
class BinTree {
public:
	class Node {
	public:
		int data;
		Node* prev;
		Node* left;
		Node* right;
		string path;
		Node();
		Node(int data);
		void operator = (const Node& n) {
			this->data = n.data;
		}

	private:

	};
private:
	
	Node* search_recoursive(int target, Node* current);
	void swap(Node* n1, Node* n2);
public:
	Node* root;
	/*Node* getRoot() {
		return root;
	}*/
	BinTree();
	void insert(int newdata);
	Node getmax(Node* n);
	Node* getmin(Node* n);
	void DeleteTarget(int target);
	Node* search(int target) {
		return search_recoursive(target, root);
	}
	~BinTree();
};



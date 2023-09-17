//sorted binary tree
#include<iostream>
#include<string>
#include"Tree.h"
using namespace std;

class BinTree {
private:
	class Node {
	public:
		int data;
		Node* prev;
		Node* left;
		Node* right;
		string path = "->";
		Node() {
			data = 666;
			prev = nullptr;
			left = nullptr;
			right = nullptr;

		}
		Node(int data) {
			this->data = data;
			prev = nullptr;
			left = nullptr;
			right = nullptr;
		}
		void operator = (const Node& n) {
			this->data = n.data;
		}

	private:

	};
	Node* root;
	Node* search_recoursive(int target, Node* current) {
		if (current->data == target) {
			return current;
		}
		else if (target >= current->data) {
			return search_recoursive(target, current->right);
		}
		else return search_recoursive(target, current->left);
	}
	void swap(Node* n1, Node* n2) {
		Node t;
		t = *n1;
		*n1 = *n2;
		*n2 = t;
	}
public:
	BinTree() {
		root = nullptr;
	}
	void insert(int newdata) {
		if (root == nullptr) {
			root = new Node(newdata);
			root->path = "root";
		}
		else {
			Node newnode(newdata);
			Node* current;
			current = root;
			while (true) {
				if (current == nullptr) {
					current = new Node(newnode.data);
					current->prev = newnode.prev;
					if (current->prev != nullptr) {
						if (current->data >= current->prev->data) {
							current->prev->right = current;

						}
						else { current->prev->left = current; }
					}

					break;
				}
				else if (current->data <= newnode.data) {
					newnode.prev = current;
					newnode.path = current->path + " -> " + "right";
					current = current->right;
				}
				else {

					newnode.prev = current;
					newnode.path = current->path+" -> "+"left";
					current = current->left;
				}
			}

		}


	}
	Node getmax(Node* n) {
		if (n == nullptr) return NULL;
		else if (n->right == nullptr) return *n;
		else return getmax(n->right);
	}
	Node* getmin(Node* n) {
		if (n == nullptr) return NULL;
		else if (n->left == nullptr) return n;
		else return getmin(n->left);
	}
	void DeleteTarget(int target) {
		Node* current;
		current = root;
		while (true) {
			if (current->data == target) {
				if (current->right != nullptr && current->left == nullptr) {
					*current = *(current->right);
					*(current->right) = NULL;
					if (current->right->right != nullptr) {
						if (current->right->left != nullptr) {
							current->right->left->prev = current->right->right;
							current->right->right->left = current->right->left;
						}
						current->right = current->right->right;
						current->right->prev = current;
					}
					else if (current->right->right == nullptr && current->right->left != nullptr) {
						current->right = current->right->left;
						current->right->prev = current;
					}
					else current->right = nullptr;
				}
				else if (current->right == nullptr && current->left != nullptr) {
					*current = *(current->left);
					*(current->left) = NULL;
					current->left = nullptr;

				}
				else if (current->right != nullptr && current->left != nullptr) {
					Node* t = current->left;
					while (true) {
						if (t->right == nullptr) {
							break;
						}
						t = t->right;
					}
					*current = *t;


					t->prev->left = nullptr;

					*t = NULL;
					t = nullptr;

				}
				else {

					if (current->data >= current->prev->data) {
						*current = NULL;
						current->prev->right = nullptr;

					}
					else {
						*current = NULL;
						current->prev->left = nullptr;
					}
				}


				break;
			}
			else if (current->data <= target) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}

	}

	Node* search(int target) {
		return search_recoursive(target, root);
	}
};

int main() {

	BinTree t;


	t.insert(5);
	t.insert(2);
	t.insert(7);
	t.insert(6);
	t.insert(3);
	t.search(3)->data=4;
	t.insert(9);


	t.DeleteTarget(5);
	t.DeleteTarget(7);

	return 0;
}
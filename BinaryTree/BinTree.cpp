#include "BinTree.h"
BinTree::Node::Node() {};
BinTree::Node::Node(int data) {
	this->data = data;
	prev = nullptr;
	left = nullptr;
	right = nullptr;
}
BinTree::Node* search_recoursive(int target, BinTree::Node* current) {
		if (current->data == target) {
			return current;
		}
		else if (target >= current->data) {
			return search_recoursive(target, current->right);
		}
		else return search_recoursive(target, current->left);
	}
	void BinTree::swap(BinTree::Node* n1, BinTree::Node* n2) {
		BinTree::Node t;
		t = *n1;
		*n1 = *n2;
		*n2 = t;
	}

BinTree::BinTree() {
		root = nullptr;
}
void BinTree::insert(int newdata) {
		if (root == nullptr) {
			root = new BinTree::Node(newdata);
			root->path = "root";
		}
		else {
			BinTree::Node* newnode = new BinTree::Node(newdata);
			BinTree::Node* current;
			current = root;
			while (true) {
				if (current == nullptr) {
					current = newnode;

					if (current->prev != nullptr) {
						if (current->data >= current->prev->data) {
							current->prev->right = current;

						}
						else { current->prev->left = current; }
					}

					break;
				}
				else if (current->data <= newdata) {
					newnode->prev = current;
					newnode->path = current->path + " -> " + "right";
					current = current->right;
				}
				else {

					newnode->prev = current;
					newnode->path = current->path + " -> " + "left";
					current = current->left;
				}
			}

		}


}
BinTree::Node BinTree::getmax(BinTree::Node* n) {
		if (n == nullptr) return NULL;
		else if (n->right == nullptr) return *n;
		else return getmax(n->right);
	}
BinTree::Node* getmin(BinTree::Node* n) {
		if (n == nullptr) return NULL;
		else if (n->left == nullptr) return n;
		else return getmin(n->left);
	}

	void BinTree::DeleteTarget(int target) {
		Node* current;
		current = root;
		while (true) {
			if (current->data == target) {

				if (current->right != nullptr && current->left == nullptr) {

					current->right->prev = current->prev;
					if (current->right->data < current->prev->data) {
						current->prev->left = current->right;
					}
					else {
						current->prev->right = current->right;
					}
					delete current;
					break;
				}
				else if (current->right == nullptr && current->left != nullptr) {
					current->left->prev = current->prev;
					if (current->left->data < current->prev->data) {
						current->prev->left = current->right;
					}
					else {
						current->prev->right = current->left;
					}
					delete current;
					break;
				}
				else if (current->right != nullptr && current->left != nullptr) {
					Node* t = current->left;
					int i = 0;
					while (true) {
						if (t->right == nullptr) {
							break;
						}
						i++;
						t = t->right;
					}
					*current = *t;
					if (i) {
						t->prev->right = nullptr;
					}
					else {
						t->prev->left = nullptr;
					}
					delete t;
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


	BinTree::~BinTree() {
		BinTree::Node* current = root;
		while (true) {
			if (current->left == nullptr && current->right == nullptr) {
				if (current->prev != nullptr) {
					bool check = current->data < current->prev->data;
					current = current->prev;
					if (check) {
						delete current->left;
						current->left = nullptr;
					}
					else {
						delete current->right;
						current->right = nullptr;
					}


				}
				else {
					delete BinTree::root;
					break;
				}

			}
			else if (current->left != nullptr && current->right == nullptr) {
				current = current->left;
			}
			else if (current->left == nullptr && current->right != nullptr) {
				current = current->right;
			}
			else {
				current = current->left;
			}
		}
		cout << "--==Tree was deleted==--";
	}


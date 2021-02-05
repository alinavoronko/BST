#include <iostream>
#include "bst.h"
using namespace std;


//KONSTRUKTORS
BST::BST() { 
	root = NULL;
}

//DESTRUKTORS
BST::~BST() {
	delete_tree(root);
}

void BST::delete_tree(node* leaf) {
	if (leaf != NULL) {
		delete_tree(leaf->left);
		delete_tree(leaf->right);
		delete leaf;
		leaf=NULL;
	}
}
//PIEVIENO JAUNU MEZGLU
void BST::insert(int key) {
	if (root != NULL) { //ja koks nav tukšs, tad pievieno tam jaunu mezglu
		insert(key, root);
	}
	else { //ja koks ir tukšs, tad šis elements kļūs par sakni
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
//funkcijas pārslogošana ir izmantota lietotāja ērtībai (lai funkcijai būtu jāpadod tikai skaitlis)
void BST::insert(int key, node* leaf) {

	if (key < leaf->value) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key > leaf->value) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

//SAMEKLĒ MEZGLU UN ATGRIEŽ NORĀDI UZ TO
node* BST::search(int key) {
	return search(key, root);
}

node* BST::search(int key, node* leaf) {
	if (leaf != NULL) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}

//IZDRUKĀ KOKU
void BST::print() {
	print(root);
	cout << endl;
}

void BST::print(node* leaf) {
	if (leaf != NULL) {
		print(leaf->left);
		cout << leaf->value << "   ";
		print(leaf->right);
	}
	
}

//SAMEKLĒ MAZGLA VECĀKU 
node* BST::searchforparentnode(node* leaf, int value)
{
	if (leaf->left == NULL && leaf->right == NULL)
		return NULL;

	if (leaf->left && leaf->left->value == value) 
		return leaf;

	if (leaf->right && leaf->right->value == value)
		return leaf;

	if (leaf->left && leaf->value > value)
		return searchforparentnode(leaf->left, value);

	if (leaf->right && leaf->value < value)
		return searchforparentnode(leaf->right, value);

}

//IZDZĒŠ APAKŠKOKU
void BST::delete_subtree(int key) {
	node* ptr = this->search(key);
	node* parent = this->searchforparentnode(root, key);
	delete_tree(ptr);
	if (key<parent->value)  parent->left = NULL;
	else parent->right = NULL;


}



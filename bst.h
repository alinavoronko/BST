/*
Uzrakstīt programmu, kas ļauj izveidot bināru meklēšanas koku, kura mezglos ir naturāli skaitļi.
Skaitlis katrā mezglā ir unikāls un kalpo par atslēgu. Uzrakstīt funkciju, kas no bināra koka izmet apakškoku. 

Autore: Alina Voroņko
*/
#pragma once
struct node {
	int value;
	node* left;
	node* right;
};

class BST {
public:
	BST();
	~BST();

	void insert(int key);
	node* search(int key);
	void print();
	void delete_subtree(int key);


private:
	node* root;
	void delete_tree(node* leaf);
	void insert(int key, node* leaf);
	node* search(int key, node* leaf);
	void print(node* leaf);
	node* searchforparentnode(node* leaf, int value);

};

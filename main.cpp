#include <iostream>
#include "bst.h"
using namespace std;
int main() {

	BST* tree = new BST();

	tree->insert(20);
	tree->insert(18);
	tree->insert(23);
	tree->insert(27);
	tree->insert(15);
	tree->insert(19);
	tree->print();
	/*
		   20
		 /   \
		18     23
	  /   \      \
	 15   19      27

	*/
	tree->delete_subtree(18);
	tree->print();

	/*
		   20
			 \
			  23
				\
				 27

	*/
	tree->insert(10);
	tree->print();
	/*
	   20
	  /	 \
	10	  23
			\
			 27

*/
	delete tree;


}


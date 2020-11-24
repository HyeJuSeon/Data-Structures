#include <iostream>
#include <fstream>
#include "TreeType.h"

int main() {
	TreeType tree;
	int num_node = 0;
	int num = 0;
	std::ofstream file("lab09_1.txt");

	std::cout << "number of node: ";
	std::cin >> num_node;
	for (int i = 0; i < num_node; i++) {
		std::cin >> num;
		tree.InsertItem(num);
	}

//	std::cin >> num;
//	tree.DeleteItem(num);
//	tree.Print(file);

	std::cout << "Is Binary Search Tree? " << tree.IsBST() << std::endl;
	std::cout << "Leaf count: " << tree.LeafCount() << std::endl;
	std::cout << "Single Parent count: " << tree.SingleParentCount() << std::endl;

	return 0;
}
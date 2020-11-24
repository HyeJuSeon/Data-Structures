#include <iostream>
#include "TreeType.h"
using namespace std;


int main() {

	TreeType tree;

	int node_num = 0;
	int num = 0;

	cin >> node_num;
	for (int i = 0; i < node_num; i++) {
		cin >> num;
		tree.InsertItem(num);
	}

	int node1 = 0;
	int node2 = 0;

	cin >> node1 >> node2;


//	TODO : 가장 가까운 공통 조상 구하기
	int* ansc1 = tree.Anscestors(node1);
	int* ansc2 = tree.Anscestors(node2);
	int result = NULL;
	for (int i = _msize(ansc1) / sizeof(int) - 1; i >= 0; i--) {
		for (int j = _msize(ansc2) / sizeof(int) - 1; j >= 0; j--) {
			if (ansc1[i] == ansc2[j]) {
				result = ansc1[i];
				break;
			}
		}
		if (result != NULL)
			break;
	}

	cout << result << endl;

	return 0;
}
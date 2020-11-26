#include <iostream>
#include "PQType.h"

int main() {
	int pq_num, num;
	std::cout << "Priority Queue number: ";
	std::cin >> pq_num;

	PQType<int> pq(pq_num);

	for (int i = 0; i < pq_num; i++) {
		std::cin >> num;
		pq.Enqueue(num);
	}

	int elem;
	std::cout << "Dequeueing" << std::endl;
	for (int i = 0; i < pq_num; i++) {
		pq.Dequeue(elem);
		std::cout << elem << " ";
	}
	return 0;
}
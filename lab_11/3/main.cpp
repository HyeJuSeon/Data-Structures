// D. 
// Sorted list�� ������ Enqueue: O(1)
// Sorted list�� ������ Dequeue: O(1)
// Heap���� ������ Enqueue: O(1)
// Heap���� ������ Dequeue: O(1)

#include <iostream>
#include "PQLLType.h"

int main() {
	PQLLType<int> pq;
	pq.Enqueue(3);
	pq.Enqueue(1);
	pq.Enqueue(11);
	pq.Enqueue(9);
	pq.Enqueue(7);
	pq.Enqueue(5);

	int x, y, z;
	pq.Dequeue(x);  // x = 11
	pq.Dequeue(y);  // y = 9
	pq.Dequeue(z);  // z = 7

	std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

	return 0;
}
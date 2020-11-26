#include <iostream>
#include "PQType.h"

int main() {
	PQType<int> pq(50);
	int x, y, z;

	pq.Enqueue(56);
	pq.Enqueue(27);
	pq.Enqueue(42);
	pq.Enqueue(26);
	pq.Enqueue(15);
	pq.Enqueue(3);
	pq.Enqueue(19);
	pq.Enqueue(25);
	pq.Enqueue(24);
	pq.Enqueue(5);

	pq.Enqueue(28);
	pq.Enqueue(2);
	pq.Enqueue(40);

	pq.Dequeue(x);  // x = 56
	pq.Dequeue(y);  // y = 42
	pq.Dequeue(z);  // z = 40

	std::cout << x << " " << y << " " << z << std::endl;
	return 0;
}
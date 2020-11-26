// A: time stamp���� ū ����
// C
// ���� stack�� Push: O(1)
// ���� stack�� Pop: O(1)
// �켱���� ť�� ������ stack�� Push: O(N)
// �켱���� ť�� ������ stack�� Pop: O(1)
#include <iostream>
#include "PQStackType.h"

int main() {
	StackType<int> stack;
	int x, y, z;

	stack.Push(5);
	stack.Push(9);
	stack.Push(1);
	stack.Push(11);
	stack.Push(3);
	stack.Push(7);
	stack.Push(2);

	x = stack.Top();   // x = 11
	stack.Pop();
	y = stack.Top();   // y = 9
	stack.Pop();
	z = stack.Top();   // z = 7

	std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

	for (int i = 0; i < 3; i++) {
		stack.Pop();
		std::cout << stack.Top() << " ";
	}

	return 0;
}
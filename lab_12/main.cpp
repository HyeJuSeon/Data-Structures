#include <iostream>
#include "GraphType.h"


int main() {
	GraphType<const char*> graph;

	graph.AddVertex("dog");
	graph.AddVertex("cat");
	graph.AddVertex("animal");
	graph.AddVertex("vertebrate");
	graph.AddVertex("oyster");
	graph.AddVertex("shellfish");
	graph.AddVertex("invertebrate");
	graph.AddVertex("crab");
	graph.AddVertex("poodle");
	graph.AddVertex("monkey");
	graph.AddVertex("banana");
	graph.AddVertex("dalmatian");
	graph.AddVertex("dachshund");

	graph.AddEdge("vertebrate", "animal", 10);
	graph.AddEdge("invertebrate", "animal", 20);
	graph.AddEdge("dog", "vertebrate", 30);
	graph.AddEdge("cat", "vertebrate", 40);
	graph.AddEdge("monkey", "vertebrate", 50);
	graph.AddEdge("shellfish", "invertebrate", 60);
	graph.AddEdge("crab", "shellfish", 70);
	graph.AddEdge("oyster", "invertebrate", 80);
	graph.AddEdge("poodle", "dog", 90);
	graph.AddEdge("dalmatian", "dog", 100);
	graph.AddEdge("dachshund", "dog", 110);

	std::cout << "Weight of 'vertebrate to animal' is " << graph.WeightIs("vertebrate", "animal") << std::endl;
	std::cout << "Weight of 'poodle to dog' is " << graph.WeightIs("poodle", "dog") << std::endl;

	// 삭제되었을시 결과는 0 출력
	graph.DeleteEdge("poodle", "dog");
	std::cout << "Weight of poodle to dog is " << graph.WeightIs("poodle", "dog") << std::endl;
	
	// GetToVertices()함수 테스트
	std::cout << std::endl << "GetToVertices(dog, queue)" << std::endl;
	QueType<const char*> queue;
	graph.GetToVertices("dog", queue);
	while (!queue.IsEmpty()) {
		const char* item;
		queue.Dequeue(item);
		std::cout << item << std::endl;
	}

	// DepthFirstSearch함수 테스트
	std::cout << std::endl << std::endl;
	graph.DepthFirstSearch("dalmatian", "animal");
	std::cout << std::endl;

	// 엣지 증가, 함수 재테스트
	graph.AddVertex("apple");
	graph.DeleteEdge("dog", "vertebrate");
	graph.AddEdge("dog", "oyster", 200);
	graph.AddEdge("dog", "banana", 200);
	graph.AddEdge("dog", "apple", 200);
	std::cout << std::endl << std::endl;
	graph.DepthFirstSearch("dalmatian", "animal");
	std::cout << std::endl;

	return 0;

}
// Definition of class PQType, which represents the Priority Queue ADT
class FullPQ{};
class EmptyPQ{};
#include "SortedType.h"
template<class ItemType>
class PQType
{
public:
  PQType();          // parameterized class constructor
  ~PQType();            // class destructor
  
  void MakeEmpty();
  // Function: Initializes the queue to an empty state.
  // Post: Queue is empty.
  
  bool IsEmpty() const;
  // Function: Determines whether the queue is empty.
  // Post: Function value = (queue is empty)
  
  bool IsFull() const;
  // Function: Determines whether the queue is full.
  // Post: Function value = (queue is full)
  
  void Enqueue(int priority, ItemType newItem);
  // Function: Adds newItem to the rear of the queue.
  // Post: if (the priority queue is full) exception FullPQ is thrown;
  //       else newItem is in the queue.
  
  void Dequeue(ItemType& item);
  // Function: Removes element with highest priority from the queue
  // and returns it in item.
  // Post: If (the priority queue is empty) exception EmptyPQ is thrown;
  //       else highest priority element has been removed from queue.
  //       item is a copy of removed element.
  void Ordering(int** orderList, int M);
private:
  int length;
  SortedType<ItemType> linkedList;
  //int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType()
{
  length = linkedList.LengthIs();
}

template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
  length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
	linkedList.MakeEmpty();
}

template<class ItemType>
void PQType<ItemType>::Ordering(int** orderList, int M)
{
    // Input Your Code
    // You only need to write the code that changes the priority according to the orderlist.
    
    // orderList 조건에 맞게 우선순위 정렬
    int num1, num2;
    int pr1, pr2;
    for (int i = 0; i < M; i++) {
        num1 = orderList[i][0];
        num2 = orderList[i][1];
        pr1 = linkedList.GetPriority(num1);
        pr2 = linkedList.GetPriority(num2);
        if (pr1 < pr2) {
            linkedList.SwapPriority(num1, num2);
        }

        // 문제 번호 순서대로 정렬
        linkedList.ResetList();
        for (int i = 0; i < linkedList.LengthIs(); i++) {
            ItemType item;
            linkedList.GetNextItem(item);
            if (item == num2)
                continue;
            else if (num1 < item) {
                pr2 = linkedList.GetPriority(item);
                if (pr1 < pr2) {
                    linkedList.SwapPriority(num1, item);
                }
            }
        }
    }
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
{
  if (length == 0)
    throw EmptyPQ();
  else
  {
	
	linkedList.ResetList();
    linkedList.GetNextItem(item);
	linkedList.DeleteItem(item);
    length--;
  
  }
}

template<class ItemType>
void PQType<ItemType>::Enqueue(int priority, ItemType newItem)
// Post: newItem is in the queue.
{
  if (linkedList.IsFull())
    throw FullPQ();
  else
  {
    length++;
	linkedList.InsertItem(priority, newItem);
  }
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Returns true if the queue is full; false, otherwise.
{
  return linkedList.IsFull();
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Returns true if the queue is empty; false, otherwise.
{
  return length == 0;
}

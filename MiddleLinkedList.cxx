/*
Given a singly linked list,return the middle node of the linked list.
If the number of nodes in the linked list is even, return the second middle node.

*/


#include <iostream>
#include <string>
#include <vector>
#include "LinkedListNode.cpp"

struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	EduLinkedListNode * arbitrary_pointer;
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};

class EduLinkedList {
public:
	EduLinkedListNode* head;

	EduLinkedList() { head = nullptr; }
	EduLinkedList(EduLinkedListNode* h) {
		 head = h; 
	}

	void InsertAtHead(int data) {
		if (head == nullptr) {
			head = new EduLinkedListNode(data);
		} else {
			EduLinkedListNode* new_node = new EduLinkedListNode(data);
			new_node->next = head;
			head = new_node;
		}
	}

	void InsertAtTail(int data) {
		if (head == nullptr) {
			head = new EduLinkedListNode(data);
		} else {
			EduLinkedListNode* new_node = new EduLinkedListNode(data);
			EduLinkedListNode* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void CreateLinkedList(vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}
	
};

void TraverseLinkedList(EduLinkedListNode* head){
    EduLinkedListNode* current = head; 
    EduLinkedListNode* nxt = nullptr; 
    while (current != nullptr){
      cout << current->data << "-> ";
      nxt = current->next;
      current = nxt;
    }
}

// function for finding the middle node
EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){
  EduLinkedListNode* fast = head;
  EduLinkedListNode* slow = head;
  while(fast && (fast->next!=nullptr) ) {
    fast=fast->next->next;
    slow=slow->next;
  }
  
  return slow;
}

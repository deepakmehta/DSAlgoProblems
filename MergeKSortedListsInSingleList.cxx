/*
Given an array of k sorted linked lists, your task is to merge them into a single sorted list.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

	void CreateLinkedList(std::vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}
	
};

#include<queue>
struct cmp{
    bool operator()(EduLinkedListNode* a, EduLinkedListNode* b) const{
        if(a->data>b->data) return true;
            return false;
    }
};

EduLinkedListNode* MergeKLists(vector<EduLinkedList*> lists)
{
    priority_queue<EduLinkedListNode*,vector<EduLinkedListNode*>,cmp> mheap;
	for(auto x: lists){
        if (x->head) mheap.push(x->head);
    }
    EduLinkedListNode head(0);
    EduLinkedListNode* curr=&head;
    while(!mheap.empty()) {
        EduLinkedListNode* t=mheap.top();
        mheap.pop();
        if(t->next) mheap.push(t->next);
        t->next=nullptr;
        curr->next=t;
        curr=t;
    }
    return head.next;
}
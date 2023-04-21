/*
Given a singly linked list, swap every two adjacent nodes of the linked list. After the swap, return the head of the linked list.
Note: Solve the problem without modifying the values in the list’s nodes. In other words, only the nodes themselves can be changed.
*/



LinkedListNode* swapPairs(LinkedListNode* head) {
    if(!head|| !head->next) return head;

	LinkedListNode* temp=head;
    head=temp->next;
	temp->next=swapPairs(head->next);
	head->next=temp;

	return head;	
}


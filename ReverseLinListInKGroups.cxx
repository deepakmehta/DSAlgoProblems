/*
Given a linked list, reverse the nodes of the linked list k at a time and return the modified list.
Here, k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of
k , the nodes left in the end will remain in their original order.
You can’t alter the values of the linked list nodes. Only the nodes themselves may be changed.
Note: Use only o(1) extra memory space.
Constraints
  1<=k<=n<=500
  0<=node.value<=1000

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    // LinkedListNode() will be used to make a LinkedListNode type object.
    LinkedListNode(int d)
    {
        data = d;
        next = nullptr;
    }
};

// Template for the linked list
class EduLinkedList
{
public:
    LinkedListNode *head = new LinkedListNode(0);
    // EduLinkedList() will be used to make a EduLinkedList type object
    EduLinkedList() { head = nullptr; }
    EduLinkedList(LinkedListNode *h) { head = h; }
    // InsertNodeAtHead() method will insert a LinkedListNode at head
    // of a linked list.
    void InsertNodeAtHead(LinkedListNode *node)
    {
        if (head != nullptr)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
        }
    }
    // CreateLinkedList() method will create the linked list using the
    // given integer array with the help of InsertAthead method.
    void CreateLinkedList(std::vector<int> vec)
    {
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            LinkedListNode *node = new LinkedListNode(vec[i]);
            InsertNodeAtHead(node);
        }
    }
    // ToString() method will display the elements of linked list.
    std::string ToString()
    {
        std::string result = "[";
        LinkedListNode *temp = head;
        while (temp != nullptr)
        {
            result += std::to_string(temp->data);
            temp = temp->next;
            if (temp != nullptr)
            {
                result += ",";
            }
        }
        result += "]";
        return result;
    }
};

void TraverseLinkedList(LinkedListNode *head)
{
    LinkedListNode *current = head;
    LinkedListNode *nxt = nullptr;
    while (current != nullptr)
    {
        cout << current->data << "-> ";
        nxt = current->next;
        current = nxt;
    }
}

// ReverseLinkedList is our challenge function that will reverse
// the group of k nodes in the linked list
LinkedListNode *ReverseLinkedList(LinkedListNode *head, int k)
{

    LinkedListNode *prevhead = nullptr;
    LinkedListNode *prevtail = nullptr;
    // figure out the length of LinkList
    int len = 0;
    LinkedListNode *newhead = head;
    while (newhead)
    {
        len++;
        newhead = newhead->next;
    }

    int section = k;
    while (head)
    {
        if (len - section < 0)
        {
            // less number of nodes left
            if (prevtail)
            {
                prevtail->next = head;
                break;
            }
        }
        LinkedListNode *sectionhead = nullptr;
        LinkedListNode *sectiontail = nullptr;

        while (section-- && head)
        {

            if (!sectiontail)
                sectiontail = head;
            LinkedListNode *temp = head;
            head = head->next;
            temp->next = sectionhead;
            sectionhead = temp;
        }
        len -= k;
        if (prevtail)
        {
            prevtail->next = sectionhead;
        }
        prevtail = sectiontail;
        if (!prevhead)
            prevhead = sectionhead;
        //  head=head->next;
        section = k;
    }
    return prevhead;
}

int main()
{
    EduLinkedList list;
    list.CreateLinkedList({3, 4, 5, 6, 2, 8, 7, 2});
    LinkedListNode *newhead = ReverseLinkedList(list.head, 3);
    TraverseLinkedList(newhead);
    return 0;
}
/*
Given the head of a singly linked list, reverse the linked list and return its updated head.
Constraints:
 Let n be the number of elements in the list
  1<=n<500
  -5000<n.value<5000
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
    void CreateLinkedList(std::vector<int>vec)
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

/* void TraverseLinkedList(EduLinkedListNode *head)
{
    EduLinkedListNode *current = head;
    EduLinkedListNode *nxt = nullptr;
    while (current != nullptr)
    {
        cout << current->data << "-> ";
        nxt = current->next;
        current = nxt;
    }
} */

LinkedListNode *Reverse(LinkedListNode *head)
{
    LinkedListNode* r=nullptr;
    while(head!=nullptr) {
      LinkedListNode* temp = head;
      head= head->next;
      temp->next=r;
      r=temp;
    }
    return r;
}

int main()
{
    EduLinkedList list;

    list.CreateLinkedList({1, -2, 3, 4, -5, 4, 3, -2, 1});
    LinkedListNode* newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({-1, -5, -3, -7, -8, -6, -2});
    newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({-1, 2, -3, 4});
     newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({1, -1, -2, 3, -4, 5});
     newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({28, 21, 14, 7});
     newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({11, -12, 13, -14});
     newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
    list.CreateLinkedList({-10});
     newhead=Reverse(list.head);
    list.head=newhead;
    cout<<list.ToString()<<endl;
};
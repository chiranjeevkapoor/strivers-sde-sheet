#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data1, Node *next1)
    {
        this->data = data1;
        this->next = next1;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *rev(Node *head)
{
    Node *prev = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

void printLinkedList(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(8);

    cout << "Print original linked list\n";
    printLinkedList(head);

    head = rev(head);

    cout << "reversed linked list\n";

    printLinkedList(head);

    return 0;
}

#include <iostream>
#include"linked_list.h"
using namespace std;
void Insert_First(Node<int> **Pointerhead, int input)
{
    Node<int> *current = new Node<int>; // Allocating memory
    current->item = input;
    current->link = *Pointerhead;
    *Pointerhead = current;
}
void Insert_End(Node<int> **Pointerhead, int input)
{
    if (*Pointerhead == NULL)
    {
        Node<int> *current = new Node<int>;
        current->item = input;
        current->link = *Pointerhead;
        *Pointerhead = current;
    }
    else
    {
        Node<int> *new_node = new Node<int>;
        Node<int> *current = *Pointerhead;
        Node<int> *prev = *Pointerhead;
        while (current != NULL)
        {
            prev = current;
            current = current->link;
        }
        new_node->item = input;
        new_node->link = current;
        prev->link = new_node;
    }
}
void Insert(Node<int> **Pointerhead, int input, int position)
{
    Node<int> *current = new Node<int>;
    current->item = input;
    if (position == 1)
    {
        current->link = *Pointerhead;
        *Pointerhead = current;
    }
    else
    {
        Node<int> *next = *Pointerhead;
        for (int i = 0; i < position - 2; i++)
            next = next->link;
        current->link = next->link;
        next->link = current;
    }
}
void Print_List(Node<int> *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "\nThe list is ";
    Node<int> *current;
    current = head; // Pointing towards address contained in head
    while (current != NULL)
    {
        cout << current->item << "  ";
        current = current->link;
    }
    cout << "\n";
}
void Remove_First(Node<int> **Pointerhead)
{
    Node<int> *current = *Pointerhead;
    if (*Pointerhead == NULL)
        cout << "\nThe list is empty\n";
    else
    {
        *Pointerhead = current->link;
        delete current;
    }
}
void Remove(Node<int> **Pointerhead, int position)
{
    Node<int> *current = *Pointerhead;
    if (*Pointerhead == NULL)
        cout << "\nThe list is empty\n";
    else if (position == 1)
    {
        *Pointerhead = current->link;
        delete current;
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            current = current->link;
        }
        Node<int> *next = current->link;
        current->link = next->link;
        delete next;
    }
}
void Remove_Last(Node<int> **Pointerhead)
{
    Node<int> *current = *Pointerhead;
    if (*Pointerhead == NULL)
        cout << "\nThe list is empty\n";
    else
    {
        Node<int> *prev_2nd = current;
        Node<int> *prev = current;
        while (current != NULL)
        {
            prev_2nd = prev;         // least but one item address
            prev = current;          // last item address
            current = current->link; // current becomes null
        }
        prev_2nd->link = NULL;
        delete prev;
    }
}
void Reverse_List_Iteration(Node<int> **Pointerhead)
{
    Node<int> *current = *Pointerhead;
    Node<int> *prev = NULL;
    Node<int> *next;
    ;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *Pointerhead = prev;
}
void Reverse_Print_List_Recursion(Node<int> *head)
{
     if(head!=NULL)
    {
        Reverse_Print_List_Recursion(head->link);
        cout<<head->item<<" ";
    }
}
void Print_List_Recursion(Node<int> *head){
    if(head!=NULL)
    {
        cout<<head->item<<" ";
        Print_List_Recursion(head->link);
    }
}
void Reverse_List_Recursion(Node<int> **Pointerhead,Node<int> *Recursor)
{
    if(Recursor->link!=NULL)
    {
        Reverse_List_Recursion(Pointerhead,Recursor->link);
        Node<int> *Next =Recursor->link;
        Next->link=Recursor;
        Recursor->link=NULL;
    }
    else
    {
        *Pointerhead=Recursor;
    }
}



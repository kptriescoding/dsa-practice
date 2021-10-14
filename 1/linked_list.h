#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template <typename T>
struct Node
{
    T item;
    Node *link;
};
void Insert_First(Node<int> **Pointerhead, int input);
void Insert_End(Node<int> **Pointerhead, int input);
void Insert(Node<int> **Pointerhead, int input, int position);
void Print_List(Node<int> *head);
void Remove_First(Node<int> **Pointerhead);
void Remove(Node<int> **Pointerhead, int position);
void Remove_Last(Node<int> **Pointerhead);
void Reverse_List(Node<int> **Pointerhead);
void Reverse_Print_List_Recursion(Node<int> *head);
void Print_List_Recursion(Node<int> *head);
void Reverse_List_Recursion(Node<int> **Pointerhead,Node<int> *Recursor);
#endif

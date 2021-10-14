#include <iostream>
#include "linked_list.h"
using namespace std;
int main()
{
    Node<int> *head = NULL;

    Insert_First(&head, 1);
    Insert_First(&head, 2);
    Insert_First(&head, 3);
    Insert_First(&head, 4);
    Insert_First(&head, 5);
    Insert_First(&head, 6);
    Insert_First(&head, 7);
    Insert_First(&head, 8);
    Insert_First(&head, 9);
    Insert_First(&head, 10);
cout<<"\nThe list is: ";
   Reverse_Print_List_Recursion(head);
    Reverse_List_Recursion(&head,head);
    cout<<"\nThe list is: ";
    Print_List_Recursion(head);

}
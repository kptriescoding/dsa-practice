#include <iostream>
#include<conio.h>
using namespace std;
template <class T>
class dynamic_array
{
private:
    int max_size;
    int top = -1;
    T input;
    T *array;

public:
    dynamic_array()
    {
        max_size = 1;
        array = new T[max_size];
    }
    ~dynamic_array()
    {
    }
    void insert(int position)
    {
        cout << "\nWhat element would you like to push\n";
        cin >> input;

        if (top + 1 >= max_size)
        {
            if (max_size == 0)
                max_size = 1;
            else
                max_size *= max_size;
            T *temp_array = new T[max_size];
            for (int i = 0; i <= top; i++)
            {
                temp_array[i] = array[i];
            }
            delete[] array;
            array = new T[max_size];
            for (int i = 0; i <= top; i++)
            {
                array[i] = temp_array[i];
            }
            delete[] temp_array;
        }
        for (int i = top; i >= position-1; i--)
        {
            array[i + 1] = array[i];
        }
        top++;
        array[position-1] = input;
    }
    void insert()
    {
        cout << "\nWhat element would you like to insert\n";
        cin >> input;
        if (top + 1 > max_size)
        {
            if (max_size == 0)
                max_size = 1;
            else
                max_size *= max_size;
            T *temp_array = new T[max_size];
            for (int i = 0; i <= top; i++)
            {
                temp_array[i] = array[i];
            }
            delete[] array;
            array = new T[max_size];
            for (int i = 0; i <= top; i++)
            {
                array[i] = temp_array[i];
            }
            delete[] temp_array;
        }
        top++;
        array[top] = input;
    }
    void remove(int position)
    {
        if (top == 0)
            cout << "The array is empty";
        else
        {
            for (int i = position; i <= top; i++)
            {
                array[i] = array[i + 1];
            }
            top--;
        }
    }
    void remove()
    {
        bool flag = true;
        cout << "\nWhat element would you like to remove\n";
        cin >> input;
        for (int i = 0; i <= top; i++)
        {
            if (array[i] == input)
            {
                for (int j = i; j << top; j++)
                {
                    array[i] = array[j + 1];
                    flag = false;
                }
                top--;
            }
        }
        if (flag == false)
            cout << "\nElement not found\n";
    }
    int size()
    {
        return top + 1;
    }
    void list_array()
    {
        cout << "\nThe array is" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << " " << array[i] << " ";
        }
    }
    int position_check(int position)
    {
        while (position - 1 > top || position <= -1)
        {
            cout << "\nThe position is invalid.Please TRY AGAIN!!\n";
            cout << "\nNote that the top position is \n"
                 << top;
            cout << "\nEnter the position you want to enter the element\n";
            cin >> position;
        }
        return position;
    }
};
int main()
{
    dynamic_array<int> user_array;
    bool condition_check = true;
    char ch;
    while (condition_check)
    {
        system("cls");
        cout << "\nWhat would you like to do\n1.Push an Element\n2.Insert an element at a position\n";
        cout << "3.Remove an element in a postion\n4.Remove an element\n5.Get size of the array\n6.List the array\n7.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case '1':
            user_array.insert();
            break;
        case '2':
            int position;
            cout << "\nEnter the position you want to enter the element\n";
            cin >> position;
            position = user_array.position_check(position);
            user_array.insert(position);
            break;
        case '3':
            user_array.remove();
            break;
        case '4':
            cout << "\nEnter the position you want to enter the element\n";
            cin >> position;
            position = user_array.position_check(position);
            user_array.remove(position);
            break;
        case '5':
            cout << "\nThe size of the array is \n"
                 << user_array.size();
            break;
        case '6':
            cout << "\nThe size of the array is \n"
                 << user_array.size();
            user_array.list_array();
            break;
        case '7':
            condition_check = false;
            break;
        default:
            cout << "\nInvalid input\n";
        }
        cout<<"\nPress any key to continue\n";
        getch();
    }
}

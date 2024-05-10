#include <iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    node<T> *next, *prev;
};
template <class T>
class DLADT
{
    node<T> *first;

public:
    DLADT()
    {
        first = nullptr;
    }
    void insert(T a);
    bool remove(T a);
    int count();
    int valAtCenterNode();
    int removefromPosition(int index);
    void printForward();
    void printBackward();
    ~DLADT()
    {
        node<T> *temp = new node<T>;
        while (first != nullptr)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        delete first;
    }
};
template <typename T>
void DLADT<T>::insert(T a)
{
    node<T> *temp = new node<T>;
    temp->data = a;
    temp->next = temp->prev = NULL;

    if (first == NULL)
        first = temp;
    else
    {
        node<T> *curr = first;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        temp->prev = curr;
    }
}
template <typename T>
bool DLADT<T>::remove(T a)
{
    if (first == NULL)
        return false;

    node<T> *curr = first;
    while (curr != NULL)
    {
        if (curr->data == a)
            break;
        curr = curr->next;
    }
    if (curr == NULL)
        return false;
    if (curr == first)
    {
        first = first->next;

        first->prev = NULL;
    }
    else if (curr->next == NULL)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    else
    {
        curr->prev->next = curr->next;
    }
    delete curr;
    return true;
}
template <typename T>
int DLADT<T>::count()
{
    int count = 0;
    node<T> *curr = first;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
template <typename T>
void DLADT<T>::printForward()
{
    node<T> *temp = first;
    if (first == NULL)
        return;

    cout << first->data << " ";
    first = first->next;
    printForward();
    first = temp;
}
template <typename T>
void DLADT<T>::printBackward()
{
    node<T> *curr = first;
    while (curr->next != NULL)
        curr = curr->next;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}
template <typename T>
int DLADT<T>::valAtCenterNode()
{
    int size = count();
    node<T> *curr = first;
    for (int i = 0; i < size / 2; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
template <typename T>
int DLADT<T>::removefromPosition(int index)
{
    node<T> *curr = first;
    int size = count();
    if (index >= size || index < 0)
    {
        return 0;
    }
    if (index == 0)
    {
        first = first->next;
        first->prev = nullptr;
        delete curr;
        return 1;
    }
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    if (curr->next != nullptr)
    {
        curr->next->prev = curr->prev;
    }
    int t = curr->data;
    delete curr;
    return t;
}
int main()
{
    DLADT<int> L;
    for (int i = 0; i < 10; i++)
        L.insert(i * 2);
    cout << L.valAtCenterNode();
    cout << "\nRemoving:" << L.removefromPosition(6) << endl;
    cout << L.valAtCenterNode();
    cout << endl;
    if (L.remove(12))
        cout << "Removed";
    else
        cout << "No Removed";
    cout << endl;
    L.printBackward();
}
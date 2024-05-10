#include <iostream>
#include <cstring>

using namespace std;

struct record
{
    char first[20];
    char last[20];
    char tel[20];
    char roll_no[10];
};

template <typename T>
class DLRecordADT
{
    struct node
    {
        T data;
        node *next;
        node *prev;
    };
    node *first;
    node *last;

public:
    DLRecordADT()
    {
        first = nullptr;
        last = nullptr;
    }
    void insert(T data)
    {
        node *new_node = new node;
        new_node->data = data;
        new_node->next = nullptr;
        new_node->prev = last;
        if (last != nullptr)
        {
            last->next = new_node;
        }
        last = new_node;
        if (first == nullptr)
        {
            first = new_node;
        }
    }
    int stringCompare(char const *string1, char const *string2)
    {
        if (*string1 == '\0' && *string2 == '\0')
            return 0;
        else if (*string1 == *string2)
            return stringCompare(string1 + 1, string2 + 1);
        else if (*string1 > *string2)
            return 1;
        else
            return -1;
    }
    void remove_by_name(char *first_name, char *last_name)
    {
        if (first == NULL)
        {
            cout << "Record is Empyty" << endl;
        }
        else
        {
            node *curr = first;
            while (curr != nullptr)
            {
                if (stringCompare(curr->data.first, first_name) == 0 && stringCompare(curr->data.last, last_name) == 0)
                {
                    if (curr == first)
                    {
                        first = curr->next;
                    }
                    if (curr == last)
                    {
                        last = curr->prev;
                    }
                    if (curr->prev != nullptr)
                    {
                        curr->prev->next = curr->next;
                    }
                    if (curr->next != nullptr)
                    {
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    return;
                }
                curr = curr->next;
            }
            cout << "Record not found." << endl;
        }
    }
    void remove_by_tel(char *tel)
    {
        if (first == NULL)
        {
            cout << "Record is Empyty" << endl;
        }
        else
        {
            node *curr = first;
            while (curr != nullptr)
            {
                if (stringCompare(curr->data.tel, tel) == 0)
                {
                    if (curr == first)
                    {
                        first = curr->next;
                    }
                    if (curr == last)
                    {
                        last = curr->prev;
                    }
                    if (curr->prev != nullptr)
                    {
                        curr->prev->next = curr->next;
                    }
                    if (curr->next != nullptr)
                    {
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    return;
                }
                curr = curr->next;
            }
            cout << "Record not found." << endl;
        }
    }
    void search_by_tel(char *tel)
    {
        if (first == NULL)
        {
            cout << "Record is Empyty" << endl;
        }
        else
        {
            node *curr = first;
            while (curr != nullptr)
            {
                if (stringCompare(curr->data.tel, tel) == 0)
                {
                    cout << "Name: " << curr->data.first << " " << curr->data.last << endl;
                    cout << "Roll No: " << curr->data.roll_no << endl;
                    cout << "Telephone number: " << curr->data.tel << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "Record not found." << endl;
        }
    }

    void search_by_name(char *first_name, char *last_name)
    {
        if (first == NULL)
        {
            cout << "Record is Empyty" << endl;
        }
        else
        {
            node *curr = first;
            while (curr != nullptr)
            {
                if (stringCompare(curr->data.first, first_name) == 0 && stringCompare(curr->data.last, last_name) == 0)
                {
                    cout << "Name: " << curr->data.first << " " << curr->data.last << endl;
                    cout << "Roll No: " << curr->data.roll_no << endl;
                    cout << "Telephone number: " << curr->data.tel << endl;
                    return;
                }
                curr = curr->next;
            }
            cout << "Record not found." << endl;
        }
    }
    void print_records()
    {
        if (first == NULL)
        {
            cout << "Cannot Print any Record Because Record is Empty" << endl;
            return;
        }
        node *curr = first;
        while (curr != nullptr)
        {
            cout << "Name: " << curr->data.first << " " << curr->data.last << endl;
            cout << "Roll No: " << curr->data.roll_no << endl;
            cout << "Telephone number: " << curr->data.tel << endl;
            cout << "***********************************************" << endl;
            curr = curr->next;
        }
    }
};
int main()
{
    DLRecordADT<record> list;
    record r[100];
    record r1;
    int n;
    char ch;
    int i = 0;

    bool flag = true;

    while (flag)
    {
        cout << "1.  Enter a record" << endl;
        cout << "2.  Delete a record" << endl;
        cout << "      a.  By name" << endl
             << "      b.  By tel no. " << endl;
        cout << "3.  Search a Record " << endl;
        cout << "      a.  By name" << endl
             << "      b.  By tel no. " << endl;
        cout << "4.  Print record" << endl;
        cout << "5.  To exit" << endl;
        cout << "Enter a number: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter first name: ";
            cin >> r[i].first;
            cout << "Enter last name: ";
            cin >> r[i].last;
            cout << "Enter telephone number: ";
            cin >> r[i].tel;
            cout << "Enter roll number: ";
            cin >> r[i].roll_no;
            list.insert(r[i]);
            i++;
            break;
        case 2:
            cout << "a.  By name" << endl
                 << "b.  By tel no. " << endl;
            cout << "Enter Character: " << endl;
            cin >> ch;
            switch (ch)
            {
            case 'a':
                cout << "Enter first name: ";
                cin >> r1.first;
                cout << "Enter last name: ";
                cin >> r1.last;
                list.remove_by_name(r1.first, r1.last);
                break;

            case 'b':
                cout << "Enter tel no.: ";
                cin >> r1.tel;
                list.remove_by_tel(r1.tel);
                break;
            }
            break;
        case 3:
            cout << "a.  By name" << endl
                 << "b.  By tel no. " << endl;
            cout << "Enter Character: " << endl;
            cin >> ch;
            switch (ch)
            {
            case 'a':
                cout << "Enter first name: ";
                cin >> r1.first;
                cout << "Enter last name: ";
                cin >> r1.last;
                list.search_by_name(r1.first, r1.last);
                break;
            case 'b':
                cout << "Enter tel no.: ";
                cin >> r1.tel;
                list.search_by_tel(r1.tel);
                break;
            }
            break;
        case 4:
            list.print_records();
            break;
        case 5:
            flag = false;
            break;
        }
    }
}
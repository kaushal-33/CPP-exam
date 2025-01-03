#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr;
    int top, capacity, count;

public:
    Stack()
    {
        int size;
        cout << "Enter Stack Size : ";
        cin >> size;
        arr = new int[size];
        this->capacity = size;
        this->top = -1;
        this->count = 0;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push();
    void pop();
    void display();
    void isEmpty();
    void isFull();
    void getSize();
};

void Stack::push()
{
    if (count == capacity)
    {
        cout << "Stack is overflow....!\n";
        return;
    }
    int data;
    cout << "Enter data : ";
    cin >> data;
    top++;
    arr[top] = data;
    count++;
    cout << arr[top] << " is added successfully....!\n";
}

void Stack::pop()
{
    if (count == 0)
    {
        cout << "Stack is empty....!\n";
        return;
    }
    cout << arr[top] << " is removed....!\n";
    top--;
    count--;
}

void Stack::display()
{
    if (count == 0)
    {
        cout << "Stack is empty....!\n";
        return;
    }

    cout << "\n--------------Stack-Elements--------------\n";
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

void Stack::isEmpty()
{
    if (count == 0)
    {
        cout << "Stack is empty....!\n";
    }
    else
    {
        cout << "Stack is not empty....!\n";
    }
}
void Stack::isFull()
{
    if (count == capacity)
    {
        cout << "Stack is full...!\n";
    }
    else
    {
        cout << "Stack is not full...!\n";
    }
}

void Stack::getSize()
{
    if (count == 0)
    {
        cout << "Stack is empty....!\n";
        return;
    }

    cout << count << " out of " << capacity << endl;
}

int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "\nPress 1 to push (insert) an element\n";
        cout << "\nPress 2 to pop (remove) an element\n";
        cout << "\nPress 3 to view all elements\n";
        cout << "\nPress 4 to check if stack is empty\n";
        cout << "\nPress 5 to check if stack is full\n";
        cout << "\nPress 6 to view size\n";
        cout << "\nENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 6:
            s.getSize();
            break;
        case 0:
            cout << "PROGRAMME EXITED......\n";
            break;
        default:
            cout << "INVALID INPUT....!\n"
                 << "PLEASE TRY AGAIN\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
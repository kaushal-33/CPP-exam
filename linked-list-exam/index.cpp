#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *HEAD;
    int nodeCount;

    LinkedList()
    {
        HEAD = nullptr;
        nodeCount = 0;
    }
    void addAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (nodeCount == 0)
        {
            HEAD = newNode;
        }
        else
        {
            newNode->next = HEAD;
            HEAD = newNode;
        }
        cout << "New Node inserted successfully\n";
        nodeCount++;
    }
    void searchByData(int data)
    {
        if (nodeCount == 0)
        {
            cout << "List is Empty !\n";
            return;
        }

        Node *temp = HEAD;
        bool flag = false;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                flag = true;
                break;
            }
           

            temp = temp->next;
        }

        (flag == true) ? cout<<"found": cout<<"not found";
        
    }
    void deleteAtAny(int position)
    {
        if (nodeCount == 0)
        {
            cout << "List is Empty !\n";
            return;
        }
        Node *temp = HEAD;
        if (position == 0)
        {
            HEAD = temp->next;
            delete temp;
            temp = nullptr;
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            toDelete = nullptr;
        }

        nodeCount--;
        cout << "Node deleted...!\n";
    }

    void updateAtAny(int position, int data)
    {
        if (position < 0 || position > nodeCount)
        {
            cout << "Input position is out of bound..!\n";
            return;
        }

        if (nodeCount == 0)
        {
            cout << "List is Empty !\n";
            return;
        }
        Node *temp = HEAD;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
        cout << "New data updated successfully...!\n";
    }
    void viewList()
    {
        if (nodeCount == 0)
        {
            cout << "List is Empty !\n";
            return;
        }
        Node *temp = HEAD;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice;
    do
    {
        cout << "\n------------LINKED-LIST------------\n";
        cout << "Press 1 to add at beginning position\n";
        cout << "Press 2 to search by data\n";
        cout << "Press 3 to delete at any position\n";
        cout << "Press 4 to update at any position\n";
        cout << "Press 5 to view Linked List\n";
        cout << "Press 0 to exit the programme\n";
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data : ";
            cin >> data;
            list.addAtBeginning(data);
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter data : ";
            cin >> data;
            list.searchByData(data);
            break;
        }
        case 3:
        {
            int position;
            cout << "Enter position : ";
            cin >> position;
            list.deleteAtAny(position);
            break;
        }
        case 4:
        {
            int position, data;
            cout << "Enter Position : ";
            cin >> position;
            cout << "Enter data : ";
            cin >> data;
            list.updateAtAny(position, data);
            break;
        }
        case 5:
        {
            list.viewList();
            break;
        }
        case 0:
        {
            cout << "PROGRAMME EXITED......!\n";
            break;
        }

        default:
            cout << "Invalid Input....!\n"
                 << "Please try again\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &, int, int);
void merger(vector<int> &, int, int, int);
void display(vector<int> &);
int binarySearch(vector<int> &, int, int, int);

class Node
{
private:
    int data;
    Node *next;

public:
    Node() {}
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Linkedlist : public Node
{
private:
    Linkedlist *HEAD;
    int nodeCount;

public:
    Linkedlist()
    {
        HEAD = nullptr;
        nodeCount = 0;
    }

    void addAtStart(int data)
    {
        Node *newNode = new Node(data);
        
    }
};
int main()
{
    int choice;
    do
    {
        cout << "PRESS 1 FOR LINKED LIST : \n";
        cout << "PRESS 2 FOR SORTING : \n";
        cout << "PRESS 3 FOR BINARY SEARCH : \n";
        cout << "PRESS 0 TO EXIT THE PROGRAME : \n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Linkedlist list;
            int choice2;
            do
            {
                cout << "PRESS 1 TO ADD AT BEGINNING : ";
                cout << "PRESS 2 TO DELETE AT ANY POSITION : ";
                cout << "PRESS 3 TO UPDATE AT ANY POSITION : ";
                cout << "PRESS 4 TO VIEW LIST : ";
                cout << "ENTER YOUR CHOICE : ";
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    int data;
                    cout << "ENTER DATA : ";
                    cin >> data;
                    break;
                }

                default:
                    break;
                }
            } while (choice2 != 0);

            break;
        }
        case 2:
        {
            int size;
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> size;
            vector<int> arr(size);
            for (int &value : arr)
            {
                cout << "Enter value : ";
                cin >> value;
            }
            cout << "\n------BEFORE SORTING-------\n";
            display(arr);
            mergeSort(arr, 0, size - 1);
            cout << "\n------AFTER SORTING-------\n";
            display(arr);
            break;
        }
        case 3:
        {
            int size;
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> size;
            vector<int> arr(size);
            for (int &value : arr)
            {
                cout << "Enter value : ";
                cin >> value;
            }
            display(arr);
            mergeSort(arr, 0, size - 1);
            int key;
            cout << "ENTER VALUE TO SEARCH : ";
            cin >> key;
            int idx = binarySearch(arr, 0, size - 1, key);
            (idx == key) ? cout << key << " is founded....!\n" : cout << key << " is not founded....!\n";
            break;
        }
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}

void display(vector<int> &arr)
{
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merger(arr, low, mid, high);
}

void merger(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid and right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int binarySearch(vector<int> &arr, int low, int high, int key)
{
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, 0, mid, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}
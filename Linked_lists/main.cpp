#include "ll.h"
#include <iostream>
using namespace std;

int main()
{
    node *head = nullptr;
    int choice, data, index;

    do {
        cout << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. Remove a node" << endl;
        cout << "3. Search for a node" << endl;
        cout << "4. Reverse the list" << endl;
        cout << "5. Exit" << endl << endl;

        cin >> choice;

        switch(choice)
        {
            case 1: 
            {
                cout << "Enter value to insert: ";
                cin >> data;
                cout << "Enter index: ";
                cin >> index;
                insertNode(head, index, data);
                break;
            }
            case 2: 
            {
                cout << "Enter index to remove: ";
                cin >> index;
                deleteNode(head, index);
                break;
            }
            case 3: 
            {
                cout << "Enter value to search: ";
                cin >> data;

                node* temp = searchNode(head, data);

                if (temp != nullptr)  
                {
                    cout << data << " found at memory address " << temp << endl;
                }
                else
                {
                    cout << data << " not found in the list." << endl;
                }
                break;
            }
            case 4:
            {
                reverseList(head);
                cout << "List reversed." << endl;
                break;
            }
            case 5: 
            {
                cout << "Freeing memory and exiting..." << endl;
                while (head != nullptr) // Free all nodes before exiting
                {
                    deleteNode(head, 0);
                }
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
        displayList(head);
    } while (choice != 5);

    return 0;
}

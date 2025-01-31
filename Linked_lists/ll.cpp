#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if(index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            return;
        }
        else
        {
            newNode->next = walker->next;
            walker->next = newNode;
        }

    }
}

void deleteNode(node *&head, int index) 
{
    // Check if the list is empty
    if (head == nullptr)
    {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    // Case 1: Deleting the first node (index 0)
    if (index == 0)
    {
        node* temp = head;  // Store reference to the node being deleted
        head = head->next;   // Move head to the next node
        delete temp;         // Free the memory
        return;
    }

    // Case 2: Deleting a node at a specific index
    node* walker = head;
    int wIndex = 0;

    // Traverse to the node just before the one to be deleted
    while (walker->next != nullptr && wIndex < index - 1)
    {
        walker = walker->next;
        wIndex++;
    }

    // If index is out of bounds
    if (walker->next == nullptr)
    {
        cout << "Index is too large, can't delete." << endl;
        return;
    }

    // Remove the node
    node* temp = walker->next;  // Node to delete
    walker->next = walker->next->next;  // Skip the node
    delete temp;  // Free memory
}


void displayList(node *head) 
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data<<" ";
        walker = walker->next;
    }
    cout<<endl;

}


node* searchNode(node *head, int data)
{
    // Check if the list is empty
    if (head == nullptr)
    {
        cout << "List is empty, cannot search." << endl;
        return nullptr;
    }

    node* walker = head;  // Pointer to traverse the list
    int index = 0;  // Track index position

    // Traverse the linked list
    while (walker != nullptr)
    {
        if (walker->data == data)  // If data is found
        {
            cout << "Value " << data << " found at index " << index << "." << endl;
            return walker;  // Return the pointer to the node
        }
        walker = walker->next;  // Move to the next node
        index++;
    }

    // If value not found
    cout << "Value " << data << " not found in the list." << endl;
    return nullptr;
}


void reverseList(node *&head)
{
    // Check if the list is empty
    if (head == nullptr)
    {
        cout << "List is empty, nothing to reverse." << endl;
        return;
    }

    node* prev = nullptr;    // Previous node pointer
    node* current = head;    // Current node pointer
    node* next = nullptr;    // Next node pointer

    // Traverse the list and reverse pointers
    while (current != nullptr)
    {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev one step forward
        current = next;        // Move current one step forward
    }

    // Update head to the new first node
    head = prev;

    cout << "List has been reversed." << endl;
}





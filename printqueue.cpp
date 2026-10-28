//***********************************************************************
// Name:
// Linked-List Practice — Level 1
// File: printqueue.cpp
//
// Implements a printer waiting line using a singly linked list.
//***********************************************************************

#include "printqueue.h"

// Part 1: Set up an empty queue.
PrintQueue::PrintQueue()
{
    // TODO: Initialize head, tail, and count.
    head = nullptr;
    tail = nullptr;

    count = 0;          //  no jobs have been assigned
}

// Part 2: Report the number of waiting jobs.
int PrintQueue::size()
{
    // TODO: Return the correct value
    return count;

}

// Part 3: Add a job at the back.
// Adds the given job to the back of the queue.
// Assume job is not nullptr.

void PrintQueue::push(PrintJob* job)
{
    // TODO: Create a node and store the job's address.
    Node* new_node = new Node;
    new_node -> job = job;
    new_node -> next = nullptr;

    // TODO: Handle the empty-queue and nonempty-queue cases.
    if (head == nullptr)
    {
        head = new_node;     // means since there is no first node, we make the 
                             // new node the first node
    }
    else
    {
        tail->next = new_node;  //  Thise goes to the node that tail points to, and
    }                           //  sets its next member to the new node's address

    // TODO: Update the tail and count.
    tail = new_node;
    count++;
}

// Part 4: Inspect the front without removing it.
// Returns the address of the front job without removing it.
// Returns nullptr if the queue is empty.
PrintJob* PrintQueue::front()
{
    // TODO: Handle an empty queue.
    if (head == nullptr)
    {
        return nullptr;
    }
    // TODO: Return the address stored in the first node.
    return head->job;
}

// Part 5: Remove the front node.
// Removes the front node.
// If the queue is empty, does nothing.
// Does NOT delete the PrintJob object.
void PrintQueue::pop()
{
    // TODO: Handle an empty queue.
    if (head == nullptr)
    {
        return;
    }
    // TODO: Save the node being removed.
    Node* old_head = head;

    // TODO: Update the head.
    head = old_head->next;          //  Makes haed hold the address stored in the 
                                    //  first node's member.
    // TODO: Handle the case where the queue becomes empty.
    if (head == nullptr)
    {
        tail = nullptr;
    }
    // TODO: Delete the removed node and update count.
    delete old_head;
    count--;
}
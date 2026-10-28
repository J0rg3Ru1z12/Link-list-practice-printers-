#ifndef PRINTQUEUE_H
#define PRINTQUEUE_H

#include "printjob.h"

class PrintQueue
{
public:
    // Constructs an empty queue.
    PrintQueue();

    // Returns the number of jobs currently waiting.
    int size();

    // Adds the given job to the back of the queue.
    // Assume job is not nullptr.
    void push(PrintJob* job);

    // Returns the address of the front job without removing it.
    // Returns nullptr if the queue is empty.
    PrintJob* front();

    // Removes the front node.
    // If the queue is empty, does nothing.
    // Does NOT delete the PrintJob object.
    void pop();

private:
    class Node
    {
    public:
        // Address of the job stored in this node.
        PrintJob* job;

        // Address of the next node, or nullptr at the end.
        Node* next;
    };

    // Points to the oldest waiting job's node.
    Node* head;

    // Points to the newest waiting job's node.
    Node* tail;

    // Number of nodes currently in the queue.
    int count;
};

#endif
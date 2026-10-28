#include <iostream>
#include "printqueue.h"

using namespace std;

int failures = 0;

void check(bool condition, const char* description)
{
    if (condition)
    {
        cout << "PASS: " << description << '\n';
    }
    else
    {
        cout << "FAIL: " << description << '\n';
        ++failures;
    }
}

int main()
{
    // These jobs exist independently of the queue nodes.
    PrintJob essay("Essay.pdf", 4);
    PrintJob lab("LabReport.pdf", 8);
    PrintJob notes("Notes.pdf", 2);

    PrintQueue q;

    // Part A: A new queue must be empty.
    check(q.size() == 0, "A new queue has size 0");
    check(q.front() == nullptr, "An empty queue has no front");

    // Part B: Removing from an empty queue must be safe.
    q.pop();

    check(q.size() == 0, "Popping an empty queue keeps size 0");
    check(q.front() == nullptr, "Empty pop leaves no front");

    // Part C: Add the first job.
    q.push(&essay);

    check(q.size() == 1, "One job has been added");
    check(q.front() == &essay, "Essay is at the front");

    // Part D: Add more jobs.
    q.push(&lab);
    q.push(&notes);

    check(q.size() == 3, "Three jobs are waiting");
    check(q.front() == &essay, "Adding jobs does not change the front");

    // Part E: Looking at the front must not remove anything.
    PrintJob* first = q.front();

    check(first == &essay, "front returns the original job's address");
    check(q.size() == 3, "front does not change the size");

    // Part F: Jobs must leave in arrival order.
    q.pop();

    check(q.size() == 2, "One pop leaves two jobs");
    check(q.front() == &lab, "Lab report is now first");

    q.pop();

    check(q.size() == 1, "Two pops leave one job");
    check(q.front() == &notes, "Notes is now first");

    // Part G: Remove the last job.
    q.pop();

    check(q.size() == 0, "Removing the last job leaves size 0");
    check(q.front() == nullptr, "Removing the last job leaves no front");

    // Part H: The emptied queue must be reusable.
    q.push(&lab);
    q.push(&essay);

    check(q.size() == 2, "An emptied queue can accept new jobs");
    check(q.front() == &lab, "Reused queue has the correct front");

    q.pop();

    check(q.front() == &essay, "Reused queue preserves arrival order");

    q.pop();
    q.pop();

    check(q.size() == 0, "Extra pop after reuse is safe");
    check(q.front() == nullptr, "Queue finishes empty");

    // Part I: The original jobs must still exist.
    check(essay.document() == "Essay.pdf", "Essay object still exists");
    check(lab.pages() == 8, "Lab object still exists");
    check(notes.pages() == 2, "Notes object still exists");

    cout << '\n';

    if (failures == 0)
    {
        cout << "Level 1 complete: all tests passed.\n";
    }
    else
    {
        cout << failures << " test(s) failed.\n";
    }

    return failures == 0 ? 0 : 1;
}
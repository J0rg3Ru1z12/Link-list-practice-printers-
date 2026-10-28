#ifndef PRINTJOB_H
#define PRINTJOB_H

#include <string>

class PrintJob
{
public:
    // Creates a job with a document name and page count.
    PrintJob(std::string document, int pages);

    // Returns the document's name.
    std::string document();

    // Returns the number of pages.
    int pages();

private:
    std::string _document;
    int _pages;
};

#endif
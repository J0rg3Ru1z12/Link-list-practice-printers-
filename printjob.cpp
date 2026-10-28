#include "printjob.h"

PrintJob::PrintJob(std::string document, int pages)
{
    _document = document;
    _pages = pages;
}

std::string PrintJob::document()
{
    return _document;
}

int PrintJob::pages()
{
    return _pages;
}
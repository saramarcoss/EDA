#ifndef PRINTJOB_H
#define PRINTJOB_H
#include <iostream>
using namespace std;

class PrintJob {
    public:
        PrintJob(int timestamp, int pages, const std::string& title);
        int getPages() const;
        bool operator<(const PrintJob& other) const;
        bool operator>(const PrintJob& other) const;
        bool operator==(const PrintJob& other) const;
        friend std::ostream& operator<<(std::ostream& os, const PrintJob& job);
    private:
        int nPages;
        int timestamp;
        std::string title;
};

std::ostream& operator<<(std::ostream& os, const PrintJob& job);

#endif // PRINTJOB_H

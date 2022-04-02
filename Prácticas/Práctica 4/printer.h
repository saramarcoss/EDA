#ifndef PRINTER_H
#define PRINTER_H
#include "printjob.h"
#include <vector>

class Printer {
    public:
        Printer(int maxNumJobs, int maxNumPages);

        int queueLength() const;
        int queuePages() const;
        bool isEmpty() const;
        bool isFull() const;

        PrintJob next();
        bool push(const PrintJob& dato, bool force = false);

        int getMaxNumPages() const{
            return _maxNumPages;
        }
        void setMaxNumPages(int value){
            _maxNumPages = value;
        }


private:
        vector<PrintJob> v1;
        int _maxNumJobs;
        int _maxNumPages;

        int plusPages;
        int plusJobs;
};




#endif // PRINTER_H

#include "printjob.h"



PrintJob::PrintJob(int timestamp, int pages, const string &title):timestamp{timestamp}, nPages{pages},title{title} {}

int PrintJob::getPages() const
{
    return nPages;
}

bool PrintJob::operator<(const PrintJob & other) const
{
    if(nPages < other.getPages()){
        return true;
    }else if(nPages == other.getPages()){
        if(timestamp < other.timestamp){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

bool PrintJob::operator>(const PrintJob &other) const
{
    if(nPages > other.getPages()){
        return true;
    }else if(nPages == other.getPages()){
        if(timestamp > other.timestamp){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

bool PrintJob::operator==(const PrintJob &other) const
{
    if(nPages == other.getPages() && timestamp == other.timestamp){
        return true;
    }else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const PrintJob& job){
    os << "title: " << job.title << " " << "pages: " << job.nPages << " " << "time: " <<  job.timestamp << endl;
    return os;
}

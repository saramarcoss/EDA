#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>


class Client {
public:
    Client();
    Client(int _max, int _min);
    int time_to_pay=max-min;

    protected:
    int min;
    int max;
};


#endif // CLIENT_H

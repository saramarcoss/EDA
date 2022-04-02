#include "client.h"

Client::Client()
{
    time_to_pay = std::rand() % 100;
}

Client::Client(int _max, int _min)
{
    max=_max;
    min=_min;
    time_to_pay= _min+rand() % (_max - _min);
}

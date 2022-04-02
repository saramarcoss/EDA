#include "police.h"

#include <algorithm>

Queue police_raid(Queue joy_slava, const std::vector<std::string>& dnis) {
    Queue ret;
    while (!joy_slava.empty()) {
        auto next = joy_slava.front();
        joy_slava.pop();
        if (find(dnis.begin(), dnis.end(), next.get_dni()) == dnis.end()) {
            ret.push(next);
        }
    }
    return ret;
}

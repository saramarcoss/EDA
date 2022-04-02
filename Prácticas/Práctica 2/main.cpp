#include <iostream>
#include "wardrobe.h"
#include "queue.h"
#include "police.h"

//1

int main() {

    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(Persona{"Manuel", "dni-manuel", 0});
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    joy_eslava.push(Persona{"Miguel", "dni-miguel", 0});
    joy_eslava.push(Persona{"Samuel", "dni-samuel", 0});
    joy_eslava.push(Persona{"Raquel", "dni-raquel", 1});

    std::vector<std::string> dnis{"dni-manuel", "dni-raquel", "dni-isabel"};
    auto filtered = police_raid(joy_eslava, dnis);

    std::cout << "Joy Slava, people waiting: " << filtered.size() << std::endl;
    while (!filtered.empty()) {
        auto person = filtered.front();
        filtered.pop();
        std::cout << person.get_name() << std::endl;
    }

    // Create the queue for the disco
    Wardrobe men;
    Wardrobe women;
    wardrobe(joy_eslava, men, women);

    std::cout << "Wardrobe men:" << std::endl;
    while (!men.empty()) {
        std::cout << men.top() << std::endl;
        men.pop();
    }

    std::cout << "Wardrobe women:" << std::endl;
    while (!women.empty()) {
        std::cout << women.top() << std::endl;
        women.pop();
    }
    // Manuel is going today to Joy Slava, he is waiting for some friends
    Persona manuel{"Manuel", "dni-manuel", 0};

    // Create the queue for the disco
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(manuel);
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    // ...

    // Create the queue with Manuel's friends
    Queue friends;
    friends.push(Persona{"Miguel", "dni-miguel", 0});
    friends.push(Persona{"Samuel", "dni-samuel", 0});
    friends.push(Persona{"Raquel", "dni-raquel", 1});

    // Sneak in
    joy_eslava.sneak_in(manuel, friends);

    // Check the queue is the expected one: print size and names
    std::cout << "Joy Slava, people waiting: " << joy_eslava.size() << std::endl;
    while (!joy_eslava.empty()) {
        auto person = joy_eslava.front();
        joy_eslava.pop();
        std::cout << person.get_name() << std::endl;
    }
}


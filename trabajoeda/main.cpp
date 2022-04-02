#include <iostream>
#include <fstream>
#include<array>
#include"client.h"
#include"queue.h"
using namespace std;

void add_new_client_shortest_lane(std::array<Queue, 4>& lanes) {
    // Creates a new client and add it to the shortest queue
    Client client{};
    int shortest_idx = 0;
    for (int i=0; i<lanes.size(); i++) {
        if (lanes[i].size() < lanes[shortest_idx].size()) {
            shortest_idx = i;
        }
    }
    // Push client to the shortest queue
    lanes[shortest_idx].push(client);
}
void add_new_client_aleatory_lane(std::array<Queue, 4>& lanes) {
    Client client{};
    int n=std::rand() % 3;
    lanes[n].push(client);
}

auto print=[](Client const & c){
    cout<<c.time_to_pay<<"\n";
};
int main()
{

    Queue cola1;
        array<Queue,4>l;
        Client c;
        add_new_client_shortest_lane(l);
        add_new_client_shortest_lane(l);
        add_new_client_aleatory_lane(l);
        add_new_client_shortest_lane(l);
        add_new_client_aleatory_lane(l);
        for(auto elem:l){
            elem.foreach(print);
        }
        c.time_to_pay=22;
        cola1.push(c);
        cola1.foreach(print);

    //Una cola por caja

        ofstream data;
        data.open("output.txt");

        cout << "Introduce segundos maximos para la generacion de nuevo cliente: ";
        int max; cin >> max;

        cout << "Introduce segundos minimos para la generacion de nuevo cliente: ";
        int min; cin >> min;
        int time_new_client = min+rand() % (max - min);

        cout << endl;

        cout << "Quiere que se añada a la cola de forma aleatoria o a la cola mas corta?: 1.Aleatorio o 2.Cola mas corta: ";
        int opcion; cin >> opcion;

        int segundos = 0;
        array<Queue, 4> lanes;
        while (segundos < 10000) {
            for (auto& lane: lanes) {
                if (!lane.empty()) {
                    auto& front_client = lane.front();
                    front_client.time_to_pay--;
                    if (front_client.time_to_pay <= 0) {
                        lane.pop();
                    }
                }
            }

            if (segundos % time_new_client == 0) {

                if(opcion == 1){
                    add_new_client_aleatory_lane(lanes);
                }else{
                    add_new_client_shortest_lane(lanes);
                }
            }
            int total = 0;
            data << segundos << " ";
            for (auto & lane: lanes) {
                data << lane.size() << " ";
                total += lane.size();
            }
            data << total << endl;
            segundos += 1;
        }
        data.close();

        //Sistema de cola unica

        array<Client, 4> cajas;
        int segundos2 = 0;
        Queue clientes;
        while(segundos2 < 10000){
            for (int i=0; i<cajas.size(); i++) {
                cajas.at(i).time_to_pay--;
                if (cajas.at(i).time_to_pay <= 0) {
                    if (!clientes.empty()) {
                        auto front_client = clientes.front();
                        clientes.pop();
                        cajas.at(i) = front_client;
                    }
                }
            }
            if(segundos2 % time_new_client == 0){
                clientes.push(Client{});
            }

            segundos2 += 1;
        }

    }




#include <iostream>
#include<memory>
#include<vector>
#include<functional>
#include"persona.h"
using namespace std;
shared_ptr<Persona>find(vector<shared_ptr<Persona>>ve,function<bool(shared_ptr<Persona>p)>f){
    for(auto elem:ve){
     if(f(elem)) return elem;
    }
    return nullptr;
};
auto namesara=[](shared_ptr<Persona>p){
    return p->getNombre()=="sara";
};
int main()
{
   string nombre,dni,telefono;
   int annaci;
   shared_ptr<Persona>p;
   vector<shared_ptr<Persona>>v;
   for(int i=0;i<2;i++){
        cout<<"Introduce el nombre:\n";
        cin>>nombre;
        cout<<"Introduce la edad:\n";
        cin>>annaci;
        cout<<"introduce el dni\n";
        cin>>dni;
        cout<<"Introduce el telefono\n";
        cin>>telefono;
        p=make_shared<Persona>(Persona{nombre,annaci,dni,telefono});
        v.push_back(p);
   }

   cout<<find(v,namesara)<<"\n";
   for(auto elem:v){
      elem->print();
   }
}

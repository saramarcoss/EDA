#include "printer.h"

Printer::Printer(int maxNumJobs, int maxNumPages){
    maxNumJobs = _maxNumJobs;
    maxNumPages = _maxNumPages;
}

int Printer::queueLength() const
{
    return v1.size();
}

int Printer::queuePages() const
{
    int contador;
    for(int i=0; i<v1.size(); i++){
        contador = contador + v1.at(i).getPages();
    }
    return contador;
}

bool Printer::isEmpty() const
{
    if(v1.empty()){
        return true;
    }else{
        return false;
    }
}

bool Printer::isFull() const
{
    if(_maxNumJobs == v1.size() || _maxNumPages == queueLength()){
        return true;
    }else{
        return false;
    }
}

PrintJob Printer::next()
{
    string a = " ";
    int contador = 0;
    int borrador = 0;
    PrintJob ej{9999999,9999999, a};
    for(auto elem: v1){
        if(elem < ej){
            ej = elem;
            borrador = contador;
        }
        contador++;
    }
    v1.erase(v1.begin()+borrador);
    return ej;
}

bool Printer::push(const PrintJob &dato, bool force){
    if(force==true){
        if(queuePages()+ dato.getPages()< _maxNumPages||v1.size()<=_maxNumJobs){
           v1.push_back(dato);
           return true;
        }else{
            std::string s=" ";
            int cont=0;
            int borrar=0;
            PrintJob pj{0,0,s};
            for (auto elem:v1){
                if(elem>pj){
                    pj=elem;
                    borrar=cont;
                }
                cont++;
            }
            v1.erase (v1.begin()+borrar);
            v1.push_back(dato);
            return true;
        }
    }else{
        if(queuePages() + dato.getPages() < _maxNumPages || v1.size()+1 <= _maxNumJobs){
           v1.push_back(dato);
           return true;
        }
    }
    return false;
}

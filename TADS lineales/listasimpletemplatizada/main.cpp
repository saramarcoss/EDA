#include <iostream>
#include<memory>
#include<functional>
using namespace std;
template<typename T>
class Elem{

public:
 Elem(T const & elem);
 T getData()const;

 void push_back(T const & e);
 void for_each(function<void(T const & t)>f);
 shared_ptr<Elem<T>> getnext()const;
 shared_ptr< Elem<T>> setnext(shared_ptr<Elem<T>>n);

private:
 T elem;// dato
 shared_ptr<Elem<T>>next;// puntero al siguiente
};
template <typename T>
Elem<T>::Elem(T const & elem):elem{elem}{
    next=nullptr;
}

template<typename T>
T Elem<T>::getData() const
{
    return elem;
}

template<typename T>
void Elem<T>::push_back(const T &e)
{
 if(next==nullptr){
     next=make_shared<Elem<T>>(e);
 }else{
     next->push_back(e);
 }
}

/*template<typename T>
void Elem<T>::for_each(function<void(T const & t)>f){
    while(next!=nullptr){
      f(elem);
    }
}*/

template<typename T>
shared_ptr<Elem<T> > Elem<T>::getnext() const
{
    return next;
}

template<typename T>
shared_ptr< Elem<T>>Elem<T>::setnext(shared_ptr<Elem<T> > n)
{
    next=n;
    return next;
}
template<typename T>
void print(Elem<T>e){
    cout<<e.getData()<<"\n";
    if(e.getnext()){
        print<T>(*(e.getnext()));
    }
}
template<typename T>
class Elemdoble{
public:
 Elemdoble(T const & elem);
 T getData()const;


 void push_back(T const & e);
 shared_ptr<Elemdoble<T>> getnext()const;
 shared_ptr<Elemdoble<T>> getlast()const;
 shared_ptr< Elemdoble<T>> setnext(shared_ptr<Elemdoble<T>>n);

 shared_ptr<Elemdoble<T>> getprev()const;
 shared_ptr< Elemdoble<T>> setprev(shared_ptr<Elemdoble<T>>n);
private:

 T elem;// dato
 shared_ptr<Elemdoble<T>>next;// puntero al siguiente
 shared_ptr<Elemdoble<T>>prev;
};
template <typename T>
Elemdoble<T>::Elemdoble(T const & elem):elem{elem}{
    next=nullptr;
}

template<typename T>
T Elemdoble<T>::getData() const
{
    return elem;
}

template<typename T>
void Elemdoble<T>::push_back(const T &e)
{
 if(next==nullptr){
     next=make_shared<Elemdoble<T>>(e);
 }else{
     next->push_back(e);
 }
}

template<typename T>
shared_ptr<Elemdoble<T>> Elemdoble<T>::getnext() const
{
    return next;
}
template<typename T>
shared_ptr<Elemdoble<T>> Elemdoble<T>::getlast() const
{
    auto iterator=next;
    while(iterator!=nullptr){
        iterator=iterator->next;
    }
    return iterator;
}

template<typename T>
shared_ptr< Elemdoble<T>>Elemdoble<T>::setnext(shared_ptr<Elemdoble<T> > n)
{
    next=n;
    return next;
}
template<typename T>
shared_ptr<Elemdoble<T>> Elemdoble<T>::getprev() const
{
    return prev;
}



template<typename T>
shared_ptr< Elemdoble<T>>Elemdoble<T>::setprev(shared_ptr<Elemdoble<T> > n)
{
    prev=n;
    return prev;
}
template<typename T>
void print(Elemdoble<T>e){
    cout<<e.getData()<<"\n";
    if(e.getnext()){
        print<T>(*(e.getnext()));
    }
}
template<typename T>
void print_reverse(Elemdoble<T>e){
    auto last=e.getlast();
    cout<<last<<"\n";
    if(e.getprev()){
        print_reverse<T>(*(e.getprev()));
    }

}

template<typename T>
void print_reverse1(Elemdoble<T>e){


}

auto print1=[](int n){
    cout<<n<<"\n";
};
int main()
{
    /*Elem<int>lista2=Elem<int>{1};//voy añadiendo elementos
    auto last=lista2.setnext(make_shared<Elem<int>>(2));
    last=lista2.setnext(make_shared<Elem<int>>(3));
    last=lista2.setnext(make_shared<Elem<int>>(4));*/
    Elem<int>lista1=Elem<int>{1};
    lista1.push_back(2);
    lista1.push_back(3);
    print(lista1);

    Elemdoble<int>lista=Elemdoble<int>{1};
    lista.push_back(2);
    lista.push_back(3);
    print(lista);
    cout<<"reverse: \n";
    print_reverse(lista);
    cout<<"ggg";
}

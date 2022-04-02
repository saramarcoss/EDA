#include <iostream>
#include"tree.h"
#include"TipoDato.h"
#include<functional>
using namespace std;

int main()
{
    TipoDato w;
    w.dato="hola";
    Tree arbol(w);
    TipoDato i;
    i.dato="holi";
    Tree tree(i);
    arbol.add_subtree(tree);
    TipoDato o;
    o.dato="hol";
    Tree arbolito(o);
    arbol.add_subtree(arbolito);

   cout<<arbol.height()<<"\n";
   cout<<arbol.size()<<"\n";

   auto print=[](TipoDato & data){
       cout<<data.dato<<"\n";
   };
   arbol.dfs_preorder(print);
   cout<<"\n";
   arbol.dfs_postorder(print);
   cout<<"\n";
   arbol.dfs_inorder(print);
}

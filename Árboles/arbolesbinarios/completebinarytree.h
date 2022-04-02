#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H
#include"TipoDato.h"
#include<functional>
#include<vector>

class CompleteBinaryTree
{
public:
       CompleteBinaryTree();

       int height() const;
       int size() const;

       void push(const TipoDato& dato); // Adds element at the end

       void bfs(std::function<void (TipoDato&)> action) const; // Trivial
   protected:
       std::vector<TipoDato> _data;
};
#endif // COMPLETEBINARYTREE_H

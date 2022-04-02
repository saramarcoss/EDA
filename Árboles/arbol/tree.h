#ifndef TREE_H
#define TREE_H
#include"elementoarbol.h"
#include<iostream>
#include<functional>

class Tree {
    private:
        shared_ptr<ElementoArbol> root = nullptr;

    public:
        Tree();  // Creates empty tree
        Tree(const TipoDato& dato);  // Creates tree with root node

        // Member functions (properties of the tree structure)
        int height() const;
        int size() const; // Returns number of nodes

        // A way to add subtrees to an existing tree
        void add_subtree(const Tree& subtree);
        void dfs_preorder(function<void (TipoDato&)> action) const;
        void dfs_postorder(function<void (TipoDato&)> action) const;
        void dfs_inorder(function<void (TipoDato&)> action) const;
        void bfs(function<void (TipoDato&)> action) const;

};

#endif // TREE_H

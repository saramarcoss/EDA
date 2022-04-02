#ifndef BINARYTREE_H
#define BINARYTREE_H
#include"elementoarbolbinario.h"


class BinaryTree
{
private:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        BinaryTree();  // Creates empty tree
        BinaryTree(const TipoDato& dato);  // Creates tree with root node

        // Member functions (properties of the tree structure)
        int height() const;
        int size() const; // Returns number of nodes

        // A way to add subtrees to an existing tree
        void add_left_subtree(const BinaryTree& subtree);
        void add_right_subtree(const BinaryTree& subtree);
};
#endif // BINARYTREE_H

#include "binarytree.h"
#include"elementoarbolbinario.h"
#include"completebinarytree.h"
// Constructor for an empty tree
BinaryTree::BinaryTree() {}

// Constructor for a tree with the root node
BinaryTree::BinaryTree(const TipoDato& dato) {
    root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

void BinaryTree::add_left_subtree(const BinaryTree& subtree) {
    root->left = subtree.root;
}

void BinaryTree::add_right_subtree(const BinaryTree& subtree) {
    root->right = subtree.root;
}
int _height(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return -1;
    }
    else {
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + std::max(height_left, height_right);
    }
}

int BinaryTree::height() const {
    return _height(root);
}
int _size(std::shared_ptr<ElementoArbolBinario> element) {
    if (element == nullptr) {
        return 0;
    }
    else {
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int BinaryTree::size() const {
    return _size(root);
}
/*void _dfs_preorder(const CompleteBinaryTree& tree,
                   int idx_node,
                   std::function<void (const TipoDato&)> action) {
    if (idx_node == -1) {
        return;
    }

    action(tree.at(idx_node));

    int left_idx = tree.left(idx_node);
    _dfs_preorder(tree, left_idx, action);

    int right_idx = tree.right(idx_node);
    _dfs_preorder(tree, right_idx, action);
}

void CompleteBinaryTree::dfs_preorder(std::function<void (const TipoDato&)> action) const {
    if (this->empty()) {
        return;
    }
    else {
        // Start recursion from the root node (idx=0)
        _dfs_preorder(*this, 0, action);
    }
}*/

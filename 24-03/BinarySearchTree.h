#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stdexcept>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    TreeNode *root;

    BinarySearchTree() : root(nullptr) {}

    // Rekurencyjne metody

    // Rekurencyjne wstawianie wartości
    void insertRec(int val)
    {
        root = insertRecHelper(root, val);
    }

    TreeNode *insertRecHelper(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->value)
        {
            node->left = insertRecHelper(node->left, val);
        }
        else
        {
            node->right = insertRecHelper(node->right, val);
        }
        return node;
    }

    // Rekurencyjne wyszukiwanie wartości
    bool searchRec(int val)
    {
        return searchRecHelper(root, val);
    }

    bool searchRecHelper(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->value == val)
        {
            return true;
        }
        return val < node->value ? searchRecHelper(node->left, val) : searchRecHelper(node->right, val);
    }

    // Rekurencyjne znajdowanie wartości minimalnej
    int findMinRec()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Drzewo jest puste");
        }
        return findMinRecHelper(root);
    }

    int findMinRecHelper(TreeNode *node)
    {
        if (node->left == nullptr)
        {
            return node->value;
        }
        return findMinRecHelper(node->left);
    }

    // Rekurecyjne znajdowanie wartości maksymalnej
    int findMaxRec()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Drzewo jest puste");
        }
        return findMaxRecHelper(root);
    }

    int findMaxRecHelper(TreeNode *node)
    {
        if (node->right == nullptr)
        {
            return node->value;
        }
        return findMaxRecHelper(node->right);
    }

    // Rekurecyjne usuwanie węzła
    void removeRec(int val)
    {
        root = removeRecHelper(root, val);
    }

    TreeNode *removeRecHelper(TreeNode *node, int val)
    {
        if (node == nullptr)
            return node;

        if (val < node->value)
        {
            node->left = removeRecHelper(node->left, val);
        }
        else if (val > node->value)
        {
            node->right = removeRecHelper(node->right, val);
        }
        else
        {
            // Węzeł z jednym dzieckiem lub bez dziecka
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            // Węzeł z dwoma dziećmi: Znajdź kolejne w porządku posortowanym
            TreeNode *temp = findMinNode(node->right);
            node->value = temp->value;
            node->right = removeRecHelper(node->right, temp->value);
        }
        return node;
    }

    TreeNode *findMinNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // Iteracyjne metody

    // Iteracyjne wstawianie wartości
    void insert(int val)
    {
        TreeNode *newNode = new TreeNode(val);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        TreeNode *current = root;
        TreeNode *parent = nullptr;
        while (current != nullptr)
        {
            parent = current;
            if (val < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if (val < parent->value)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    // Iteracyjne wyszukiwanie wartości
    bool search(int val)
    {
        TreeNode *current = root;
        while (current != nullptr)
        {
            if (current->value == val)
            {
                return true;
            }
            current = val < current->value ? current->left : current->right;
        }
        return false;
    }

    // Iteracyjne znajdowanie wartości minimalnej
    int findMin()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Drzewo jest puste");
        }
        TreeNode *current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current->value;
    }

    // Iteracyjne znajdowanie wartości maksymalnej
    int findMax()
    {
        if (root == nullptr)
        {
            throw std::runtime_error("Drzewo jest puste");
        }
        TreeNode *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current->value;
    }

    // Iteracyjne usuwanie węzła
    void remove(int val)
    {
        TreeNode *current = root;
        TreeNode *parent = nullptr;
        while (current != nullptr && current->value != val)
        {
            parent = current;
            current = val < current->value ? current->left : current->right;
        }
        if (current == nullptr)
            return; // Element nie znaleziony

        // Węzeł z dwoma dziećmi
        if (current->left != nullptr && current->right != nullptr)
        {
            TreeNode *successor = findMinNode(current->right);
            int successorVal = successor->value;
            remove(successorVal);
            current->value = successorVal;
        }
        else
        {
            TreeNode *temp = current->left ? current->left : current->right;
            if (parent == nullptr)
            {
                root = temp;
            }
            else if (parent->left == current)
            {
                parent->left = temp;
            }
            else
            {
                parent->right = temp;
            }
            delete current;
        }
    }
};

#endif // BINARY_SEARCH_TREE_H

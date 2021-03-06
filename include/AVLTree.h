#ifndef BTREE_H
#define BTREE_H

#include <algorithm>

class AVLTree{
    public:
        AVLTree();
        ~AVLTree();


        void printTreePre();
        void printTreePost();
        void printTreeIn();
        void displayTree();
        int max();
        int min();
        int height();
        int numNodes();
        int numLeafs();

        void deleteTree();
        void insert(int _value);
        bool search(int _value);
        bool remove(int _value);
        bool isBalanced();

    private:
        /**
        *   Node: Contains a value and two children (left child and right child).
        */
        struct Node {
            int value;
            int height;
            Node* left;
            Node* right;

            // constructor sets value to 0 if no parameter is given
            Node(int _value) : value(0){
                value = _value;
                height = 1;
                left = NULL;
                right = NULL;
            }
        };

        Node* root;

        void printTreePre(Node* _root);
        void printTreePost(Node* _root);
        void printTreeIn(Node* _root);
        void displayTree(Node* _root, int depth);
        Node* max(Node* _root);
        Node* min(Node* _root);
        int countNodes(Node* _root);
        int countLeafs(Node* _root);



        void deleteTree(Node* _leaf);
        Node* insert(int _value, Node* _node);
        Node* search(int _value, Node* _root);
        Node* remove(int _value, Node* _root);
        Node* removeMin(Node* _root);
        Node* balance(Node* _node);
        Node* rotateRight(Node* _node);
        Node* rotateLeft(Node* _node);

        int minDepth(Node* _root);
        int maxDepth(Node* _root);



        int getHeight(Node* _root);

        int getBalance(Node* _root);

};

#endif // BTREE_H

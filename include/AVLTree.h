#ifndef BTREE_H
#define BTREE_H

#include <algorithm>

class AVLTree{
    public:
        AVLTree();
        ~AVLTree();

        void deleteTree();
        void insert(int _value);
        bool isBalanced();

        void printTreePre();
        void printTreePost();
        void printTreeIn();

        int max();
        int min();
        int height();
        int numNodes();
        int numLeafs();

    private:
        /**
        *   Node: Contains a value and two children (left child and right child).
        */
        struct Node {
            int value;
            int height; //Height of NULL nodes is 0
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

        void deleteTree(Node* _leaf);
        void insert(int _value, Node* _node);
        void fixHeight(Node* _root);

        void printTreePre(Node* _root);
        void printTreePost(Node* _root);
        void printTreeIn(Node* _root);

        void rotateRight(Node* _node);
        void dblRotateRight(Node* _node);
        void rotateLeft(Node* _node);
        void dblRotateLeft(Node* _node);

        int max(Node* _root);
        int min(Node* _root);

        int heightN(Node* _root);
        int balFactor(Node* _root);

        int minDepth(Node* _root);
        int maxDepth(Node* _root);

        int countNodes(Node* _root);
        int countLeafs(Node* _root);
};

#endif // BTREE_H

#include "AVLTree.h"
#include <iostream>

using namespace std;

int main(){
    AVLTree testTree;
<<<<<<< HEAD
    testTree.insert(10);
<<<<<<< HEAD
    testTree.insert(9);
    testTree.insert(7);
    testTree.insert(6);
    testTree.insert(5);
    testTree.insert(4);
=======
    testTree.insert(8);
    testTree.insert(12);

    testTree.insert(6);
    testTree.insert(9);
    testTree.insert(13);
    testTree.insert(11);
    testTree.insert(5);

>>>>>>> parent of c0984c5... Buggy insert
=======
    for (int i = 1; i <= 10; i++){
        testTree.insert(i * 10);
    }

>>>>>>> parent of 03297f5... Buggy and broken

    cout << "Pre-order: ";
    testTree.printTreePre();
    cout << endl;

    cout << "Post-order: ";
    testTree.printTreePost();
    cout << endl;

    cout << "In-order: ";
    testTree.printTreeIn();
    cout << endl;

    cout << "Max: ";
    cout << testTree.max() << endl;

    cout << "Min: ";
    cout << testTree.min() << endl;

    cout << "Number of nodes: ";
    cout << testTree.numNodes() << endl;

    cout << "Number of Leafs: ";
    cout << testTree.numLeafs() << endl;

    cout << "Is the tree balanced? ";
    cout << testTree.isBalanced() << endl;
    return 0;
}

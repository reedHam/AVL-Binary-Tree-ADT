#include "AVLTree.h"
#include <iostream>

using namespace std;

int main(){
    AVLTree testTree;
    testTree.insert(10);
    testTree.insert(9);
    testTree.insert(7);
    testTree.insert(6);
    testTree.insert(5);
    testTree.insert(4);

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

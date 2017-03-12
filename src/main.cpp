#include "AVLTree.h"
#include <iostream>

using namespace std;

int main(){
    AVLTree testTree;
    for (int i = 1; i <= 10; i++){
        testTree.insert(i * 10);
    }


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

    cout << "Height of Tree: ";
    cout << testTree.height() << endl;

    cout << "Is the tree balanced? ";
    cout << testTree.isBalanced() << endl;
    return 0;
}

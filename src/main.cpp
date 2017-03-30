#include "AVLTree.h"
#include <iostream>

using namespace std;

int main(){
    AVLTree testTree;
    for (int i = 0; i < 10; i++){
        testTree.insert(i);
    }


    testTree.displayTree();

    return 0;
}

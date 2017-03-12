#include "AVLTree.h"
#include <iostream>
AVLTree::AVLTree(){
    root = NULL;
}

AVLTree::~AVLTree(){
    deleteTree();
}

/**
*   isBalanced Checks if a tree is balanced
*   @return  True if the tree is balanced or if root is null
*   @return  False if the tree is not balanced
*/
bool AVLTree::isBalanced(){
    if (root != NULL){
        // if the difference is greater than 1 the tree is unbalanced
        return (maxDepth(root) - minDepth(root)) < 1;
    }
}

/**
*   This method calls a method that traverses the tree in pre-order
*/
void AVLTree::printTreePre(){
    return printTreePre(root);
}

/**
*   This method traverses the tree in pre-order and prints the value
*/
void AVLTree::printTreePre(Node* _root){
    if (_root != NULL){
        std::cout << _root->value;
        std::cout << " ";
        printTreePre(_root->left);
        printTreePre(_root->right);
    }
}

/**
*   This method calls a method that traverses the tree in post-order
*/
void AVLTree::printTreePost(){
    return printTreePost(root);
}

/**
*   This method traverses the tree in post-order and prints the value
*/
void AVLTree::printTreePost(Node* _root){
    if (_root != NULL){
        printTreePost(_root->left);
        printTreePost(_root->right);
        std::cout << _root->value;
        std::cout << " ";
    }
}

/**
*   This method calls a method that traverses the tree in in-order
*/
void AVLTree::printTreeIn(){
    return printTreeIn(root);
}

/**
*   @return The height of the tree
*/
int AVLTree::height(){
    return maxDepth(root);
};

/**
*   This method traverses the tree in in-order and prints the value
*/
void AVLTree::printTreeIn(Node* _root){
    if (_root != NULL){
        printTreeIn(_root->left);
        std::cout << _root->value;
        std::cout << " ";
        printTreeIn(_root->right);
    }
}


/**
*   This method traverses the right branch of the tree by calling a recursing max method
*   @return the maximum value in the tree
*/
int AVLTree::max(){
    if (root != NULL){
        if (root->right != NULL){
            return max(root->right);
        } else {
            return root->value;
        }
    } else {
        return 0;
    }
}

/**
*   This method traverses the right branch of the tree by recursing
*   @return the maximum value in the tree
*/
int AVLTree::max(Node* _root){
    if (_root->right != NULL){
        max(_root->right);
    } else {
        return _root->value;
    }
}

/**
*   This method traverses the left branch of the tree by calling a recursing min method
*   @return the minimum value in the tree
*/
int AVLTree::min(){
    if (root != NULL){
        if (root->left != NULL){
            return min(root->left);
        } else {
            return root->value;
        }

    } else {
        return 0;
    }
}

/**
*   This method traverses the left branch of the tree by recursing
*   @return the minimum value in the tree
*/
int AVLTree::min(Node* _root){
    if (_root->left != NULL){
        min(_root->left);
    } else {
        return _root->value;
    }
}


/**
*   This method calls countNode
*   @return the number of nodes in the tree
*/
int AVLTree::numNodes(){
    return countNodes(root);
};

/**
*   This traverses the tree and adds 1 for every node
*   @param node to traverse from
*   @return the number of nodes in the tree
*/
int AVLTree::countNodes(Node* _root){
    if (_root != NULL){
        return 1 + countNodes(_root->left) + countNodes(_root->right);
    } else {
        return 0;
    }
};

/**
*   This method calls countLeaf
*   @return the number of nodes in the tree
*/
int AVLTree::numLeafs(){
    return countLeafs(root);
};

/**
*   This traverses the tree and adds 1 for every leaf node
*   @param node to traverse from
*   @return the number of leaf nodes in the tree
*/
int AVLTree::countLeafs(Node* _root){
    if (_root != NULL){
        if (_root->left == NULL && _root->right == NULL){
            return 1;
        }

        return countLeafs(_root->left) + countLeafs(_root->right);
    } else {
        return 0;
    }
};


//-----------------DATA OPERATIONS----------------------

/**
*   this method allows the user to delete the entire tree it calls the deleteTree(Node*) method that
*   will recursively delete all the nodes in the tree
*/
void AVLTree::deleteTree(){
    deleteTree(root);
}

/**
*   this method recursively deletes all the nodes in the tree starting with the leaf nodes
*   @param _leaf the node to delete
*/
void AVLTree::deleteTree(Node* _leaf){
    if (_leaf != NULL){
        deleteTree(_leaf->left);
        deleteTree(_leaf->right);
        delete _leaf;
    }
}

/**
*   This method allows the user to insert a value that will create a new node
*   The tree is traversed recursively and the new node is inserted in the appropriate place
*   @param _value int the value that will be inserted into the tree
*/
void AVLTree::insert(int _value){
    if (root != NULL){
        insert(_value, root);
    } else { // create root
        root = new Node(_value);
    }
}

/**
*   This method traverses the tree and inserts the value as a new node in the
*   correct position
*   will not insert duplicate values
*   @param _value int the value that will be inserted into the tree
*   @param _node the node to be checked against _value
*/
void AVLTree::insert(int _value, Node* _node){
    if (_value < _node->value){
        if (_node->left != NULL){ // if there is a left child recurse
            insert(_value, _node->left);
        } else { // if there is no left child insert node here
            _node->left = new Node(_value);
        }
    } else if (_value > _node->value){
        if (_node->right != NULL){ // if there is a right child recurse
            insert(_value, _node->right);
        } else { // if there is no right child insert node here
            _node->right = new Node(_value);
        }
    } else { // if the value is a duplicate then return
        return;
    }
}

/**
*   minDepth is a helper function for recursion, used in isBalanced
*   minDepth recurses through the tree and adds 1 for each layer of depth it traverses
*   @param  Root of the tree that you want to find the min depth of
*   @return The depth of the tree
*/

int AVLTree::minDepth(Node* _root){
    if (_root != NULL){
       return 1 +  std::min(minDepth(_root->left), minDepth(_root->right));
    }
    return 0;
}

/**
*   maxDepth is a helper function for recursion, used in isBalanced
*   maxDepth recurses through the tree and adds 1 for each layer of depth it traverses
*   @param  Root of the tree that you want to find the max depth of
*   @return The depth of the tree
*/
int AVLTree::maxDepth(Node* _root){
    if (_root != NULL){
       return 1 + std::max(minDepth(_root->left), minDepth(_root->right));
    }
    return 0;
}


/**
*   rotates a right heavy sub tree once
*   @param node to rotate on
*/
void AVLTree::rotateRight(Node* _node){

}


/**
*   rotates a left heavy sub tree once
*   @param node to rotate on
*/
void AVLTree::rotateLeft(Node* _node){

}

/**
*   gets the height of a node
*   @param node to get hight from
*   @return the hight of the node 0 if node is NULL
*/
int AVLTree::getHeight(Node* _node){
    if (_node != NULL){
        return _node->height;
    } else {
        return 0;
    }
}



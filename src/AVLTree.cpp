#include "AVLTree.h"
#include <iostream>
AVLTree::AVLTree(){
    root = NULL;
}

AVLTree::~AVLTree(){
    deleteTree();
}

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
    if (root == NULL){
       root = new Node(_value);
    } else {
        insertNode(_value, root);
    }
}

/**
*   This method traverses the tree and inserts the value as a new node in the
*   correct position
*   will not insert duplicate values
*   @param _value int the value that will be inserted into the tree
*   @param _node the node to be checked against _value
*/
AVLTree::Node* AVLTree::insertNode(int _value, Node* _node){
    // Step 1: If _node is NULL the spot is free and a new node needs to be created
    if (_node == NULL){
        return new Node(_value);
        // Step 2: If the value being inserted is smaller than the current nodes
        //         try and insert to the left
    } else if (_value < _node->value){
        std::cout << "\n";
        _node->left = insertNode(_value, _node->left); // Try and insert until the node is NULL
        // Step 3: If the value being inserted is larger than the current nodes
        //         try and insert to the right
    } else if (_value > _node->value){
        std::cout << "\n";
        _node->right = insertNode(_value, _node->right); // Try and insert until the node is NULL
    }
    balance(_node);
}



/**
*   isBalanced Checks if a tree is balanced
*   @return  True if the tree is balanced or if root is null
*   @return  False if the tree is not balanced
*/
bool AVLTree::isBalanced(){
    if (root != NULL){
        // if the difference is greater than 1 the tree is unbalanced
        return (maxDepth(root) - minDepth(root)) <= 1;
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
       return 1 + std::min(minDepth(_root->left), minDepth(_root->right));
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
        std::cout << "Root: " << &_root->value << std::endl;
        return 1 + std::max(maxDepth(_root->left), maxDepth(_root->right));
    } else {
        return 0;
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
*   @return The height of the tree
*/
int AVLTree::height(){
    return maxDepth(root);
};

/**
*   rotates a right heavy sub tree once
*   @param node to rotate on
*/
AVLTree::Node* AVLTree::rotateRight(Node* _node){
    Node* tempNode = _node->left;
    _node->left = tempNode->right;
    tempNode->right = _node;
    fixHeight(_node);
    fixHeight(tempNode);
    std::cout << "sub Root: " << tempNode->value << std::endl;
    std::cout << "left: " << tempNode->left->value << std::endl;
    std::cout << "right: " << tempNode->right->value << std::endl;
    std::cout << "Root: " << root->value << std::endl;
    return tempNode;
}

/**
*   rotates a left heavy sub tree once
*   @param node to rotate on
*/
AVLTree::Node* AVLTree::rotateLeft(Node* _node){
    Node* tempNode = _node->right;
    _node->right = tempNode->left;
    tempNode->left = _node;
    fixHeight(_node);
    fixHeight(tempNode);
    return tempNode;
}

AVLTree::Node* AVLTree::balance(Node* _root){
    fixHeight(_root);

    if (balFactor(_root) == 2){
         if (balFactor(_root->right) < 0){
            _root->right = rotateRight(_root->right);
        }
        return rotateLeft(_root);
    }

    if (balFactor(_root) == -2){
         if (balFactor(_root->left) > 0){
            _root->left = rotateLeft(_root->left);
        }
        return rotateRight(_root);
    }
    return _root;
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
*   checks if the node is NULL
*   @param node to check the height of
*   @return height of the node height = 0 if NULL
*/
int AVLTree::heightN(Node* _root){
    if (_root != NULL){
        return _root->height;
    } else {
        return 0;
    }
}

/**
*   subtracts the height of the left subtree from the right
*   @param node to check the balance factor of (only operates with non NULL nodes)
*   @return balance factor of the node
*/
int AVLTree::balFactor(Node* _root){
    if (_root != NULL){
        return (heightN(_root->right) - heightN(_root->left));
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

/**
*   gets the length of the longest subtree and sets the height of the node to it
*   @param node to fix the height of
*/
void AVLTree::fixHeight(Node* _root){
    if (_root != NULL){
       _root->height = maxDepth(_root);
        std::cout << _root->value << ": ";
        std::cout << _root->height << "\n";
    }
}





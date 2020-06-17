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
        return (maxDepth(root) - minDepth(root)) <= 1;
    }
}

/**
*   printTreePre calls  printTreePre(root) that traverses the tree in pre-order
*/
void AVLTree::printTreePre(){
    return printTreePre(root);
}

/**
*   printTreePre traverses the tree in pre-order and prints the value
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
*   printTreePost calls a printTreePost(root) that traverses the tree in post-order
*/
void AVLTree::printTreePost(){
    return printTreePost(root);
}

/**
*   printTreePost traverses the tree in post-order and prints the value
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
*   printTreeIn calls a printTreeIn(root) that traverses the tree in in-order
*/
void AVLTree::printTreeIn(){
    return printTreeIn(root);
}

/**
*   printTreeIn traverses the tree in in-order and prints the value
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
*   This method calls a method that displays the tree in the terminal
*/
void AVLTree::displayTree(){
    displayTree(root, 1);
}

void AVLTree::displayTree(Node* _root, int depth){
    if (_root != NULL){
        displayTree(_root->right, depth + 1);
        std::cout << std::endl;
        if (_root == root){
            std::cout<<"Root -> ";
        }
        for (int i = 0; i < depth && _root != root; i++){
            std::cout<<"        ";
        }
        std::cout << _root->value;
        displayTree(_root->left, depth + 1);
    }
}


/**
*   @return The height of the tree
*/
int AVLTree::height(){
    return maxDepth(root);
};


/**
*   This method traverses the right branch of the tree by calling a recursing max method
*   @return the maximum value in the tree
*/
int AVLTree::max(){
    if (root != NULL){
        if (root->right != NULL){
            return max(root->right)->value;
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
AVLTree::Node* AVLTree::max(Node* _root){
    if (_root->right != NULL){
        max(_root->right);
    } else {
        return _root;
    }
}

/**
*   This method traverses the left branch of the tree by calling a recursing min method
*   @return the minimum value in the tree
*/
int AVLTree::min(){
    if (root != NULL){
        if (root->left != NULL){
            return min(root->left)->value;
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
AVLTree::Node* AVLTree::min(Node* _root){
    if (_root->left != NULL){
        min(_root->left);
    } else {
        return _root;
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
*   this method calls the private remove method
*   @param _leaf the node to delete
*/
bool AVLTree::remove(int _value){
    if (search(_value)){
        root = remove(_value, root);
        return true;
    }
    return false;
}

/**
*   this method recursively searches through the tree and deletes the node when it is found
*   then the tree is reconstructed and balanced
*   @param _leaf the node to delete
*   @return _leaf the tree without deleted node
*/
AVLTree::Node* AVLTree::remove(int _value, Node* _node){
    if (_node == NULL){
        return NULL;
    } else if (_value < _node->value){
        _node->left = remove(_value, _node->left);
    } else if (_value > _node->value){
        _node->left = remove(_value, _node->right);
    } else { // if the value is found
        Node* left = _node->left;
        Node* right = _node->right;
        delete _node;

        if (right == NULL){
            return left;
        }

        Node* minimum = min(right);

        minimum->right = removeMin(right);

        minimum->left = left;

        return balance(minimum);
    }
}

/**
*   helper method for removing finds the lowest value in the sub tree
*   then balances
*   @param _leaf the node to delete
*/
AVLTree::Node* AVLTree::removeMin(Node* _node){
    if (_node->left == NULL){
        return _node->right;
    }

    _node->left = removeMin(_node->left);

    return balance(_node);
}

/**
*   This method allows the user to insert a value that will create a new node
*   The tree is traversed recursively and the new node is inserted in the appropriate place
*   @param _value int the value that will be inserted into the tree
*/
void AVLTree::insert(int _value){
    root = insert(_value, root);
}

/**
*   This method passes a value to search for to the private search method
*   @param the value to search for
*/
bool AVLTree::search(int _value){
    return search(_value, root) != NULL;
}

/**
*   This method searches for a node recursively
*   @param the value to search for
*   @param the node of the sub tree to search
*/
AVLTree::Node* AVLTree::search(int _value, Node* _root){
    if (_root == NULL){
        return NULL;
    } else if (_value < _root->value){
        search(_value, _root->left);
    } else if (_value > _root->value){
        search(_value, _root->right);
    } else { // if the value is found
        return _root;
    }
}



/**
*   This method traverses the tree and inserts the value as a new node in the
*   correct position
*   will not insert duplicate values
*   @param _value int the value that will be inserted into the tree
*   @param _node the node to be checked against _value
*   @return root to changed tree
*/
AVLTree::Node* AVLTree::insert(int _value, Node* _node){
    // Step 1: Insert node into tree
    if (_node == NULL){
        return new Node(_value);// if node is NULL create it
    } else if (_value < _node->value){
        _node->left = insert(_value, _node->left);
    } else if (_value > _node->value){
        _node->right = insert(_value, _node->right);
    } else { // if the value is a duplicate then return
        return _node;
    }

    return balance(_node);
}

/**
*   checks if the difference in the height of the sub-trees violates the balance property
*   @param root of the tree to balance
*   @return root of the balanced tree
*/
AVLTree::Node* AVLTree::balance(Node* _node){
    _node->height = maxDepth(_node);

    if (getBalance(_node) == 2){
        //Left Right
        if (getBalance(_node->right) > 0){
            _node->left = rotateLeft(_node->left);
        }
        //Left Left
        return rotateRight(_node);
    }

    if (getBalance(_node) == -2){
        //Right Left
        if (getBalance(_node->left) < 0){
            _node->right = rotateRight(_node->right);
        }
        //Right Right
        return rotateLeft(_node);
    }

    return _node;
}


/**
*   rotates a right heavy sub tree once
*   @param node to rotate on
*   @return Rotated sub tree
*/
AVLTree::Node* AVLTree::rotateRight(Node* _node){
    Node *piviot = _node->left;
    Node *leaf = piviot->right;

    // Perform rotation
    piviot->right = _node;
    _node->left = leaf;

    piviot->height = maxDepth(piviot);
    _node->height = maxDepth(_node);

    return piviot;
}

/**
*   rotates a left heavy sub tree once
*   @param node to rotate on
*   @return Rotated sub tree
*/
AVLTree::Node* AVLTree::rotateLeft(Node* _node){
    Node *piviot = _node->right;
    Node *leaf = piviot->left;

    // Perform rotation
    piviot->left = _node;
    _node->right = leaf;

    piviot->height = maxDepth(piviot);
    _node->height = maxDepth(_node);

    return piviot;
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
       return 1 + std::max(maxDepth(_root->left), maxDepth(_root->right));
    }
    return 0;
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

int AVLTree::getBalance(Node* _root){
    if (_root != NULL){
        return (getHeight(_root->left) - getHeight(_root->right));
    }
    return 0;
}

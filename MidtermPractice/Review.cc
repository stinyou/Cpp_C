#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct BST_Node {
    string key;
    BST_Node* left;
    BST_Node* right;
};
typedef BST_Node* BST;

using namespace std;

void BST_init (BST& root) {
    root = nullptr;
}

bool BST_isEmpty (const BST& root) {
    return nullptr == root;
}

bool BST_has (const BST& root, std::string key) {
    if (nullptr == root) {
	    return false;
    } else if (root->key == key) {
	    return true;
    } else if (root->key > key) {
	    return BST_has (root->left, key);
    } else {
	    return BST_has (root->right, key);
    }
}

void BST_insert (BST& root, std::string key) {
    if (nullptr == root) {
        root = new BST_Node; 
        root->key = key; 
        root->left = nullptr; 
        root->right = nullptr;
    } else if (key < root->key) {
	    BST_insert(root->left, key);
    } else {
	    BST_insert(root->right, key);
    } 
}

void BST_print (const BST& root) {
    if (nullptr != root) {
        BST_print (root->left);
        cout << root->key << endl;
        BST_print (root->right);
    }
}

// Now you do this one ...
void BST_remove (BST& root, std::string key) {
    if (!BST_has(root, key)) { // Case 1: Not in BST
        cerr << "Error, couldn't find \"" << key << "\" in the BST\n";
        assert(false);
    }
    else if (root->key == key) {
        if (BST_isEmpty(root->left) && BST_isEmpty(root->right)) { // Case 2: Leaf Node
            delete(root);
            root = nullptr;
        }
        else if (BST_isEmpty(root->left)) { // Case 3: Right Child Only
            BST tempnode = root->right;
            delete(root);
            root = tempnode;
        }
        else if (BST_isEmpty(root->right)) { // Case 4: Left Child Only
            BST tempnode = root->left;
            delete(root);
            root = tempnode;
        }
        else { // Case 5: Two Children
            if (BST_isEmpty(root->left->right)) {
                BST tempnode = root->left;
                root->left->right = root->right;
                delete(root);
                root = tempnode;
            }
            else {
                BST tempnode = root->left;
                while (tempnode->right->right) {
                    tempnode = tempnode->right;
                }
                string copy = tempnode->right->key;
                BST_remove(tempnode, tempnode->right->key);
                BST newroot = new BST_Node {copy, root->left, root->right};
                delete(root);
                root = newroot;
            }
        }
    }
    /*
    else if (root->left && root->left->key == key) {
        if (BST_isEmpty(root->left->left) && BST_isEmpty(root->left->right)) { // Case 2: Leaf Node
            delete(root->left);
            root->left = nullptr;
        }
        else if (BST_isEmpty(root->left->left)) { // Case 3: Right Child Only
            BST tempnode = root->left->right;
            delete(root->left);
            root->left = tempnode;
        }
        else if (BST_isEmpty(root->left->right)) { // Case 4: Left Child Only
            BST tempnode = root->left->left;
            delete(root->left);
            root->left = tempnode;
        }
        else { // Case 5: Two Children
            if (BST_isEmpty(root->left->left->right)) {
                BST tempnode = root->left->left;
                root->left->left->right = root->left->right;
                delete(root->left);
                root->left = tempnode;
            }
            else {
                BST tempnode = root->left->left;
                while (tempnode->right->right) {
                    tempnode = tempnode->right;
                }
                string copy = tempnode->right->key;
                BST_remove(tempnode, tempnode->right->key);
                BST newroot = new BST_Node {copy, root->left->left, root->left->right};
                delete(root->left);
                root->left = newroot;
            }
        }
    }
    else if (root->right && root->right->key == key) {
        if (BST_isEmpty(root->right->left) && BST_isEmpty(root->right->right)) { // Case 2: Leaf Node
            delete(root->right);
            root->right = nullptr;
        }
        else if (BST_isEmpty(root->right->left)) { // Case 3: Right Child Only
            BST tempnode = root->right->right;
            delete(root->right);
            root->right = tempnode;
        }
        else if (BST_isEmpty(root->right->right)) { // Case 4: Left Child Only
            BST tempnode = root->right->left;
            delete(root->right);
            root->right = tempnode;
        }
        else { // Case 5: Two Children
            if (BST_isEmpty(root->right->left->right)) {
                BST tempnode = root->right->left;
                root->right->left->right = root->right->right;
                delete(root->right);
                root->right = tempnode;
            }
            else {
                BST tempnode = root->right->left;
                while (tempnode->right->right) {
                    tempnode = tempnode->right;
                }
                string copy = tempnode->right->key;
                BST_remove(tempnode, tempnode->right->key);
                BST newroot = new BST_Node {copy, root->right->left, root->right->right};
                delete(root->right);
                root->right = newroot;
            }
        }
    }
    else {
        if (key < root->key) {
            BST_remove(root->left, key);
        }
        else {
            BST_remove(root->right, key);
        }
    }
    */
   else {
    if (key < root->key) {
        BST_remove(root->left, key);
    }
    else {
        BST_remove(root->right, key);
    }
}
}
// ... and this one too
void BST_nuke (BST & root) {
    // TODO
    if (BST_isEmpty(root)) { // Base Case: Empty
        return;
    }
    else if (BST_isEmpty(root->left) && BST_isEmpty(root->right)) {
        delete(root);
        root = nullptr;
    }
    else if (BST_isEmpty(root->left)) {
        BST_nuke(root->right);
        delete(root);
        root = nullptr;
    }
    else if (BST_isEmpty(root->right)) {
        BST_nuke(root->left);
        delete(root);
        root = nullptr;
    }
    else {
        BST_nuke(root->left);
        BST_nuke(root->right);
        delete(root);
        root = nullptr;
    }
}

void BST_poin(const BST & root) {
    if (!BST_isEmpty(root)) {
        if (BST_isEmpty(root->left) && BST_isEmpty(root->right)) {
            return;
        }
        BST_poin(root->left);
        cout << root->key << endl;
        BST_poin(root->right);
    }
}

int main(void) {
    BST bst;
    BST_init(bst);
    BST_insert(bst, "delta");
    BST_insert(bst, "beta");
    BST_insert(bst, "alpha");
    BST_insert(bst, "epsilon");
    BST_insert(bst, "sigma");
    BST_insert(bst, "gamma");
    BST_insert(bst, "pi");
    BST_insert(bst, "omega");
    BST_insert(bst, "charlie");
    BST_poin(bst);
    BST_nuke(bst);
}
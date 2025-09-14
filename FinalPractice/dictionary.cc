#include <iostream>
#include <string>
using namespace std;

class Dictionary {
    public:
        Dictionary();
        virtual ~Dictionary();
        void add(string person, int num);
        void overwrite(string person, int num);
        int lookup(string person);
        void remove(string person);
        void print();
    private:
        struct Node;
        Node* root;
        Dictionary(Node* root);
        void addHelper(Node* & root, string person, int num);
        void removeHelper(Node* & root, string person);
        void printHelper(Node* & root);
};

struct Dictionary::Node {
    string key;
    int val;
    Node* left;
    Node* right;
};

Dictionary::Dictionary() : root {nullptr} {}

Dictionary::Dictionary(Node* root) : root{root} {}

Dictionary::~Dictionary() {
    if (root != nullptr) {
        Dictionary left {root->left};
        Dictionary right {root->right};
    }
    delete root;
}

void Dictionary::addHelper(Node* & root, string person, int num) {
    if (root == nullptr) {
        root = new Node {person, num, nullptr, nullptr};
    }
    else if (person < root->key) {
        addHelper(root->left, person, num);
    }
    else if (person > root->key) {
        addHelper(root->right, person, num);
    }
    else if (person == root->key) {
        cerr << "Error, " << person << "already exists." << endl;
    }
}

void Dictionary::add(string person, int num) {
    addHelper(root, person, num);
}

void Dictionary::overwrite(string person, int num) {
    Node* curnode = root;
    while (curnode) {
        if (curnode->key == person) {
            curnode->val = num;
            return;
        }
        else if (person < curnode->key) {
            curnode = curnode->left;
        }
        else if (person > curnode->key) {
            curnode = curnode->right;
        }
    }
    cerr << "Error, " << person << " does not exist." << endl;
}

int Dictionary::lookup(string person) {
    Node* curnode = root;
    while (curnode) {
        if (curnode->key == person) {
            return curnode->val;
        }
        else if (person < curnode->key) {
            curnode = curnode->left;
        }
        else if (person > curnode->key) {
            curnode = curnode->right;
        }
    }
    cerr << "Error, " << person << " does not exist." << endl;
    return -1;
}

void Dictionary::removeHelper(Node* & root, string person) {
    if (root == nullptr) {
        cerr << "Error, " << person << " does not exist." << endl;
        return;
    }
    if (root->key == person) {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            Node* tempnode = root->left;
            delete root;
            root = tempnode;
        }
        else if (root->left == nullptr && root->right != nullptr) {
            Node* tempnode = root->right;
            delete root;
            root = tempnode;
        }
        else if (root->left != nullptr && root->right != nullptr) {
            Node* tempnode = root->left;
            if (tempnode->right == nullptr) {
                tempnode->right = root->right;
                delete root;
                root = tempnode;
            }
            else {
                while (tempnode->right->right) {
                    tempnode = tempnode->right;
                }
                Node* detachednode = tempnode->right;
                tempnode->right = tempnode->right->left;
                detachednode->left = root->left;
                detachednode->right = root->right;
                delete root;
                root = detachednode;
            }
        }
    }
    else if (person < root->key) {
        removeHelper(root, person);
    }
    else if (person > root->key) {
        removeHelper(root, person);
    }
}

void Dictionary::remove(string person) {
    removeHelper(root, person);
}

void Dictionary::printHelper(Node* & root) {
    if (root != nullptr) {
        printHelper(root->left);
        cout << root->key << ": " << root->val << endl;
        printHelper(root->right);
    }
}

void Dictionary::print() {
    printHelper(root);
}

int main(int argc, char* argv[]) {
    Dictionary phonebook {};
    phonebook.add("Justin", 647);
    phonebook.add("You", 905);
    phonebook.add("Christopher", 330);
    int number = phonebook.lookup("Justin");
    cout << "Justin's number is: " << number << endl;
    phonebook.overwrite("Justin", 416);
    number = phonebook.lookup("Justin");
    cout << "Justin's new number is: " << number << endl;
    phonebook.add("Dad", 888);
    phonebook.print();
    phonebook.remove("Justin");
    number = phonebook.lookup("Justin");
    phonebook.print();
    return 0;
}
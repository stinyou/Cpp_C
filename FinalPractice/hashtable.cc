#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class HashTable {
    public:
        HashTable(long long unsigned int size = 1000);
        virtual ~HashTable();
        void insert(string id, int num);
        bool has(string id);
        int lookup(string id);
        void remove(string id);
        void print();
    private:
        struct Node;
        const long long unsigned int tableSize;
        vector<Node*> table;
        int Hash(string val);
};

struct HashTable::Node {
    string id;
    int num;
    Node* next;
};

int HashTable::Hash(string val) {
    int hash = 17;
    for (int i = 0; i < val.length(); i++) {
        hash += val[i];
        hash *= 173;
        hash %= tableSize;
    }
    return hash;
}

HashTable::HashTable(long long unsigned int size) : tableSize{size}, table{size} {}

HashTable::~HashTable() {
    for (int i = 0; i < tableSize; i++) {
        while (table[i]) {
            Node* tempnode = table[i];
            table[i] = table[i]->next;
            delete tempnode;
        }
    }
}

void HashTable::insert(string id, int num) {
    int bucket = Hash(id);
    table[bucket] = new Node {id, num, table[bucket]};
}

bool HashTable::has(string id) {
    int bucket = Hash(id);
    Node* curnode = table[bucket];
    while (curnode) {
        if (curnode->id == id) {
            return true;
        }
        curnode = curnode->next;
    }
    return false;
}

int HashTable::lookup(string id) {
    int bucket = Hash(id);
    Node* curnode = table[bucket];
    while (curnode) {
        if (curnode->id == id) {
            return curnode->num;
        }
        curnode = curnode->next;
    }
    cerr << "Error, " << id << " does not exist.";
    return -1;
}

void HashTable::remove(string id) {
    int bucket = Hash(id);
    Node* curnode = table[bucket];
    if (curnode == nullptr) {
        cerr << "Error, " << id << " does not exist.";
    }
    if (curnode->id == id) {
        table[bucket] = curnode->next;
        delete curnode;
        return;
    }
    while (curnode->next) {
        if (curnode->next->id == id) {
            Node* tempnode = curnode->next;
            curnode->next = curnode->next->next;
            delete tempnode;
            return;
        }
    }
    cerr << "Error, " << id << " does not exist.";
}

void HashTable::print() {
    for (int i = 0; i < tableSize; i++) {
        Node* curnode = table[i];
        while (curnode) {
            cout << curnode->id << ": " << curnode->num << endl;
            curnode = curnode->next;
        }
    }
}

int main(int argc, char* argv[]) {
    HashTable packages {};
    packages.insert("Justin", 4);
    packages.insert("You", 5);
    packages.insert("Justin", 6);
    packages.print();
    assert(packages.has("Justin"));
    assert(packages.has("You"));
    assert(packages.lookup("Justin") == 6);
    assert(packages.lookup("You") == 5);
    packages.remove("Justin");
    packages.print();
    assert(packages.lookup("Justin") == 4);
    return 0;
}
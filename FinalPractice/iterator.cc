#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class LinkedList {
    private:
        struct Node {
            string val;
            Node* next;
        };
        Node* head;
    public:
        LinkedList(); // ctor

        // The Big Three
        virtual ~LinkedList(); // dtor
        LinkedList(const LinkedList & other); // copy ctor
        LinkedList& operator=(LinkedList other); // copy assgt operator

        bool isEmpty() const;
        void push(const string & val);
        string peek() const;
        string pop();

        class iterator {
            public:
                bool operator!=(const iterator& other) const;
                string& operator*();
                iterator& operator++();
            private:
                Node* p;
                iterator(Node* p); // private ctor
            friend class LinkedList;
        };
        iterator begin();
        iterator end();
};

// Implementing linked list

LinkedList::LinkedList() : head{nullptr} {}

LinkedList::~LinkedList() {
    while (!isEmpty()) {
        pop();
    }
}

LinkedList::LinkedList(const LinkedList& other) {
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }
    head = new Node {other.head->val, nullptr};
    Node* curnode = head;
    Node* copiednode = other.head;
    while (copiednode->next) {
        curnode->next = new Node {copiednode->next->val, nullptr};
        curnode = curnode->next;
        copiednode = copiednode->next;
    }
}

LinkedList& LinkedList::operator=(LinkedList other) {
    while (!isEmpty()) {
        pop();
    }
    head = other.head;
    return *this;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::push(const string& val) {
    head = new Node {val, head};
}

string LinkedList::peek() const {
    return head->val;
}

string LinkedList::pop() {
    assert(!isEmpty());
    string returnval = head->val;
    Node* tempnode = head;
    head = head->next;
    delete tempnode;
    return returnval;
}

// Implementing iterator

LinkedList::iterator::iterator(Node* p) : p{p} {}

bool LinkedList::iterator::operator!=(const iterator & other) const {
    return p != other.p;
}

string& LinkedList::iterator::operator*() {
    return p->val;
}

LinkedList::iterator& LinkedList::iterator::operator++() {
    p = p->next;
    return *this;
}

LinkedList::iterator LinkedList::begin() {
    return iterator{head};
}

LinkedList::iterator LinkedList::end() {
    return iterator{nullptr};
}

int main(void) {
    LinkedList ll {};
    assert(ll.isEmpty());
    ll.push("apple");
    ll.push("banana");
    ll.push("cherry");
    cout << ll.peek() << endl;
    LinkedList llcopy1 {ll};
    LinkedList llcopy2 {};
    llcopy2.push("test");
    llcopy2 = ll;
    ll.pop();
    cout << "oglist:" << endl;
    for (LinkedList::iterator it = ll.begin(); it != ll.end(); ++it) {
        cout << *it << endl;
    }
    cout << "first copy:" << endl;
    for (LinkedList::iterator it = llcopy1.begin(); it != llcopy1.end(); ++it) {
        cout << *it << endl;
    }
    cout << "second copy:" << endl;
    for (LinkedList::iterator it = llcopy2.begin(); it != llcopy2.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
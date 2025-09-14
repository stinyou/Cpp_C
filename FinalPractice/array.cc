#include <string>

class Array {
    private:
        std::string* theArray;
    public:
        const int size;
        Array() = delete;
        Array(int size);

        // Big Three
        Array(const Array& other);
        Array& operator=(const Array& other);
        virtual ~Array();

        const std::string& at(int i) const;
        std::string& at(int i);

        // implementing iterator class
        class iterator {
            private:
                std::string* p;
                iterator(std::string* p);
            public:
                bool operator!=(const iterator& other) const;
                std::string& operator*();
                iterator& operator++();
            friend class Array;
        };
        iterator begin();
        iterator end();
};

#include <iostream>
#include <cassert>
using namespace std;

Array::Array(int size) : size{size}, theArray{new string[size]} {}

Array::Array(const Array& other) : size{other.size}, theArray{new string[other.size]} {
    for (int i = 0; i < size; i++) {
        theArray[i] = other.theArray[i];
    }
}

Array& Array::operator=(const Array& other) {
    assert(size == other.size);
    for (int i = 0; i < size; i++) {
        theArray[i] = other.theArray[i];
    }
    return *this;
}

Array::~Array() {
    delete [] theArray;
}

const string& Array::at(int i) const {
    assert(i < size);
    return theArray[i];
}

string& Array::at(int i) {
    assert(i < size);
    return theArray[i];
}

Array::iterator::iterator(string* p) : p{p} {}

bool Array::iterator::operator!=(const iterator& other) const {
    return p != other.p;
}

string& Array::iterator::operator*() {
    return *p;
}

Array::iterator& Array::iterator::operator++() {
    p++;
    return *this;
}

Array::iterator Array::begin() {
    return iterator{theArray};
}

Array::iterator Array::end() {
    return iterator{&theArray[size]};
}

int main(int argc, char* argv[]) {
    Array people{3};
    people.at(0) = "Justin";
    people.at(1) = "Christopher";
    people.at(2) = "You";
    Array copy1{people};
    Array copy2{3};
    copy2 = people;
    for (int i = 0; i < people.size; i++) {
        cout << people.at(i) << endl;
    }
    for (Array::iterator it = people.begin(); it != people.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
#include <iostream>
#include <deque>
#include <cassert>
#include <string>
using namespace std;

template <typename T>
class Queue {
    public:
        Queue();
        virtual ~Queue();
        void enter(T val);
        void leave();
        T first();
        bool isEmpty();
    private:
        deque <T> q;
};

template <typename T>
Queue<T>::Queue() : q{} {}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::enter(T val) {
    q.push_back(val);
}

template <typename T>
void Queue<T>::leave() {
    assert(!isEmpty());
    q.pop_front();
}

template <typename T>
T Queue<T>::first() {
    assert(!isEmpty());
    return q.at(0);
}

template <typename T>
bool Queue<T>::isEmpty() {
    return q.empty();
}

int main(int argc, char* argv[]) {
    Queue<string> people {};
    if (people.isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    people.enter("Justin");
    if (!people.isEmpty()) {
        cout << "The first person in the queue is: " << people.first() << endl;
    }
    people.enter("You");
    if (!people.isEmpty()) {
        cout << "The first person in the queue is: " << people.first() << endl;
    }
    people.leave();
    if (!people.isEmpty()) {
        cout << "The first person in the queue is: " << people.first() << endl;
    }
    people.leave();
    if (people.isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    people.enter("Justin");
    people.enter("You");
    return 0;
}
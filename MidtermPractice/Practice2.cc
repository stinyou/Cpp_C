#include <iostream>
using namespace std;

struct test {
    int x;
    int* p;
};

int main(void) {
    int a = 4, b = 3, c = 7;
    cout << (a > (b > c)) << ((a > b) > c) << (a > b > c) << endl;
    test init1;
    cout << init1.x << " " << init1.p << endl;
    test init2 {};
    cout << init2.x << " " << init2.p << endl;
    return 0;
}
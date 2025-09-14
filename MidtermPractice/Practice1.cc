#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    vector<string> names {"Misba", "Justin"};
    names.push_back("Ioan");
    cout << names.back() << endl;
    names.pop_back();
    cout << names.back() << endl;
    vector<string> months (2);
    months.push_back("January");
    months.push_back("February");
    months.push_back("March");
    cout << months.back() << endl;
    return 0;
}
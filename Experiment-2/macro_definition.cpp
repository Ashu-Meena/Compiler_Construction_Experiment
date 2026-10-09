#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter assembly instruction: ";
    getline(cin, s);

    if (s.find("MACRO") != string::npos) {
        cout << "It is a macro definition" << endl;
    } else {
        cout << "It is not a macro definition" << endl;
    }

    return 0;
}

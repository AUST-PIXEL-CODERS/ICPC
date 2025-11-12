#include <iostream>
#include <string>
using namespace std;

int main() {
    string mystr;
    while(1) {
        cout << "Enter a String: ";
        cin >> mystr;
        cout << "Your string is: " << mystr << "\n\n";
    }
    return 0;
}
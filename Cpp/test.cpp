#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s = "1,2,3,4";
    stringstream ss(s);
    int ind;
    while (ss >> ind){
        if (ss.peek() == ','){
            ss.ignore();
        }
        cout << ind << endl;
    }
    return 0;
}
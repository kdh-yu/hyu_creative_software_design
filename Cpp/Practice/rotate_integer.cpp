/*
Write a program that rotates a list of numbers as follows.
- Create int type variables a, b, c and initialize the values to 10, 20, and 30, respectively.
- When the user enters 1, each value is shifted to the left,
  leftmost value moves tightmost, and the list of values are printed.
- When the user enters 2, each value is shiftd to the right,
  rightmost values moves leftmost, and the list of values are printed.
- When the user enters 3, the program stops.
- When the enters anything other than 1, 2, or 3,
  "Error: Wrong input" is printed and the program terminates.
*/

#include <iostream>

using namespace std;

void rotateLeft(int* pa, int* pb, int* pc) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = temp;
    cout << *pa << ":" << *pb << ":" << *pc << endl;
}

void rotateRight(int* pa, int* pb, int* pc) {
    int temp;
    temp = *pc;
    *pc = *pb;
    *pb = *pa;
    *pa = temp;
    cout << *pa << ":" << *pb << ":" << *pc << endl;
}

int main() {
    int a = 10, b = 20, c = 30;
    int input;
    bool repeat = true;
    cout << a << ":" << b << ":" << c << endl;
    while (repeat) {
        cout << "Input : ";
        cin >> input;
        switch (input){
            case 1:
                rotateLeft(&a, &b, &c);
                break;
            case 2:
                rotateRight(&a, &b, &c);
                break;
            case 3:
                cout << "Program Stops" << endl;
                repeat = false;
                break;
            default:
                cout << "Error: Wrong input\n";
                repeat = false;
                break;
        }
    }
    return 0;
}
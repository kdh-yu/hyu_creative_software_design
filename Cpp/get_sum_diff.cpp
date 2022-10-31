#include <iostream>

// Write a program that outputs the sum (a+b) and difference (a-b) of two integers a and b.
using namespace std;

void getSumDiff(int a, int b, int* pSum, int* pDiff) {
    *pSum = a + b;
    *pDiff = a - b;
}

int main() {
    int a, b, pSum, pDiff;
    cout << "a : ";
    cin >> a;
    cout << "b : ";
    cin >> b;
    getSumDiff(a, b, &pSum, &pDiff);
    cout << "Sum : " << pSum << "\nDiff : " << pDiff << endl;
    return 0;
}
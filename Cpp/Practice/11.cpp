#include <iostream>
using namespace std;

typedef struct { int a,b,c; } Triplet;

void TR(Triplet t, Triplet* pt, Triplet& rt){
    t.a = 10;
    pt->b = 20;
    rt.c = 30;
    cout << t.a << " " << t.b << " " << t.c << endl;
    cout << pt->a << " " << pt->b << " " << pt->c << endl;
    cout << rt.a << " " << rt.b << " " << rt.c << endl;
}

int main(){
    Triplet triplet = {0,0,0};
    TR(triplet, &triplet, triplet);
    cout << triplet.a << " " << triplet.b << " " << triplet.c << endl;
    return 0;
}
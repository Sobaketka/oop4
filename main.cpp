#include <iostream>
#include "Polynom.h"
using namespace std;

int main() {
    // Polynom p1;
    // cout << "p1 = ";
    // p1.output();
    //
    // Polynom p2(3);
    // cout << "p2 = ";
    // p2.output();
    //
    // int k;
    // cout << "Number of coefficients: ";
    // cin >> k;
    // double* arr = new double[k];
    // for (int i = 0; i < k; i++) {
    //     cout << "a" << i << " = ";
    //     cin >> arr[i];
    // }
    // Polynom p3(arr, k);
    // delete[] arr;
    // cout << "p3 = ";
    // p3.output();

    // {
    //     Polynom am, bm, cm;
    //     am = bm = cm = p3;
    //     am.output();
    //     bm.output();
    //     cm.output();
    // }

    // Polynom p4(p3);
    // cout << "p4 = ";
    // p4.output();
    //
    // p1 = p3;
    // cout << "p1 = ";
    // p1.output();
    //
    // Polynom p5;
    // p5.input();
    // cout << "p5 = ";
    // p5.output();

    // Polynom temp(1, 2);
    // temp.output();

    cout << "Objects now: " << Polynom::getCount() << endl;

    double c1[] = {1, 2, 3};
    double c2[] = {-1, 1};
    Polynom A(c1, 3), B(c2, 2);
    A.output();
    B.output();

    Polynom C = A.copy();
    cout << "copy: "; C.output();
    cout << "A(2) = " << A.value() << endl;
    Polynom D = A.derivative();
    cout << "A' = ";
    D.output();

    Polynom E = A.mulXminusB(2);
    cout << "(x-2)A = ";
    E.output();

    Polynom F = A.shift(1);
    cout << "A(x+1) = ";
    F.output();

    Polynom G = compose(A, B);
    cout << "A(B(x)) = ";
    G.output();

    Polynom q, r;
    divide(A, B, q, r);
    cout << "q = "; q.output();
    cout << "r = "; r.output();


    cout << "Objects now: " << Polynom::getCount() << endl;

    return 0;
}
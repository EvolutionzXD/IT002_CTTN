#include <bits/stdc++.h>
#include "Matrix.h"
using namespace std;

int main() {
    srand(time(0));

    MATRIX a, b;
    cin >> a;
    cin >> b;
    cout << "Ma tran A:\n" << a <<"\n";
    cout << "Ma tran B:\n" << b <<"\n";

    cout << "Ma tran (A + B):\n" << a + b <<"\n";
    cout << "Ma tran (A - B):\n" << a - b <<"\n";

    cout << "Ma tran (A * B) :\n"<< a * b <<"\n";

    cout << "Ma tran 2x2 ngau nhien: \n";
    MATRIX c;
    c.TaoNgauNhien(2, 2);
    cout << c;

    return 0;
}


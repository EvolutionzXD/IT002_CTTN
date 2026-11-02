#include <bits/stdc++.h>
#include "HoanCau.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    CongTyHoanCau cty;
    cin >> cty;

    cout << "\nDANH SACH NHAN VIEN CONG TY HOAN CAU\n";
    cout << cty;

    cout << "\nDANH SACH NHAN VIEN CO LUONG DUOI MUC TRUNG BINH\n";
    cty.ThapHonTB(cout);

    return 0;
}

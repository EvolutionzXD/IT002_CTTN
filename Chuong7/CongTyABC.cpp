#include <bits/stdc++.h>
#include "CongTyABC.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    CongTyABC cty;
    cin >> cty;

    cout << "\nDANH SACH NHAN VIEN CONG TY ABC\n";
    cout << cty;

    cout << "\nTONG LUONG CUA CONG TY\n";
    cout << "Tong chi tra luong: " << fixed << setprecision(0) << cty.TinhTongLuong() << " VND\n";

    cout << "\nTIM KIEM NHAN VIEN THEO HO TEN\n";
    string tenCanTim;
    cin >> ws;
    getline(cin, tenCanTim);
    cout << "Ket qua tim kiem cho \"" << tenCanTim << "\":\n";
    cty.TimKiemTheoTen(tenCanTim, cout);

    return 0;
}

/*
Input / Output mau:

Input:
3
1
Nguyen Van A
15/03/1995
5000000 22 1000000
2
Tran Van B
20/11/1998
4000000 1500
3
Le Van C
01/01/1985
10000000 2.5 5000000
Nguyen Van A

Output:
DANH SACH NHAN VIEN CONG TY ABC
[Van Phong] Ho ten: Nguyen Van A | Ngay sinh: 15/03/1995 | LCB: 5000000 | Luong thuc nhan: 10400000 | Ngay lam: 22 | Tro cap: 1000000
[San Xuat]  Ho ten: Tran Van B | Ngay sinh: 20/11/1998 | LCB: 4000000 | Luong thuc nhan: 7000000 | So san pham: 1500
[Quan Ly]   Ho ten: Le Van C | Ngay sinh: 01/01/1985 | LCB: 10000000 | Luong thuc nhan: 30000000 | He so CV: 2 | Thuong: 5000000

TONG LUONG CUA CONG TY
Tong chi tra luong: 47400000 VND

TIM KIEM NHAN VIEN THEO HO TEN
Ket qua tim kiem cho "Nguyen Van A":
[Van Phong] Ho ten: Nguyen Van A | Ngay sinh: 15/03/1995 | LCB: 5000000 | Luong thuc nhan: 10400000 | Ngay lam: 22 | Tro cap: 1000000
*/

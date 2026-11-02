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

/*
Input / Output mau:

Input:
3
1
NV001
Nguyen Van Dev
25
0901234567
dev@hoancau.com
15000000
10
2
NV002
Tran Thi Tester
23
0912345678
test@hoancau.com
10000000
20
1
NV003
Le Van Coder
28
0987654321
coder@hoancau.com
20000000
5

Output:
DANH SACH NHAN VIEN CONG TY HOAN CAU
[LTV] Ma NV: NV001 | Ten: Nguyen Van Dev | Tuoi: 25 | SDT: 0901234567 | Email: dev@hoancau.com | LCB: 15000000 | Luong: 17000000 | Overtime: 10h
[KCV] Ma NV: NV002 | Ten: Tran Thi Tester | Tuoi: 23 | SDT: 0912345678 | Email: test@hoancau.com | LCB: 10000000 | Luong: 11000000 | So loi: 20
[LTV] Ma NV: NV003 | Ten: Le Van Coder | Tuoi: 28 | SDT: 0987654321 | Email: coder@hoancau.com | LCB: 20000000 | Luong: 21000000 | Overtime: 5h

DANH SACH NHAN VIEN CO LUONG DUOI MUC TRUNG BINH
Muc luong trung binh: 16333333 VND
Danh sach nhan vien luong duoi muc trung binh:
[KCV] Ma NV: NV002 | Ten: Tran Thi Tester | Tuoi: 23 | SDT: 0912345678 | Email: test@hoancau.com | LCB: 10000000 | Luong: 11000000 | So loi: 20
*/
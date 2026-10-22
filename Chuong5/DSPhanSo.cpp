#include <bits/stdc++.h>
#include "DSPhanSo.h"
using namespace std;

int main() {
    DSPhanSo list;
    cin >> list;
    
    cout << "\nDanh sach phan so: " << list << endl;
    cout << "Phan so lon nhat: " << list.TimMax() << endl;
    cout << "Tong cac phan so: " << list.TinhTong() << endl;

    return 0;
}


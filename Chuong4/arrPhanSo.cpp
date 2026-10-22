#include <bits/stdc++.h>
#include "arrPhanSo.h"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	arrPhanSo A;
	cin >> A;
	cout << "Danh sach: " << A << "\n";
	cout << "Phan so lon nhat: " << A.Max() << "\n";
	cout << "So phan so co tu la so nguyen to: " << A.CountPrime() << "\n";
	A.arrPhanSoSort();
	cout << "Sau khi sap xep: " << A << "\n";
	arrPhanSo B;
	randomize(5, B);
	cout << "5 phan so ngau nhien: " << B << "\n";
}


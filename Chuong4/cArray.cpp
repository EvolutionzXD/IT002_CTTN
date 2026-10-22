#include <bits/stdc++.h>
#include "cArray.h"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cArray A;
	cin >> A;
	cout << "Day so: ";
	cout << A;
	int x;
	cin >> x;
	cout << "So lan xuat hien cua " << x << ": " << A.count(x) << "\n";
	cout << "Day tang dan: " << (A.isIncrease() ? "Co" : "Khong") << "\n";
	int m = A.findOddMin();
	cout << "So le nho nhat: " << m << "\n";
	A.cArraySort();
	cout << "Sau khi sap xep: ";
	cout << A;
	cArray B;
	randomize(5, B);
	cout << "Day ngau nhien: ";
	cout << B;
}


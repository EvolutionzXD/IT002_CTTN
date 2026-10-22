#include <bits/stdc++.h>
#include "DaThuc.h"
using namespace std;

int main() {
	long long x;
	
	DaThuc P1, P2;
	cin >> P1;
	cin >> P2;
	cin >> x;
	
	cout << "\n--- KET QUA ---\n";
	cout << "P1: " << P1 << endl;
	cout << "P2: " << P2 << endl;
	cout << "P1 + P2: " << (P1 + P2) << endl;
	cout << "P1 - P2: " << (P1 - P2) << endl;
	cout << "Gia tri P1(" << x << ") = " << P1.calculate(x) << endl;
	
	return 0;
}

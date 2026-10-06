#include <bits/stdc++.h>
#include "matrix.h"
using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	matrix a, b;
	a.read();
	b.read();
	
	(a + b).print(); cout <<endl;
	(a - b).print(); cout << endl;
	(a ^ b).print(); cout <<endl;
	
}
/*
4 4
1 2 3 4
2 2 2 2
3 2 1 4
4 1 1 0
4 4
2 2 6 1
1 1 3 2 
9 0 1 2
2 2 2 2

*/

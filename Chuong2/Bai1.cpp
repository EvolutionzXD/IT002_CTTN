#include <bits/stdc++.h>
#include "fraction.h"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	fraction x, y;
	x.read();
	y.read();
	
	(x + y).print();
	(x - y).print();
	(x * y).print();
	(x / y).print();
}



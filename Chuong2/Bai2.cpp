#include <bits/stdc++.h>
#include "fraction.h"
using namespace std;

int n;
vector <fraction> fractions;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i ++ ){
		fraction f;
		f.read();
		fractions.push_back(f);
	}
	
	fraction best, sum;
	
	for (int i = 0; i < n; i ++ ){
		maximize(best, fractions[i]);
		sum = sum + fractions[i];
	}
	
	sum.print();
	best.print();
}


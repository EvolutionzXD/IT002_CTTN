#include <bits/stdc++.h>
using namespace std;

class DaThuc{
private:
	int n;
	long long *a;
public:
	DaThuc(int _n = 0){
		n = _n;
		a = new long long[n+1]();
	}
	DaThuc(const DaThuc &other) {
		n = other.n;
		a = new long long[n + 1];
		for (int i = 0; i <= n; i++) {
			a[i] = other.a[i];
		}
	}
	~DaThuc(){
		delete[] a;
	}
	
	long long calculate(long long x)const{
		long long res = 0;
		long long x_i = 1;
		for (int i = n; i >= 0; i -- ){
			res += x_i*a[i];
			x_i = x_i * x;
		}
		return res;
	}
	
	friend istream& operator >> (istream &inp, DaThuc &A);
	friend ostream& operator << (ostream &out, const DaThuc &A);
	friend DaThuc operator + (const DaThuc &A, const DaThuc &B);
	friend DaThuc operator - (const DaThuc &A, const DaThuc &B);
};
istream& operator >> (istream &inp, DaThuc &A){
	inp >> A.n;
	delete[] A.a;
	A.a = new long long[A.n+1];
	
	for (int i = 0; i <= A.n; i ++ )
		inp >> A.a[i];
	return inp;
}
ostream& operator << (ostream &out, const DaThuc &A){
	out << "P(X)=";
	bool ok = 0;
	for (int i = 0; i <= A.n; i ++ ){
		if (A.a[i] == 0) continue;
		if (A.a[i] > 0 && (i != 0)) out <<" + ";
		if (A.a[i] < 0) out << " - "; 
		if (abs(A.a[i]) != 1 || i == A.n) out << abs(A.a[i]);
		if (i != A.n)out <<"x";
		if (A.n-i > 1) out << "^"<<A.n-i;
		ok = 1;
	}
	if (!ok){
		out << 0;
		return out;
	}
	return out;
}
DaThuc operator + (const DaThuc &A, const DaThuc &B){
	DaThuc res(max(A.n, B.n));
	
	for (int i = 0; i <= res.n; i ++ ){
		if (i - res.n + A.n >= 0) res.a[i] += A.a[i - res.n + A.n];
		if (i - res.n + B.n >= 0) res.a[i] += B.a[i - res.n + B.n];
	}
	return res;
}
DaThuc operator - (const DaThuc &A, const DaThuc &B){
	DaThuc res(max(A.n, B.n));
	
	for (int i = 0; i <= res.n; i ++ ){
		if (i - res.n + A.n >= 0) res.a[i] += A.a[i - res.n + A.n];
		if (i - res.n + B.n >= 0) res.a[i] -= B.a[i - res.n + B.n];
	}
	return res;
}

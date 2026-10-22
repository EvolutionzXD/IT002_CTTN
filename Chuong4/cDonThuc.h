#include <bits/stdc++.h>
using namespace std;

class cDonThuc{
private:
	long long a, b;
public:
	cDonThuc(long long _a = 0, long long _b = 0){
		a = _a;
		b = _b;
	}
	double calculate(double x) const{
		double res = 1;
		long long _b = b;
		if (b < 0){
			x = 1/x;
			_b = -b;
		}
		while (b > 0){
			if (b % 2 ) res *= x;
			
			x = x * x;
			_b /= 2;
		}
		return a*res;
	}
	cDonThuc DaoHam() const{
		if (b == 0) return cDonThuc(0, 0);
		return cDonThuc(a*b, b-1);
	}
	friend istream& operator >> (istream &inp, cDonThuc &A);
	friend ostream& operator << (ostream &out, const cDonThuc &A);
	friend cDonThuc operator + (const cDonThuc &A,const cDonThuc &B);
};
istream& operator >> (istream &inp, cDonThuc &A){
	inp >> A.a >> A.b;
	return inp;
}
ostream& operator << (ostream &out, const cDonThuc &A){
	out << A.a <<"x^"<<A.b;
	return out;
}
cDonThuc operator + (const cDonThuc &A,const cDonThuc &B){
	return cDonThuc(A.a + B.a, A.b);
}

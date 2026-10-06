#include <bits/stdc++.h>
using namespace std;

class fraction{
private:
	long long x, y;
public:
	fraction(long long _x = 0, long long _y = 1){
		long long gcd = __gcd(abs(_x), abs(_y));
		x = _x/gcd; y = _y/gcd;
		if (y < 0){
			x = -x;
			y = -y;
		}
	}
	void read(){
		cin >> x >> y;
		long long gcd = __gcd(abs(x), abs(y));
		x = x/gcd; y = y/gcd;
		if (y < 0){
			x = -x;
			y = -y;
		}
	}
	void print() const{
		cout << x <<"/" << y <<"\n";
	}
	
	long long getX() const { return x; }
	long long getY() const { return y; }
	
	fraction operator + (const fraction other) const{
		return fraction((x*other.y+other.x*y), y*other.y);
	}	
	fraction operator - (const fraction other) const{
		return fraction((x*other.y-other.x*y), y*other.y);
	}
	fraction operator * (const fraction other) const{
		return fraction((x*other.x), y*other.y);
	}
	fraction operator / (const fraction other) const{
		return fraction((x*other.y), y*other.x);
	}
};
bool maximize(fraction &A, fraction &B){
	if (A.getX()*B.getY() < A.getY()*B.getX()) return A = B, true; return false;
}
bool minimize(fraction &A, fraction &B){
	if (A.getX()*B.getY() > A.getY()*B.getX()) return A = B, true; return false;
}


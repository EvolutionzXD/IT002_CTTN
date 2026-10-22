#include <bits/stdc++.h>
using namespace std;

class SoPhuc{
private:
	double x, y;
public:
	SoPhuc(double _x = 0, double _y = 0){
		x = _x;
		y = _y;
	}
	
	friend istream& operator >> (istream& inp, SoPhuc &A){
		inp >> A.x >> A.y;
		return inp;
	}
	friend ostream& operator << (ostream& out, const SoPhuc &A){
		out << "(" << A.x <<"," <<A.y <<")";
		return out; 
	}
	friend SoPhuc operator + (const SoPhuc &A, const SoPhuc &B){
		return SoPhuc(A.x+B.x, A.y+B.y);
	}
	friend SoPhuc operator - (const SoPhuc &A, const SoPhuc &B){
		return SoPhuc(A.x-B.x, A.y-B.y);
	}
	friend SoPhuc operator * (const SoPhuc &A, const SoPhuc &B){
		return SoPhuc(A.x*B.x-A.y*B.y, A.x*B.y+A.y*B.x);
	}
	friend SoPhuc operator / (const SoPhuc &A, const SoPhuc &B){
		return SoPhuc((A.x*B.x+A.y*B.y)/(B.x*B.x+B.y*B.y), (A.y*B.x-A.x*B.y)/(B.x*B.x+B.y*B.y));
	}
	friend bool operator == (const SoPhuc &A, const SoPhuc &B){
		return (A.x == B.x && A.y == B.y);
	}
};

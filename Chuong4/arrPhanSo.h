#include <bits/stdc++.h>
using namespace std;

class PhanSo{
private:
	int tu, mau;
	void fixed(){
		int d = __gcd(abs(tu), abs(mau));
		if (mau < 0){
			tu = -tu;
			mau = -mau;
		}
		tu /= d;
		mau /= d;
	}
public:
	PhanSo(int x = 0, int y = 1){
		tu = x;
		mau = y;
		fixed();
	}

	bool TuPrime(){
		if (tu <= 1) return 0; 
		for (int i = 2; i*i <= tu; i ++ )
			if (tu % i == 0) return 0;
		return 1;
	}	
	friend bool operator < (const PhanSo &A, const PhanSo &B); 
	friend ostream& operator << (ostream &out, const PhanSo &A);
	friend istream& operator >> (istream &inp, PhanSo &A);
	friend class arrPhanSo;
};
bool operator < (const PhanSo &A, const PhanSo &B){
	return 1ll*A.tu*B.mau < 1ll*B.tu*A.mau;
}
ostream& operator << (ostream &out, const PhanSo &A){
	out << A.tu <<"/"<<A.mau;
	return out;
}
istream& operator >> (istream &inp, PhanSo &A){
	inp >> A.tu >> A.mau;
	A.fixed(); 
	return inp;
}

class arrPhanSo{
private:
	int n;
	PhanSo *arr;
public:
	arrPhanSo(int _n = 0){
		n = _n;
		arr = new PhanSo[n];
	}
	~arrPhanSo(){
		delete[] arr;
	}
	friend istream& operator >> (istream &inp, arrPhanSo &A);
	friend ostream& operator << (ostream &out, const arrPhanSo &A);
	friend void randomize(const int n, arrPhanSo &A);
	
	PhanSo Max(){
		PhanSo res = arr[0];
		for (int i = 1; i < n; i ++ )
			if (res < arr[i])
				res = arr[i];
		return res;
	}
	
	int CountPrime(){
		int res = 0;
		for (int i = 0; i < n; i ++ )
			if (arr[i].TuPrime()) res ++;
		return res;
	}
	
	void arrPhanSoSort(){
		sort(arr, arr+n);
	}
	
};
istream& operator >> (istream &inp, arrPhanSo &A){
	inp >> A.n; 
	delete[] A.arr;
	A.arr = new PhanSo[A.n];
	for (int i = 0; i < A.n; i ++ )
		inp >> A.arr[i];
	return inp;
}
ostream& operator << (ostream& out, const arrPhanSo &A){
	for (int i = 0; i < A.n; i ++ )
		out << A.arr[i] <<" ";
	return out;
}
void randomize(const int n, arrPhanSo &A){
	A.n = n;
	delete[] A.arr;
	A.arr = new PhanSo[A.n];
	
	for (int i = 0; i < n; i ++ ){
		int t = 1ll * rand() * rand() % 100 + 1;
		int m = 1ll * rand() * rand() % 100 + 1;
		A.arr[i] = PhanSo(t, m); 
	}
}



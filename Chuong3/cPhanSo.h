#include <bits/stdc++.h>
using namespace std;

class cPhanSo{
private:
	long long tu, mau;
	
	void tu_dieu_chinh(){
		if (mau < 0){
			tu = -tu;
			mau = -mau;
		}
		long long gcd = __gcd(abs(tu), abs(mau));
		
		tu /= gcd;
		mau /= gcd;
	}
public:
	cPhanSo(long long _tu = 0, long long _mau = 1){
		tu = _tu; mau = _mau;
		tu_dieu_chinh();
	}
	
	void nhap(){
		cin >> tu >> mau;
		tu_dieu_chinh();
	}
	
	long long layTu() const{
		return tu;
	}
	
	long long layMau() const{
		return mau;
	}
	
	void xuat() const{
		cout <<tu<<"/"<<mau<<"\n";
	}
	
	cPhanSo operator + (const cPhanSo &other) const{
		return cPhanSo((tu*other.mau+mau*other.tu), mau*other.mau);
	}
	
	cPhanSo operator - (const cPhanSo &other) const{
		return cPhanSo((tu*other.mau-mau*other.tu), mau*other.mau);
	}
 	
 	cPhanSo operator * (const cPhanSo &other) const{
		return cPhanSo(tu*other.tu, mau*other.mau);
	}
	
 	cPhanSo operator / (const cPhanSo &other) const{
		return cPhanSo(tu*other.mau, mau*other.tu);
	}
};

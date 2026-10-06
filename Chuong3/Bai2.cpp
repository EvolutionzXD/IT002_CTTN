#include <bits/stdc++.h>
using namespace std;

float PI = 3.14159265;

class DuongTron{
private:
	float TamX, TamY;
	float BanKinh;
public:
	DuongTron(float X = 0, float Y = 0, float r = 0){
		TamX = X;
		TamY = Y;
		BanKinh = r;
	}
	
	void nhap(){
		cin >> TamX >> TamY >> BanKinh;
	}
	
	float DienTich() const{
		return BanKinh*BanKinh*PI;
	}
	float ChuVi() const{
		return 2*BanKinh*PI;
	}
	
	void xuat(){
		cout << "Chu vi: " << ChuVi() <<"\n";
		cout << "Dien tich: " << DienTich() <<"\n";
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	DuongTron A;
	A.nhap();
	A.xuat()
;}


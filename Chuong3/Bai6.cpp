#include <bits/stdc++.h>
using namespace std;

class soPhuc{
private:
	float thuc, ao;
public:
	soPhuc(float _thuc = 0, float _ao = 0){
		thuc = _thuc;
		ao = _ao;
	}
	void thayPhanThuc(float _thuc = 0){
		thuc = _thuc;
	}
	void thayPhanAo(float _ao = 0){
		ao = _ao;
	}
	float layThuc() const{
		return thuc;
	}
	float layAo() const{
		return ao;
	}
	
	void nhap(){
		cin >> thuc >> ao;
	}
	void xuat(){
		cout << "(" <<thuc <<"," << ao <<")"<<endl;
	}
	soPhuc operator + (const soPhuc &other) const{
		return soPhuc(thuc + other.thuc, ao + other.ao);
	}
	soPhuc operator - (const soPhuc &other) const{
		return soPhuc(thuc - other.thuc, ao - other.ao);
	}
	soPhuc operator * (const soPhuc &other) const{
		return soPhuc(thuc*other.thuc-ao*other.ao, thuc*other.ao+ao*other.thuc);
	}
	soPhuc operator / (const soPhuc &other) const{
		return soPhuc((thuc*other.thuc+ao*other.ao)/(other.ao*other.ao+other.thuc*other.thuc), (ao*other.thuc-thuc*other.ao)/(other.ao*other.ao+other.thuc*other.thuc));
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	soPhuc A, B;
	A.nhap();
	B.nhap();
	
	cout << "A = "; A.xuat();
	cout << "B = "; B.xuat();
	
	cout << "A + B = "; (A + B).xuat();
	cout << "A - B = "; (A - B).xuat();
	cout << "A * B = "; (A * B).xuat();
	cout << "A / B = "; (A / B).xuat();
}


#include <bits/stdc++.h>
using namespace std;

string XL[6] = {"Kem", "Yeu", "Trung binh", "Kha", "Gioi", "Xuat Sac"};
float Moc[7] = {0, 3.5, 5, 6.5, 8, 9, 10};
class student{
private:
	string HoTen;
	float DiemToan, DiemVan;
public:
	student(string _HoTen = "N/A", float _DiemToan = 0, float _DiemVan = 0){
		HoTen = _HoTen;
		DiemToan = _DiemToan;
		DiemVan = _DiemVan;
	}
	
	void nhap(){
		cin >> HoTen >> DiemToan >> DiemVan;
	}
	
	float TrungBinh() const{
		return (DiemToan + DiemVan)/2;
	}
	
	string XepLoai(){
		float TB = TrungBinh();
		int iXepLoai = 0;
		while(iXepLoai + 1 < 7 && TB >= Moc[iXepLoai + 1])
			iXepLoai ++;
		return XL[iXepLoai];
	}
	
	void xuat(){
		cout <<"Diem trung binh: " << TrungBinh() <<"\n";
		cout <<"Diem xep loai: " << XepLoai() <<"\n";
		
		 
	}
	
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	student A;
	A.nhap();
	A.xuat();
}


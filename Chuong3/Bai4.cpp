#include <bits/stdc++.h>
using namespace std;

class cArray{
private:
	int n;
	int* arr;
public:
	cArray(int size = 0){
		n = size;
		arr = new int[n];
		srand(time(0));
		
		for (int i = 0; i < n; i ++ )
			arr[i] = rand() - RAND_MAX/2;
	}
	
	~cArray() {
		delete[] arr;
	}
	
	void xuat() const{
		cout <<"{ ";
		for (int i = 0; i < n; i ++ )
			cout << arr[i] <<" ";
		cout <<"}\n";
	}
	
	int SoAmLonNhat(){
		int x = 1;
		for (int i = 0; i < n; i ++ )
			if (arr[i] < 0)
				if (x == 1) x = arr[i];
				else x = max(x, arr[i]);
		
		if (x == 1) return 1e9;
		else return x;
	}
	
	int find(int x){
		int count = 0;
		
		for (int i = 0; i < n; i ++ )
			if (arr[i] == x)
				count ++;
		
		return count;
	}
	
	bool DangGiamDan(){
		for (int i = 0; i < n - 1; i ++ )
			if (arr[i] < arr[i + 1]) return false;
		return true;
	}
	
	void SapXep(int L, int R){
		
		if (L >= R) return;
		
		int mid = arr[(L + R)/2];
		
		int j = L;
		for (int i = L; i <= R; i ++ ){
			if (arr[i] <= mid){
				swap(arr[j], arr[i]);
				j ++;
			}
		}
		
		SapXep(L, j - 2);
		SapXep(j, R);
	}
	
	void SapXep(){
		for (int i = 1; i <= 2*n; i ++ ){
			int x = 1ll*rand()*rand()%n;
			int y = 1ll*rand()*rand()%n;
			swap(arr[x], arr[y]);
		}
		
		SapXep(0, n - 1);
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n = 10;
	cArray X(10);
	
	X.xuat();
	cout <<"So am lon nhat: " << X.SoAmLonNhat() <<"\n";
	int x = 5;
	cout <<"So lan xuat hien cua so nguyen " << x <<": " << X.find(x) <<"\n";
	cout <<"Mang co giam dan khong?" << X.DangGiamDan() <<"\n";
	X.SapXep();
}


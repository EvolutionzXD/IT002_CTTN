#include <bits/stdc++.h>
using namespace std;

class cArray{
private:
	int n;
	int *arr;
public:
	cArray(int _n = 0){
		n = _n;
		arr = new int[n];
	}
	~cArray(){
		delete[] arr;
	}
	friend istream& operator >> (istream &inp, cArray &a);
	friend ostream& operator << (ostream &out, const cArray &a);
	friend void randomize (const int n,  cArray &a);
	
	int count(int X){
		int res = 0;
		for (int i = 0; i < n; i ++ )
			res += (X==arr[i]);
		return res;
	}
	bool isIncrease(){
		for (int i = 0; i < n - 1; i ++ )
			if (arr[i] > arr[i + 1]) return 0;
		return 1;	
	}
	int findOddMin(){
		int Min = 1e9 + 7;
		bool ok = 0;
		for (int i = 0; i < n; i ++ )
			if (arr[i] % 2 == 1 && Min > arr[i])
				Min = arr[i], ok = 1;
		if (ok == 0){
			cout <<"Khong co so le :/";
		}
		return Min;
	}
	void cArraySort(){
		sort(arr, arr + n);
	}
};
istream& operator >> (istream &inp, cArray &a){
	inp >> a.n;
	delete[] a.arr;
	a.arr=new int[a.n];
	for (int i = 0; i <	 a.n; i ++ )
		inp >> a.arr[i];
	return inp;
}
ostream& operator << ( ostream &out, const cArray &a){
	for (int i = 0; i < a.n; i ++ )
		out << a.arr[i] <<" ";
	out <<"\n";
	return out;
}
void randomize (const int n, cArray &a){
	a.n = n;
	delete[] a.arr;
	a.arr = new int[n];
	for (int i = 0; i < n; i ++ )
		a.arr[i] = 1ll * rand() * rand() * rand() % 1000000007;
}


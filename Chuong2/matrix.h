#include <bits/stdc++.h>
using namespace std;

class matrix{
private:
	int n, m;
	vector<vector<float>> arr;
public:
	matrix(int _n = 0, int _m = 0, float value = 0.0){
		n = _n; m = _m;
		arr.assign(n, vector <float> (m, 0.0f));
	}
	void read(){
		cin >> n >> m;
		arr.assign(n, vector <float> (m, 0.0f));
		
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < m; j ++ )
				cin >> arr[i][j];	
	}
	void print() const{
		for (int i = 0; i < n; i ++ ){
			cout << "| ";
			for (int j = 0; j < m; j ++ )
				cout << arr[i][j] <<" ";
			cout << "|\n";	
		} 
	}
	
	matrix operator + (const matrix &other) const{
		matrix res(n, m);
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < m; j ++ )
				res.arr[i][j] = arr[i][j] + other.arr[i][j];
		return res;
	}	
	matrix operator - (const matrix &other) const{
		matrix res(n, m);
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < m; j ++ )
				res.arr[i][j] = arr[i][j] - other.arr[i][j];
		return res;
	}
	matrix operator * (const matrix &other) const{
		matrix res(n, m);
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < m; j ++ )
				res.arr[i][j] = arr[i][j] * other.arr[i][j];
		return res;
	}
	matrix operator ^ (const matrix &other) const{
		matrix res(n, other.m, 0);
		
		for (int i = 0; i < n; i ++ )
			for (int j = 0; j < other.m; j ++ )
				for (int h = 0; h < m; h ++ )
					res.arr[i][j] += arr[i][h]*other.arr[h][j];
					
		return res; 
	}
	
	matrix T() const{
		matrix res(m, n);
		
		for (int i = 0; i < m; i ++ )
			for (int j = 0; j < n; j ++ )
				res.arr[i][j] = arr[j][i];
		
		return res;
	}
};

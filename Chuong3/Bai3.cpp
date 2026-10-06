#include <bits/stdc++.h>
using namespace std;

class point{
private:
	float x, y;
public:
	point(float _x = 0, float _y = 0){
		x = _x; y = _y;
	}
	
	void nhap(){
		cin >> x >> y;
	}
	
	float distance(const point &other) const{
		return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	point X, Y;
	X.nhap();
	Y.nhap();
	
	cout <<"Khoang cach: " << X.distance(Y);
}


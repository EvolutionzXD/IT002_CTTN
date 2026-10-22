#include <bits/stdc++.h>
#include "cListBook.h"
using namespace std;
int main() {
	cListBook listBook;
	cin >>listBook;
	cout<<listBook<<"\n";
	cout <<"Sach duoc xuat ban gan nhat:\n";
	cout <<listBook.lastest()<<endl;
	return 0;
}

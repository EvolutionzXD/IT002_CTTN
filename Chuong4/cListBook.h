#include <bits/stdc++.h>
using namespace std;

class cBook{
private:
	int id;
	string name;
	int Year;
	int pages;
public:
	cBook(int _id = 0, string _name = "", int _Year = 0, int _pages = 0){
		id = _id;
		name = _name;
		Year = _Year;
		pages = _pages;
	}
	
	friend istream& operator >> (istream &inp, cBook &A);
	friend ostream& operator << (ostream &out,const cBook &A);
	friend class cListBook;
	
	void changeID(const int _id){
		id = _id;
	}
	void changeNAME(const string _name){
		name = _name;
	}
	void changeYEAR(const int _Year){
		Year = _Year;
	}
	void changePAGE(const int _pages){
		pages = _pages;
	}
};
istream& operator >> (istream &inp, cBook &A){
	inp >> A.id >> A.name >> A.Year >> A.pages;
	return inp;
}
ostream& operator << (ostream &out,const cBook &A){
	out <<"Ma sach:"<< A.id <<"|Ten sach:"<< A.name <<"|Nam xuat ban:"<< A.Year <<"|Tong so trang:"<< A.pages;
	return out;
}
class cListBook{
private:
	int n;
	cBook *arr;
public:
	cListBook(int _n = 0){
		n = _n;
		arr = new cBook[n];
	}
	
	~cListBook(){
		delete[] arr;
	}
	
	friend istream& operator >> (istream &inp, cListBook &A);
	friend ostream& operator << (ostream &out,const cListBook &A);
	
	cBook lastest(){
		int id = 0;
		for (int i = 1; i < n; i ++ )
			if (arr[id].Year < arr[i].Year) id = i;
		return arr[id];
	}
};
istream& operator >> (istream &inp, cListBook &A){
	inp >> A.n;
	delete[] A.arr;
	A.arr = new cBook[A.n];
	for (int i = 0; i < A.n; i ++ )
		inp >> A.arr[i];
	return inp;
}
ostream& operator << (ostream &out,const cListBook &A){
	out << "Danh sach: ";
	for (int i = 0; i < A.n; i ++ )
		out << A.arr[i] <<"\n";
	return out;
	
}

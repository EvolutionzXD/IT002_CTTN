#include <bits/stdc++.h>
using namespace std;

class student{
private:
	int id;
	string name, gender;
	int birthYear;
	float score;
	string PhuongThuc;
public:
	student(int _id = 0, string _name = "", string _gender = "",int _birthYear = 0, float _score = 0, string _PhuongThuc = ""){
		id = _id;
		name = _name;
		gender = _gender;
		birthYear = _birthYear;
		score = _score;
		PhuongThuc = _PhuongThuc;
	}
	
	float getID() const{
		return id;
	}
	string getName() const{
		return name;	
	}
	
	string getGender() const{
		return gender;
	}
	
	int getBirthYear() const{
		return birthYear;
	}
	
	float getScore() const{
		return score;
	}
	
	string getPhuongThuc() const{
		return PhuongThuc;
	}
	
	void nhap(){
		cin >> id;
		cin >> name;
		cin >> gender;
		cin >> birthYear;
		cin >> score;
		cin >> PhuongThuc;
	}
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	student A, B;
	
	A.nhap();
	B.nhap();
	string s;	
	if (A.getScore() > B.getScore()){
		s = A.getName();
	}
	else s = B.getName();
	
	cout << "Ban " << A.getName() <<" co diem trung binh cao hon \n";
	
	if (A.getBirthYear() > B.getBirthYear()) s = A.getName();
	else s = B.getName();
	
	cout << "Ban " << B.getName() <<" nho tuoi hon \n";
}


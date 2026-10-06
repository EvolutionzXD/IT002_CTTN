#include <bits/stdc++.h>
using namespace std;

class student{
private:
	int id;
	string name, gender;
	float MathScore, PhysicScore, ChemistryScore;
public:
	student(int _id = 0,string _name = "N/A", string _gender = "N/A", float _MathScore = 0, float _PhysicScore = 0, float _ChemistryScore = 0){
		id = _id;
		name = _name;
		gender = _gender;
		MathScore = _MathScore;
		PhysicScore = _PhysicScore;
		ChemistryScore = _ChemistryScore;
	}
	
	float average() const{
		return (MathScore + PhysicScore + ChemistryScore)/3;
	}
	
	void read(){
		cin >> id >> name >> gender >> MathScore >> PhysicScore >> ChemistryScore;
	}
	
	void print() const{
		cout <<"Ma sinh vien: " << id <<"\n";
		cout <<"Ten: " << name <<"\n";
		cout <<"Gioi tinh: " << gender <<"\n";
		cout <<"Diem toan: " << MathScore <<"\n";
		cout <<"Diem ly: " << PhysicScore <<"\n";
		cout <<"Diem hoa: " << ChemistryScore <<"\n"; 
		cout <<"Diem trung binh: " << average() <<"\n";
	}
		
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	student A;
	A.read();
	A.print();
}

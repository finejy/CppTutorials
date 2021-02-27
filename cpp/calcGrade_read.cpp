#include "calcGrade_studentInfo.h"

using namespace std;

bool compare(const student_info& x, const student_info& y){
	return x.name < y.name;
}

istream& read(istream& is, student_info& s){
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is, s.homework);
}

istream& read_hw(istream& in, vector<double>& hw){
		if(in){
		hw.clear();
		
		double x= 0;
		
		while(in >> x) hw.push_back(x);
		
		in.clear();
	} 
	
	return in;
}

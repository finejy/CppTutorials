#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept> 

using namespace std;

struct student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};

boolfgrade(const student_info& s){
	return grade(s) < 60;
}

vector<student_info> fails(vector<student_info>& students){
	vector<student_info> fail;
	vector<student_info>::iterator iter = students.begin();
	while(iter != students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else ++iter;
	}
	
	return fail;
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

istream& read(istream& is, student_info& s){
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

bool compare(const student_info& x, const student_info& y){
	return x.name < y.name;
}

double grade(double midterm, double final, double homework){
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec){
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	
	//오류 발생(입력값이 없을 때)시 domain_error 을 출 력 
	if(size == 0) throw domain_error("median of an empty vector");
	
	sort(vec.begin(), vec.end());
	/*cout << "median: "<< ends;
	for(int i=0; i!=size; ++i){
		cout << vec[i] << " " << ends;
	}*/
	vec_sz mid = size/2;
	return size%2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

/*해당 함수에서 매개변수를 const 참조로 호출받은 이유는 main 함수에도 hw에 해당하는 함수가 const 벡터일 가능성이 있기 때문이라고 이해됨.*/ 
double grade(double midterm, double final, const vector<double>& hw){
	if(hw.size()==0) throw domain_error("Student has done no homework");
	
	/*cout << "grade : " << ends;
	for(int i=0; i!=hw.size(); ++i){
		cout << hw[i] << " " << ends;
	}
	cout << endl;*/
	/*Question. 매개변수 hw 는 const 참조로 정의되어있는 상황인데, 이 상황에서 median 함수의 매개변수로 hw를 호출받아  함수 내에서 sort 함수를 실행하는 구조인데 
	 	이때 const 함수의 복사본을 정렬하는데 생기는 오류는 없는 것인가?
	  Answer. 가능한 것으로 확인 됨. const 참조에 대한 복사본의 수정은 문제가 없는 것으로 확인.*/ 
	return grade(midterm, final, median(hw));
}

double grade(const student_info& s){
	return grade(s.midterm, s.final, s.homework);
}

/*
int main(){
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	
	cout << "Please enter your midterm and final exam grades : " ;
	double midterm, final;
	cin >> midterm >> final;
	
	cout << "Enter all your homework grades, followed by end-of-file : ";
	vector<double> homework;

	read_hw(cin, homework);
	
	try{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	
	catch (domain_error){
		cout << endl << "You must enter your grades. Please try again." << endl;
		return 1;
	}
	
	return 0;
}*/

int main(){
	vector<student_info> students;
	student_info record;
	string::size_type maxlen = 0;
	
	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	
	sort(students.begin(), students.end(), compare);
	
	for(vector<student_info>::size_type i = 0; i!=students.size(); ++i){
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		
		try{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	} 
	
	return 0;
}

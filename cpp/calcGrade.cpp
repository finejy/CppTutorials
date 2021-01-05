#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
	
using namespace std;

int main(){
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	
	cout << "Please enter your medterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";
	vector<double> homework;
	double x;
	
	while (getline(cin, x)){		
		homework.push_back(x);	
	}
	/*이 부분은 개선이 필요할듯. 이렇게 되면 double 타입 이외의 입력이 들어와야 입력이 끝남.(공백과 줄바꿈으로는 종료되지 않음) 
	  가장 깔끔한건 엔터 입력시 입력이 종료되는 것.*/
	  
	/*while (getline(cin, x){
		homework.push_back(x);
	}
	이 경우 x가 double 타입이라는 문제가 발생. 이때문에 x를 string타입으로 정의, push_back 전에 int로 변환할 경우 연산이 많아진다는 문제 발생.
	## getline의 문제점. '공백'을 포함한 데이터를 입력받는 것이므로 string일 수 밖에 없음... 
	*/ 
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if(size == 0){
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}
	
	sort (homework.begin(), homework.end());
	
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
		: homework[mid];
	//조건문을 사용하는 특이한 방식. if 문이 없어지면 코드가 깔끔해 지니깐 기억할 것. 
	
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
	
	return 0;
}

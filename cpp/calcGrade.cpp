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
	/*
	while (cin >> x){		
		homework.push_back(x);	
	}
	/*이 부분은 개선이 필요할듯. 이렇게 되면 double 타입 이외의 입력이 들어와야 입력이 끝남.(공백과 줄바꿈으로는 종료되지 않음) 
	  가장 깔끔한건 엔터 입력시 입력이 종료되는 것.*/
	  
	/*while (getline(cin, x){
		homework.push_back(x);
	}
	이 경우 x가 double 타입이라는 문제가 발생. 이때문에 x를 string타입으로 정의, push_back 전에 int로 변환할 경우 연산이 많아진다는 문제 발생.
	## getline의 문제점. '공백'을 포함한 데이터를 입력받는 것이므로 string일 수 밖에 없음... 
	## 애초에 공백을 포함한 string을 정의한다 하더라도 그 string에 줄바꿈 문자가 포함되지 않인을 가능성이 높음 (testCode.cpp에서 확)
	##### 해당 코드의 문제는 오로지 입력을 while문의 조건으로써 사용했다는 것인듯 하다. cin 함수는 줄바꿈이나 공백 문자(whitespace)를 인식하지만,
		반복문이 언제 끝날지 확인할 수 없으므로 줄바꿈을 하더라도 오류가 계속 발생하는 것. 따라서 따로 homework의 갯수를 입력받는 과정을 추가하는 것이 최선. 
	*/  
	
	while(true){
		cin >> x;
		if(cin.eof() == true){
			break;
		}
		homework.push_back(x);
		
	}
	/*eof 함수를 이용하여 줄바꿈이 일어났을 때 end-of-file로 인식을 하여 반복문이 종료되는지 확인.
		결과 줄바꿈을 eof를 인식하지 못해 무한 루프에 빠지는 것을 확인할 수 있었음.*/ 
	
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

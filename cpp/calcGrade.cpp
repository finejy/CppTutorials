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
	/*�� �κ��� ������ �ʿ��ҵ�. �̷��� �Ǹ� double Ÿ�� �̿��� �Է��� ���;� �Է��� ����.(����� �ٹٲ����δ� ������� ����) 
	  ���� ����Ѱ� ���� �Է½� �Է��� ����Ǵ� ��.*/
	  
	/*while (getline(cin, x){
		homework.push_back(x);
	}
	�� ��� x�� double Ÿ���̶�� ������ �߻�. �̶����� x�� stringŸ������ ����, push_back ���� int�� ��ȯ�� ��� ������ �������ٴ� ���� �߻�.
	## getline�� ������. '����'�� ������ �����͸� �Է¹޴� ���̹Ƿ� string�� �� �ۿ� ����... 
	## ���ʿ� ������ ������ string�� �����Ѵ� �ϴ��� �� string�� �ٹٲ� ���ڰ� ���Ե��� ������ ���ɼ��� ���� (testCode.cpp���� Ȯ)
	##### �ش� �ڵ��� ������ ������ �Է��� while���� �������ν� ����ߴٴ� ���ε� �ϴ�. cin �Լ��� �ٹٲ��̳� ���� ����(whitespace)�� �ν�������,
		�ݺ����� ���� ������ Ȯ���� �� �����Ƿ� �ٹٲ��� �ϴ��� ������ ��� �߻��ϴ� ��. ���� ���� homework�� ������ �Է¹޴� ������ �߰��ϴ� ���� �ּ�. 
	*/  
	
	while(true){
		cin >> x;
		if(cin.eof() == true){
			break;
		}
		homework.push_back(x);
		
	}
	/*eof �Լ��� �̿��Ͽ� �ٹٲ��� �Ͼ�� �� end-of-file�� �ν��� �Ͽ� �ݺ����� ����Ǵ��� Ȯ��.
		��� �ٹٲ��� eof�� �ν����� ���� ���� ������ ������ ���� Ȯ���� �� �־���.*/ 
	
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
	//���ǹ��� ����ϴ� Ư���� ���. if ���� �������� �ڵ尡 ����� ���ϱ� ����� ��. 
	
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;
	
	return 0;
}

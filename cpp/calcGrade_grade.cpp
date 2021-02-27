#include <stdexcept>
#include <vector>
#include "calcGrade_grade.h"
#include "calcGrade_median.h"
#include "calcGrade_studentInfo.h"

using namespace std;

double grade(double midterm, double final, double homework){
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){
	if(hw.size()==0) throw domain_error("Student has done no homework");
	
	/*cout << "grade : " << ends;
	for(int i=0; i!=hw.size(); ++i){
		cout << hw[i] << " " << ends;
	}
	cout << endl;*/
	/*Question. �Ű����� hw �� const ������ ���ǵǾ��ִ� ��Ȳ�ε�, �� ��Ȳ���� median �Լ��� �Ű������� hw�� ȣ��޾�  �Լ� ������ sort �Լ��� �����ϴ� �����ε� 
	 	�̶� const �Լ��� ���纻�� �����ϴµ� ����� ������ ���� ���ΰ�?
	  Answer. ������ ������ Ȯ�� ��. const ������ ���� ���纻�� ������ ������ ���� ������ Ȯ��.*/ 
	return grade(midterm, final, median(hw));
}

double grade(const student_info& s){
	return grade(s.midterm, s.final, s.homework);
}

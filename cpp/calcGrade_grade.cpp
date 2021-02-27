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
	/*Question. 매개변수 hw 는 const 참조로 정의되어있는 상황인데, 이 상황에서 median 함수의 매개변수로 hw를 호출받아  함수 내에서 sort 함수를 실행하는 구조인데 
	 	이때 const 함수의 복사본을 정렬하는데 생기는 오류는 없는 것인가?
	  Answer. 가능한 것으로 확인 됨. const 참조에 대한 복사본의 수정은 문제가 없는 것으로 확인.*/ 
	return grade(midterm, final, median(hw));
}

double grade(const student_info& s){
	return grade(s.midterm, s.final, s.homework);
}

#include <iostream>

using namespace std;

long long solution(int n){
	long long answer = 0;
	long long each_case = 1;
	int case_num = n / 2;

	
	for(int i=0; i!=case_num+1; ++i){
		int j = n - i*2;
		if(i==0 || j==0) ++answer;
		else{
			each_case=((each_case*(n-2*i+2))*(n-2*i+1))/(i*(n-i+1));
			answer+=each_case;
		}
		//cout << i << " " << each_case << " " << answer << " " << endl;
		//cout << (n-2*i+2) << " " << (n-2*i+1) << " " << i << " " <<(n-i+1) << endl;
		//cout << i << " " << j << " " << i+j << " " << each_case << endl;
	}
	
	//cout << answer<< endl;
	
	return answer % 1000000007;
}

//solution2. 정직하게 계산해보자."floating point exception 에러 발생. 아마 long long  이상의 값을 연산하면서 음수값, 0을 나눗셈 수식에 대입하면서 발생하는 듯 하다.
//+ 시간 초과 에러 발생.  
/*


long long calc(int a, int b){
	int maximum = max(a, b);
	int minimum = min(a, b);
	long long result_1 = 1;
	long long result_2 = 1;
	long long result = 0;
	for(int i=maximum+1; i!=maximum+minimum+1; ++i){
		result_1*=i;
		result_2*=i-maximum;
	}
	result = result_1/result_2;
	
	return result;
}


long long solution(int n){
	long long answer = 0;
	int case_num = n / 2;
	
	for(int i=0; i!=case_num+1; ++i){
		int j = n - i*2;
		
		long long calculate = calc(i, j);
		
		answer+=calculate;
		//cout << answer << endl;
	}
	
	return answer;
	
} */


int main(){
	int n;
	cin >> n;
	cout << solution(n) << endl;
	
	return 0;
}

/*Solution:가로로 배치하는 타일의 갯수 별로 각 상황의 타일 배치 경우의 수
 를 계산, 총합을 결과값으로 출력*/ 
 
//논리 자체에 문제는 없는 것으로 판단.
//산수 과정에서 오류 발생. 나눗셈의 존재 때문에 발생하는 오류일 것으로 예상.(곱셈과 나눗셈의 순서 문제.) 
//상정한 경우에 대해서는 코드가 성공하는 것을 확인했지만 실제 테스트 문제는 전부 실패. for문으로 반복하는 방법을 사용해봐야 할 것으로 판단됨. 

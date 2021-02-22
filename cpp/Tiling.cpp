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
			long long each_calc = (n-i+1)*(n-i))/(i*(n-i+1));
			each_case*=each_calc;
			answer+=each_case;
		}
		cout << i << " " << each_case << " " << answer << " " << endl;
	}
	
	
	return answer % 1000000007;
}

//testcode
long long test(int n){
	long long iNum = 1;
	long long jNum = 1;
	long long tNum = 1;
	for(int i=1; i!=11; ++i){
		iNum*=i;
	}
	for(int j=1; j!=n-9; ++j){
		jNum*=j;
	}
	for(int k=1; k!=n+1; ++k){
		tNum*=k;
	}
	
	long long answer = tNum/(iNum*jNum);
	
	cout << answer << endl;
	return answer;
	
} 

int main(){
	int n;
	cin >> n;
	cout << solution(n)<< " " << test(n) << endl;
	
	return 0;
}

/*Solution:가로로 배치하는 타일의 갯수 별로 각 상황의 타일 배치 경우의 수
 를 계산, 총합을 결과값으로 출력*/ 
 
//논리 자체에 문제는 없는 것으로 판단.
/*입력하는 n값이 커지면 each_case에 음수값이 나타남. null값의 영향인듯함. 
	-> each_case와 answer의 타입문제였음. int 타입으로 대입하기엔 값이 너무 큼. */
//타입을 long long 으로 바꿔도 오류 발생. 아마도 큰 값을 계산하기 위한 다른 대처가  팔요한 것으로 보임 

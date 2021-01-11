#include <iostream>

using namespace std;

long long solution(int n){
	long long answer = 0;
	
	int case_num = n / 2;
	
	for(int i=0; i!=case_num+1; ++i){
		long long space = 0;
		long long each_case = 1;
		space = n - i;
		if(i==0){
			answer+=1;
			continue;   
		}
		
		for(int j=0; j!=i; ++j){
			each_case=each_case * (space - j) / (j + 1);
		 //if(i == 7) cout << space - j << " " << j + 1 << " " << each_case << endl;
		}
		//cout << each_case << endl;
		answer += each_case % 1000000000;
	}
	
	return answer % 1000000007;
}

int main(){
	int n;
	cin >> n;
	cout << solution(n)<<endl;
	
	return 0;
}

/*Solution:가로로 배치하는 타일의 갯수 별로 각 상황의 타일 배치 경우의 수
 를 계산, 총합을 결과값으로 출력*/ 
 
//논리 자체에 문제는 없는 것으로 판단.
/*입력하는 n값이 커지면 each_case에 음수값이 나타남. null값의 영향인듯함. 
	-> each_case와 answer의 타입문제였음. int 타입으로 대입하기엔 값이 너무 큼. */
//타입을 long long 으로 바꿔도 오류 발생. 아마도 큰 값을 계산하기 위한 다른 대처가  팔요한 것으로 보임 

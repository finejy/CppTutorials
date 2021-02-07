#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long ternary(int n){
	string str_result="";
    
	int i=1;
	while(n>0){
		str_result= str_result + to_string(n%3);
		n/=3;
	}
    long long result = stoll(str_result);
	return result;
	
}
/*원래 3진법 계산과 앞뒤 반전을 위한 함수를 각각 설정했지만, 한꺼번에 진행하는 코드로 변경 
long long opposite(string t){
	string::size_type len = t.size();
	string str_result="";
	
	for(int i=0; i!=len; ++i){
		str_result+=t.at(len-1-i);
	}
	
	long long result=stoll(str_result);
	
	return result;
}*/

int decimal(long long n){
	int result=0;
	long long num = n;
	int term=1;
	
	while(num!=0){
		result+=num%10*term;
		num/=10;
		term*=3;
	}
	return result;
	
}

int solution(int n) {
    int answer = 0;
    if(n==0){
    	return 0;
	} 
    long long ter=0;
    ter = ternary(n);
    answer = decimal(opp);
    return answer;
}

int solution(int n) {
    int answer = 0;
    string ter="";
    long long opp=0;
    cout << answer << endl;
    ter = ternary(n);
    cout << ter << endl;
    opp = opposite(ter);
    cout << opp << endl;
    answer = decimal(opp);
    cout << answer << endl;
    return answer;
}


int main(){
	int n=0;
	cin >> n;
	solution(n);
	return 0;
}

/*특정 상황에서 aborted(core dumped) 에러 발생. 확인 결과 stoi 함수를 사용할 때 수가 큰 경우 out of range 문제가 발생하여 생기는 문제로 확인됨. 결과값을 
	double로 바꾸면 에러는 해결이 되는데 core dumped 에러가발생했던 case에 한해서는 결과가 실패로 출력되는 문제 확인. decimal 함수에서 double을 int로 
	바꾸는 과정에서 double의 값이 int의 범위 이상일 경우 문제가 생기는 것으로 판단됨.->double 대신 long long 타입을 사용해서 문제 해결.*/ 
/*core dumped 에러를 해결했음에도 실패 상황 발생-> 코드 오류(long long이 아니라 double 사용) */

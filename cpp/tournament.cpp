//#코딩테스트 #C++ #2단계 #예상 대진표 #Clear!
#include <iostream>

using namespace std;

int next_round(int& x){
	x=(x+1)/2;
	return x;
}

int solution(int n, int a, int b){
	int answer=0;
	
	while(a!=b){
		next_round(a);
		next_round(b);
		++answer;
	}
	
	return answer;
}

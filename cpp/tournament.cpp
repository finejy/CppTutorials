//#�ڵ��׽�Ʈ #C++ #2�ܰ� #���� ����ǥ #Clear!
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

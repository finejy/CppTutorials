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
/*���� 3���� ���� �յ� ������ ���� �Լ��� ���� ����������, �Ѳ����� �����ϴ� �ڵ�� ���� 
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

/*Ư�� ��Ȳ���� aborted(core dumped) ���� �߻�. Ȯ�� ��� stoi �Լ��� ����� �� ���� ū ��� out of range ������ �߻��Ͽ� ����� ������ Ȯ�ε�. ������� 
	double�� �ٲٸ� ������ �ذ��� �Ǵµ� core dumped �������߻��ߴ� case�� ���ؼ��� ����� ���з� ��µǴ� ���� Ȯ��. decimal �Լ����� double�� int�� 
	�ٲٴ� �������� double�� ���� int�� ���� �̻��� ��� ������ ����� ������ �Ǵܵ�.->double ��� long long Ÿ���� ����ؼ� ���� �ذ�.*/ 
/*core dumped ������ �ذ��������� ���� ��Ȳ �߻�-> �ڵ� ����(long long�� �ƴ϶� double ���) */

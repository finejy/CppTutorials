#include <iostream>

using namespace std;
/*
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
}*/

//solution2. �����ϰ� ����غ���.

long long calc(int n){
	long long result = 1;
	if(n==0) return 1;
	else{
		for(int i=1; i!=n+1; ++i){
			result*=i;
		}
	}
	cout << result << endl;
	
	return result;
}


long long solution(int n){
	long long answer = 0;
	int case_num = n / 2;
	
	for(int i=0; i!=case_num+1; ++i){
		int j = n - i*2;
		
		long long calculate = calc(i+j)/(calc(i)*calc(j));
		
		answer+=calculate;
		//cout << answer << endl;
	}
	
	return answer;
	
	
	
} 


int main(){
	int n;
	cin >> n;
	cout << solution(n) << endl;
	
	return 0;
}

/*Solution:���η� ��ġ�ϴ� Ÿ���� ���� ���� �� ��Ȳ�� Ÿ�� ��ġ ����� ��
 �� ���, ������ ��������� ���*/ 
 
//�� ��ü�� ������ ���� ������ �Ǵ�.
//��� �������� ���� �߻�. �������� ���� ������ �߻��ϴ� ������ ������ ����.(������ �������� ���� ����.) 
//������ ��쿡 ���ؼ��� �ڵ尡 �����ϴ� ���� Ȯ�������� ���� �׽�Ʈ ������ ���� ����. for������ �ݺ��ϴ� ����� ����غ��� �� ������ �Ǵܵ�. 

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

/*Solution:���η� ��ġ�ϴ� Ÿ���� ���� ���� �� ��Ȳ�� Ÿ�� ��ġ ����� ��
 �� ���, ������ ��������� ���*/ 
 
//�� ��ü�� ������ ���� ������ �Ǵ�.
/*�Է��ϴ� n���� Ŀ���� each_case�� �������� ��Ÿ��. null���� �����ε���. 
	-> each_case�� answer�� Ÿ�Թ�������. int Ÿ������ �����ϱ⿣ ���� �ʹ� ŭ. */
//Ÿ���� long long ���� �ٲ㵵 ���� �߻�. �Ƹ��� ū ���� ����ϱ� ���� �ٸ� ��ó��  �ȿ��� ������ ���� 

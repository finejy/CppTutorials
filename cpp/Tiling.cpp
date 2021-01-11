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

/*Solution:���η� ��ġ�ϴ� Ÿ���� ���� ���� �� ��Ȳ�� Ÿ�� ��ġ ����� ��
 �� ���, ������ ��������� ���*/ 
 
//�� ��ü�� ������ ���� ������ �Ǵ�.
/*�Է��ϴ� n���� Ŀ���� each_case�� �������� ��Ÿ��. null���� �����ε���. 
	-> each_case�� answer�� Ÿ�Թ�������. int Ÿ������ �����ϱ⿣ ���� �ʹ� ŭ. */
//Ÿ���� long long ���� �ٲ㵵 ���� �߻�. �Ƹ��� ū ���� ����ϱ� ���� �ٸ� ��ó��  �ȿ��� ������ ���� 

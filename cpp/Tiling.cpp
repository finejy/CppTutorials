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

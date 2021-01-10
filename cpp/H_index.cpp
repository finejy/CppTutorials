#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    vector<int>::size_type len = citations.size();

    for(int i=0; i!=len; ++i){
    	//cout << citations[i] << ends;
    	if(i+1 >= citations[i]){
    		answer = citations[i];
    		break;
		}
	}	
	
	return answer;
}

int main(){
	vector<int> citations;

	for(int i=0; i!=5; ++i){
		int x=0;
		cin >> x;
		citations.push_back(x);		
	}
	cout << solution(citations) << endl;
}

/* Solution : �Է� ���� vector�� ������������ �����ϰ�, �ش� ��ġ�� index+1�� �ش� ��ġ�� ���Ұ��� ���Ͽ� h-index���� ����*/
// �⺻ ���̽������� ����. But, �׽�Ʈ���̽������� ���� ����
// answer = i�� ����� �� �� ���� ��� �ܿ��� ���� �����Ͽ���.
 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n){
	vector<string>::size_type len = strings.size();
	
	for(int i=0; i!=len ; ++i){
		strings[i]=strings[i].at(n)+strings[i];
	}
	
	sort(strings.begin(), strings.end());
	
	for(int i=0; i!=len; ++i){
		strings[i].erase(0, 1);
	}
	
	return strings;
}

/*Solution : strings�� ������ ���ҵ��� index n ��ġ�� ���ҵ��� �ش� ���ҵ��� �տ� �̾�ٿ� �����Ͽ� index n�� �������� ���ڸ� ������������ ����,
	������ ���� �Ŀ��� �ٽ� ù ��° ���ڸ� ���� �Ͽ� ���� ���ڷ� �����Ͽ� ����ϴ� �Լ��� ����.*/ 

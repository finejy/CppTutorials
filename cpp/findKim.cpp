#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int answer_index=0;
    
    answer_index=find(seoul.begin(), seoul.end(), "Kim")-seoul.begin();
    
    answer = "�輭���� " + to_string(answer_index) + "�� �ִ�"; 
    
    return answer;
}

/*vector�� ���Ҹ� find �Լ��� �˻��ϴ� ��� �ش� ��ġ�� iterator�� ��µȴ�.
 	�� �� iterator���� ���̸� ����ϸ� �� iterator���� �Ÿ��� ��Ÿ���ٴ� ���� �̿���
	�ش� ��ġ�� index�� �˻��Ѵ�,*/ 

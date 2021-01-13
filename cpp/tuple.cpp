#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
	
	string::size_type len = s.size();
	int element_len = 0;
	int max_element = 0;
	int start_index = 0;
	int max_index = 0;
	
	for(int i=0; i!=len; ++i){
		if(s.at(i) == '}' && max_element < element_len){
			max_element = element_len;
			max_index = start_index;
		}
		else if(s.at(i) == '{'){
			element_len = 0;
			start_index = i;
		}
		else if(s.at(i)!= '}'){
			element_len +=1;
		}
	}
	
	vector<int> answer;
	
	for(int i=0; i!=max_element + 1; ++i){
		if(s.at(max_index+i)==',' || s.at(max_index+i) =='{'){
			int int_element = 0;
			const char *char_element = &s.at(max_index+i+1);
			//char -> const char*
			int_element = atoi(char_element);
			cout << int_element << ends;
			answer.push_back(int_element);
		}
	}

    return answer;
}

int main(){
	string str = "";
	cin >> str;
	solution(str);
	return 0;
}

/*Solution1. ��ü string �߿��� ���̰� ���� �� Ʃ���� ���� index�� �ش�
	tuple�� ���̸� �ް� �ش� ���� ���� int�� ������� ��¹޴´�*/ 

/*#1 string ���� int�� ����ȯ�� �� ���� stoi, char���� int�� atoi�� ���
	-> atoi���� �Է¹޴� char���� const char*�� ���·� ������ �־�� ��*/
/*Q1 34������ s.at(max_index + i)�� char_element�� ������ �޾Ҵµ� �� 
	max_index + i ��ġ�� �ִ� ���� �ϳ��� �ƴ϶� ����� ���� ��ü�� ��µǴ°�
	ex) cin >> "{{123}}" -> [123]�� ��µ� */
	
/*Error. Ʃ���� ������ size�� ����� ���� �߰��Ǵ� ���Ҹ� ������� �ᱣ������ ����ؾ���*/ 

/*Solution2. ������ vector�� �̿��� ������ tuple�� �ش� vector�� �Է�,
	������ �� vector�� size�� �̿��� ���Ҹ� ������� �����ϰ� for���� �̿���
	vector���� ���� �߰��Ǵ� ���Ҹ� ������� answer�� ����*/
/*Solution3. tuple�� ���� �����ϱ�*/	 

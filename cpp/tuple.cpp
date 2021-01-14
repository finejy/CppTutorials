#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*Solution1.
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
*/
/*Solution4.*/
vector<int> solution(string s){
	
	string::size_type len = s.size();
	vector<int> sum_vec;
	int sum = 0;
	
	
	
	
	for(int i=1; i!=len-1; ++i){
		if(s.at(i) == '}'){
			//cout << sum << ends;
			sum_vec.push_back(sum);
			sum = 0;
		}
		else if(s.at(i) == '{' || s.at(i) == ','){
			int int_element = 0;
			const char *char_element = &s.at(i+1);
			int_element = atoi(char_element);
			sum += int_element;
		}
	}
	
	sort(sum_vec.begin(), sum_vec.end());
	
	vector<int>::size_type int_len=sum_vec.size();
	vector<int> answer;
	
	answer.push_back(sum_vec[0]);
	
	
	for(int i=0; i!=int_len-1; ++i){
		answer.push_back(sum_vec[i+1]-sum_vec[i]);
		//cout << sum_vec[i+1]- sum_vec[i] << endl;
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
/*Solution4. ������ tuple ���� ������ ���� vector�� �Է�, �������� ���� ��
	�̿� index���� ���̸� ������� answer�� ����.-> CLEAR!!*/ 

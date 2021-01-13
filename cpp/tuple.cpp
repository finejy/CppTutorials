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

/*Solution1. 전체 string 중에서 길이가 가장 긴 튜플의 시작 index와 해당
	tuple의 길이를 받고 해당 범위 내의 int를 순서대로 출력받는다*/ 

/*#1 string 에서 int로 형변환을 할 때는 stoi, char에서 int는 atoi를 사용
	-> atoi에서 입력받는 char값은 const char*의 형태로 정해져 있어야 함*/
/*Q1 34열에서 s.at(max_index + i)를 char_element에 대입을 받았는데 왜 
	max_index + i 위치에 있는 문자 하나가 아니라 연결된 숫자 전체가 출력되는가
	ex) cin >> "{{123}}" -> [123]이 출력됨 */
	
/*Error. 튜플의 원소의 size에 비례해 새로 추가되는 원소를 순서대로 결괏값으로 출력해야함*/ 

/*Solution2. 이차원 vector을 이용해 각각의 tuple을 해당 vector에 입력,
	원소인 각 vector의 size를 이용해 원소를 순서대로 졍렬하고 for문을 이용해
	vector별로 새로 추가되는 원소를 순서대로 answer에 대입*/
/*Solution3. tuple에 대해 공부하기*/	 

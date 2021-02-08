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

/*Solution : strings의 각각의 원소들의 index n 위치의 원소들을 해당 원소들의 앞에 이어붙여 정렬하여 index n을 기준으로 문자를 오름차순으로 정렬,
	정렬이 끝난 후에는 다시 첫 번째 문자를 삭제 하여 원래 문자로 변형하여 출력하는 함수를 제작.*/ 

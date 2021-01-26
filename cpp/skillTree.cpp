#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool background(string skill, string skill_tree){
	string::size_type len_1 = skill.size();
	string::size_type len_2 = skill_tree.size();
	int skill_list=0;
	int real_skill=0;
	int skill_level=0;
	/*Solution 1 : 각 스킬의 위치 index를 새로운 vector 에 대입하고, 이 vector를 정렬한 값과 원래 값이 일치하는지 비교하여 참 거짓을 판별
	 	-> 이 방법을 사용하면 단계가 낮은 스킬을 쓰지 않고 다음 단계 스킬을 찍는 경우도 true로 판별됨. 조건 추가로 문제 해결은 가능하지만 효율이 떨어질 듯. 
	
	
	vector<int> skill_index;
	vector<int> new_index;
	
	for(int i=0; i!=len_1; ++i){
		for(int j=0; j!=len_2; ++j){
			if(skill_tree.at(j) == skill.at(i)){
				skill_index.push_back(skill_tree.find(skill.at(i)));
				cout << skill_tree.find(skill.at(i)) << " " << ends;
				break;
			}
		}
		
	} 
	cout << endl;
	
	new_index = skill_index;
	sort(new_index.begin(), new_index.end());
	
	if(new_index != skill_index){
		cout << "false" << endl;
		return false;
	} 
	else{
		cout << "true" << endl;
		return true;
	}*/
	
	/*Solution 2 : skill_trees의 각 원소들을 대상으로 각각의 skill_tree에 포함되어있는 skill의 원소 갯수를 파악하고, 실제로 skill의 순서대로 skill_tree를 찍었는지
		확인하여 두 결과값이 같으면 참을, 틀리면 거짓을 출력하는 함수를 만듬.*/ 
	
	for(int i=0; i!=len_1; ++i){
		for(int j=0; j!=len_2; ++j){
			if(skill_tree.at(j) == skill.at(i)){
				++skill_list;
				break;
			}
		}
	}
	
	for(int i=0; i!=len_2; ++i){
		if(skill.at(skill_level) == skill_tree.at(i)){
			++skill_level;
			++real_skill;
		}
		if(skill_level >= len_1) break;
	}
	cout << real_skill << " " << skill_list << endl;
	
	if(real_skill == skill_list){
		cout << "true" << endl;
		return true; 
	}
	else{
		cout << "false" << endl;
		return false;
	}
	
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<string>::size_type len = skill_trees.size();
    
    for(int i=0; i!=len; ++i){
    	if(background(skill, skill_trees[i])){
    		++answer;
		}
	}
    cout << answer << endl;
    
    return answer;
}

int main(){
	
	int len = 0;
	string skill;
	cin >> skill;
	cin >> len;
	
	vector<string> skill_trees(len, "");
	for(int i=0; i!=len; ++i){
		cin >> skill_trees[i];
	}
	
	solution(skill, skill_trees);
	
	return 0;
	
}
 

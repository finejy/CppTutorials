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
	/*Solution 1 : �� ��ų�� ��ġ index�� ���ο� vector �� �����ϰ�, �� vector�� ������ ���� ���� ���� ��ġ�ϴ��� ���Ͽ� �� ������ �Ǻ�
	 	-> �� ����� ����ϸ� �ܰ谡 ���� ��ų�� ���� �ʰ� ���� �ܰ� ��ų�� ��� ��쵵 true�� �Ǻ���. ���� �߰��� ���� �ذ��� ���������� ȿ���� ������ ��. 
	
	
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
	
	/*Solution 2 : skill_trees�� �� ���ҵ��� ������� ������ skill_tree�� ���ԵǾ��ִ� skill�� ���� ������ �ľ��ϰ�, ������ skill�� ������� skill_tree�� �������
		Ȯ���Ͽ� �� ������� ������ ����, Ʋ���� ������ ����ϴ� �Լ��� ����.*/ 
	
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
 

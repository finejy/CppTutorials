#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*predefined_ops.h ������ ���Ƿ� ���� �Լ��� �Է��� ��ü�� ������ Ÿ�Կ� ������ ������ �߻��ϴ� ������ ����. 
bool compare(int i, int j){
    return i < j;
}


string solution(string s) {
    string answer = "";
    string::size_type len = s.size();
    vector<string> element(len, "");
    
    for(int i=0; i!=len; ++i){
    	element[i]=s.at(i);
	}
	sort(element.begin(), element.end(), compare);
	
	for(int i=0; i!=len; ++i){
		answer+=element[i];
	}
	
    return answer;
}*/

string solution(string s){
	string answer = "";
	string::size_type len = s.size();
	vector<int> element(len, 0);
	string alpha = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	
	for(int i=0; i!=len; ++i){
		element[i]=find(alpha.begin(), alpha.end(), s.at(i))-alpha.begin();
	}
	
	sort(element.begin(), element.end());
	
	for(int i=0; i!=len; ++i){
		answer+=alpha.at(element[i]);
	}
	cout << answer << endl;
	
	return answer;
} 





int main(){
	string s="";
	cin >>s;
	
	solution(s);
	
	return 0;
}


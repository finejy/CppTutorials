//#코딩테스트 #C++ #2단계 #짝지어 제거하기 
#include <iostream>
#include <string>

using namespace std;

int solution(string s){
    int answer = 0;
	string::size_type len = s.size();
	
	if(len%2==1) return answer;
	int index = 0;
	
	while(len>0){
		if(s.at(index)==s.at(index+1)){
			s.erase(index, 2);
			len-=2;
			if(index!=0){
				--index;
			}
		}
		else{
			++index;
		}
		//cout << "s: " << s << " len: " << len << " index: " << index << endl;
		if(index==len-1&&len!=0){
			answer=0;
			break;
		}
		else answer=1;
	}
    return answer;
}

int main(){
	string s;
	cin >> s;
	solution(s);
	
	return 0;
}

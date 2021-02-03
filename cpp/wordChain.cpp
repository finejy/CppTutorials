//#코딩테스트 #C++ #2단계 #영어 끝말잇기 #Clear!
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    vector<string> used_word;
    used_word.push_back(words[0]);
    vector<string>::size_type len = words.size();
    
    for(int i=1; i!=len; ++i){
    	string::size_type len_word = used_word[i-1].size();
    	if(find(used_word.begin(), used_word.end(), words[i])==used_word.end()&&used_word[i-1].at(len_word-1)==words[i].at(0)){
    		used_word.push_back(words[i]);
		}
		else{
			answer[0]=i%n+1;
			answer[1]=i/n+1;
			break;
		}
		
	}
    return answer;
}

int main(){
	int n=0;
	cin >> n;
	int len=0;
	cin >> len;
	
	vector<string> words(len, "");
	for(int i=0; i!=len; ++i){
		cin >> words[i];
	}
	
	solution(n, words);
	
	return 0;
}



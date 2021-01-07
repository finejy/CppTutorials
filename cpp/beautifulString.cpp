#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string s){
	
	long long answer = 0;
	
	vector<string>::size_type len = s.size();
	int part = 0;
	if(len == 1) return answer;
	//part의 갯수 확인 
	for(int i=0; i!=len-1; ++i){
		if(s.at(i) != s.at(i+1)) part +=1;
	}
	if(part <=1) return answer;
	
	//part의 길이 및 해당 알파벳을 벡터에 저장 
	vector<int> part_len(part, 0);
	vector<string> part_alpha(part, "");
	
	for(int i=0; i!= part; ++i){
		for(int j=0; j!=len; ++j){
			if(s.at(i)!= s.at(i+1)) break;
			else{
				part_len[i] +=1;
				if(part_alpha[i]=="") part_alpha[i] = s.at(i);
			} 
			
		}
	}
	 
	
	int between=0;
	
	for(int i=0; i!=part-1; ++i){
		for(int j=i+1; j!=part; ++j){
			if(j-i==1){
				between=0;
			}
			else if(part_alpha[i] != part_alpha[j]){
				between=0;
				for(int k=i+1; k!=j; ++k){
					between += part_len[k];
				}
			}
			answer+=part_len[i]*part_len[j]*(between+1);
			
		}
	}
		
	cout << answer << endl;
	
	return answer;	
	
}

int main(){
	string s;
	cin >> s;
	solution(s);
	return 0;
}

//이웃하는 동일한 문자끼리 각각의 part로 나누고, 각각의 part들 간의 거리를 비교해서 모든 아름다움을 계산 
//21.01.07 part_len의 원소가 1일 경우 결과값이 0이 나오는 오류 발생, index의 경계 문제인듯 

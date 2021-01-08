#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string s){
	
	long long answer = 0;
	
	vector<string>::size_type len = s.size();  
	if(len == 1) return answer;
	int part = 1;
	
	//part의 갯수 확인 
	for(int i=0; i!=len-1; ++i){
		if(s.at(i) != s.at(i+1)) part +=1;
	}
	cout << part << endl;
	if(part <=1) return answer;
	
	//part의 길이 및 해당 알파벳을 벡터에 저장 
	vector<int> part_len(part, 0);
	vector<string> part_alpha(part, "");
	int part_now=0;
	
	/*반복문 오류. 첫 번째 for문과 두 번째 for문 위치 변경 필요 
	for(int i=0; i!= part; ++i){
		for(int j=0; j!=len-1; ++j){
			if(s.at(j)!= s.at(j+1)) break;
			else{
				part_len[i] +=1;
				if(part_alpha[i]=="") part_alpha[i] = s.at(j);
			} 
			
		}
	}*/
	for(int i=0; i!=len-1; ++i){
		if(part_alpha[part_now]=="") part_alpha[part_now] = s.at(i);
		
		if(s.at(i)!= s.at(i+1)){
			part_len[part_now]+=1;
			part_now +=1;
		}
		else{
			part_len[part_now]+=1;
			
		}
	}
	part_len[part-1]+=1;
  
	//임이의 두  part 사이에 존재하는 다른 part 들과 해당 part들의 갯수를 이용해 각 경우의  아름다움 조사. 
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
	
	return answer;	
	
}

int main(){
	string s;
	cin >> s;
	cout << solution(s) << endl;;
	return 0;
}

//이웃하는 동일한 문자끼리 각각의 part로 나누고, 각각의 part들 간의 거리를 비교해서 모든 아름다움을 계산 
//21.01.07 part_len의 원소가 1일 경우 결과값이 0이 나오는 오류 발생, index의 경계 문제인듯 
//첫번째 이중 for문에서 s의 원소를 받아오는 과정에서 변수 i와 j를 바꿔서 작성한 오류 발견-> 수정 완료
//21.01.08 간단한 예제에서는 제대로된 결과값 출력. 하지만 오류가 나는 예외 상황 존재, 입력값이 크면 시간 초과 문제 발생.
//문제 출처 programmers; https://programmers.co.kr/learn/courses/30/lessons/68938?language=cpp 

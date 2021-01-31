#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//시간 초과 오류
 
/*int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    
    while(true){
    	scoville.push_back(scoville[0] + scoville[1] * 2);
    	scoville.erase(scoville.begin(), scoville.begin() + 2);
    	answer +=1;
		sort(scoville.begin(), scoville.end());
		if(scoville[0] < K && scoville.size() == 1) answer = -1;
    	if(scoville[0] >= K || scoville.size() == 1){
    	//#1. else if(scoville[0] >= K || scoville.size() == 1){
    		break;
		}
	}
	cout << answer << endl;
    return answer;
}*/

//K이하인 원소만 따로 추출해서 계산하는 방식으로 진행
//실패:under_scoville.size()==1일 때 코드가 종료되지 못함. K이상인 원소들까지 들고와서 계산해야 하므로 결국 시간 초과에 걸릴 것임. 
int solution(vector<int> scoville, int K){
	int answer =0;
	sort(scoville.begin(), scoville.end());
	vector<int> under_scoville;
	vector<int>::size_type len = scoville.size();
	
	for(int i=0; i!=len; ++i){
		if(scoville[i] < K) under_scoville.push_back(scoville[i]);
		else break;
	}
	
	while(true){
		int new_scoville=under_scoville[0] + under_scoville[1] * 2;
		under_scoville.erase(scoville.begin(), scoville.begin() + 2);
		if(new_scoville < K){
			under_scoville.push_back(new_scoville);
			sort(under_scoville.begin(), under_scoville.end());
		}
		answer+=1;
		if(under_scoville.size()==1){
			if()
			answer = -1;
			break;
		}
		else if(under_scoville.size()==0){
			break;
		}
	}
	
	cout << answer << endl;
	return answer;
} 
 

int main(){
	int x = 0;
	int K = 0;
	vector<int> scoville;
	cin >> K;
	int s = 0;
	cin >> s;
	for(int i=0; i!=s; ++i){
		cin >> x;
		scoville.push_back(x);
	}
	solution(scoville, K);
	return 0;
}

/* #1. segmentation 에러 발생. 첫 번째 조건문과 두 번째 조건문 모두 size()==1이 있고, 각 조건이 &&와 ||라 중복되는 상황이 발생해서 그런듯.
	else if 사용하면 중복되는 상황 제외하고 조건문에 입력한다고 생각했는데 두 조건 모두 만족하니깐 에러가 생기는 것으로 생각됨. */
//시간 초과 문제.. while문이 실행될때마다 정렬을 해서 그런듯.  
//Heap 자료구조를 이해해야 풀 수 있는 문제. 

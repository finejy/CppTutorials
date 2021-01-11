#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    vector<int>::size_type len = citations.size();

    for(int i=0; i!=len; ++i){
    	//cout << citations[i] << ends;
    	if(i > citations[i]){
    		answer = citations[i];
    		break;
		}
	}	
	
	return answer;
}

int main(){
	vector<int> citations;

	for(int i=0; i!=5; ++i){
		int x=0;
		cin >> x;
		citations.push_back(x);		
	}
	cout << solution(citations) << endl;
}

/* Solution : 입력 받은 vector을 내림차순으로 정렬하고, 해당 위치의 index+1과 해당 위치의 원소값을 비교하여 h-index값을 구함*/
// 기본 케이스에서는 성공. But, 테스트케이스에서는 전부 실패
// answer = i로 잡았을 때 한 가지 경우 외에는 전부 성공하였음.
/* 범위랑 answer에 대입하는 값(citations[i])가 틀렸음. 애초에 문제 해석 자체가 틀렸음. 
	h의 최댓값을 찾아야 하는데 그 값이 citations의 원소 중에서 최댓값이라는 말이 아님. 따라서 최댓값을 찾으려면 i를 이용해서 1단위로 확인을 해야함.
	i+1 > citations[i]가 i에서 처음 성립한다는 말은 i-1에 대해서는 해당 조건이 성립하지 않는다는 말인데, 이렇게 되면 i == citations[i-1]이든 
	i < citations[i-1]이든 결국 H-index의 최댓값은 i가 될 수밖에 없다.*/ 
/* vector을 내림차순으로 정렬하고, for 문을 이용해 해당 위치의 index+1과 해당 위치의 원소를 비교한다.  

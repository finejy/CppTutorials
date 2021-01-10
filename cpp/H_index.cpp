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
    	if(i+1 >= citations[i]){
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
 

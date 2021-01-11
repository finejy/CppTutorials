#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    while(scoville[0] < K && scoville.size() > 1){
    	
		sort(scoville.begin(), scoville.end());
    	
    	scoville.push_back(scoville[0] + scoville[1] * 2);
    	scoville.erase(scoville.begin()+ 2);
    	answer +=1;
	}
    return answer;
}

int main(){
	int x = 0;
	int K = 0;
	vector<int> scoville;
	cin >> K;
	while(cin >> x){
		scoville.push_back(x);
	}
	cout << solution(scoville, K) << endl;
}

//�� while���� �� ���� �������� �𸣰���-> while�� sort�� ���� ���°� �����ΰ�? 
//priority_queue�� ����ϴ� ������ ����? 


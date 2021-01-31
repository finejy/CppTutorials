#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//�ð� �ʰ� ����
 
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

//K������ ���Ҹ� ���� �����ؼ� ����ϴ� ������� ����
//����:under_scoville.size()==1�� �� �ڵ尡 ������� ����. K�̻��� ���ҵ���� ���ͼ� ����ؾ� �ϹǷ� �ᱹ �ð� �ʰ��� �ɸ� ����. 
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

/* #1. segmentation ���� �߻�. ù ��° ���ǹ��� �� ��° ���ǹ� ��� size()==1�� �ְ�, �� ������ &&�� ||�� �ߺ��Ǵ� ��Ȳ�� �߻��ؼ� �׷���.
	else if ����ϸ� �ߺ��Ǵ� ��Ȳ �����ϰ� ���ǹ��� �Է��Ѵٰ� �����ߴµ� �� ���� ��� �����ϴϱ� ������ ����� ������ ������. */
//�ð� �ʰ� ����.. while���� ����ɶ����� ������ �ؼ� �׷���.  
//Heap �ڷᱸ���� �����ؾ� Ǯ �� �ִ� ����. 

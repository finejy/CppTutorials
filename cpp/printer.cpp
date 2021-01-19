#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //location이 음수가 되서 해당 위치의 원소가 프린트 될때까지 반복문이 지속
	while(location >= 0){
		int maxi = *max_element(priorities.begin()+1, priorities.end());
		
		//priorities[0]의 값보다 큰 값이 원소로 포함되어 있으면 첫 번째 원소를 맨 뒤로 이동시켜준다 
		if(priorities[0] < maxi){
			priorities.push_back(priorities[0]);
			priorities.erase(priorities.begin());
			
			//location이 0이 됬는데 뒤에 더 큰 값이 존재하면 원소를 뒤로 보내면서 location을 priorities의 size로 변경 
			if(location == 0){
				location += priorities.size();
			}
		}
		
		//priorities[0]의 값이 최대일 경우 해당 값을 지워주고, answer의 값을 1 늘려준다. 
		else{
			priorities.erase(priorities.begin());
			++answer;
		}
		
		--location;
	}
    
    return answer;
}

int main(){
	vector<int> priorities = {1, 1, 9 ,1, 1, 1};
	int location = 0;
	cin >> location;
	
	cout << solution(priorities,location) << ends;
	
	return 0;
	
}

/*Solution index가 0인 원소와 그 이외의 원소의 최댓값을 비교하고 해당 결과에 따라 location의 값을 산술해 location이 음수가 될 때의 answer을 출력*/
/*erase 함수 사용 시 literator 함수를 사용 할 수 있다고 함. literator 함수에 대해 알아볼 것.*/ 

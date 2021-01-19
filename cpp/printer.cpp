#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    //location�� ������ �Ǽ� �ش� ��ġ�� ���Ұ� ����Ʈ �ɶ����� �ݺ����� ����
	while(location >= 0){
		int maxi = *max_element(priorities.begin()+1, priorities.end());
		
		//priorities[0]�� ������ ū ���� ���ҷ� ���ԵǾ� ������ ù ��° ���Ҹ� �� �ڷ� �̵������ش� 
		if(priorities[0] < maxi){
			priorities.push_back(priorities[0]);
			priorities.erase(priorities.begin());
			
			//location�� 0�� ��µ� �ڿ� �� ū ���� �����ϸ� ���Ҹ� �ڷ� �����鼭 location�� priorities�� size�� ���� 
			if(location == 0){
				location += priorities.size();
			}
		}
		
		//priorities[0]�� ���� �ִ��� ��� �ش� ���� �����ְ�, answer�� ���� 1 �÷��ش�. 
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

/*Solution index�� 0�� ���ҿ� �� �̿��� ������ �ִ��� ���ϰ� �ش� ����� ���� location�� ���� ����� location�� ������ �� ���� answer�� ���*/
/*erase �Լ� ��� �� literator �Լ��� ��� �� �� �ִٰ� ��. literator �Լ��� ���� �˾ƺ� ��.*/ 

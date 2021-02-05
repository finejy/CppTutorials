#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(vector<int> d, int budget){
	int answer = 0;
	int budget_sum = 0;
	sort(d.begin(), d.end());
	vector<int>::size_type len = d.size();
	
	while(budget >= budget_sum){
		budget_sum+=d[answer];
        if(budget < budget_sum) break;
		++answer;
        if(answer == len) break;
	}
	
	return answer;
}


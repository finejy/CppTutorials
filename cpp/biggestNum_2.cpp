#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<vector<int>> num_element;
    vector<int>::size_type len = numbers.size();
    
    for(int i=0; i!=len; ++i){
    	int::size_type num_len = numbers[i].size();
    	
    	while(num_len > 0){
    		num_element[i].push_back(numbers[i] / pow(10, num_len));
    		--num_len;
		}
	}
	
	sort(num_element.begin(), num_element.end(), greater<int>());
	
	
	
	
	return answer;
}

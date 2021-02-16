#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    
    vector<vector<int>>::size_type row_1 = arr1.size();
    vector<int>::size_type column = arr1[0].size();
    //vector<vector<int>>::size_type row_2 = arr2.size();
    
    for(int i=0; i!=row_1; ++i){
    	vector<int> answer_element;
    	for(int j=0; j!=column; ++j){
    		int element = 0;
    		for(int k=0; k!=column; ++k){
    			element+=arr1[i][k]*arr2[k][j];
			}
			answer_element.push_back(element);
		}
		answer.push_back(answer_element);
		
	}

    return answer;
}

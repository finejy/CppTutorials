#include <string>
#include <vector>

using namespace std;

vector<int> binary(int n, int element){
	vector<int> result(n, 0);
	while(element>0){
		result[n-1]=element%2;
		--n;
		element/=2;
	}
	return result;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map_1;
    vector<vector<int>> map_2;
    
    
    for(int i=0; i!=n; ++i){
    	map_1.push_back(binary(n, arr1[i]));
    	map_2.push_back(binary(n, arr2[i]));
	}
	
	for(int i=0; i!=n; ++i){
		string map_element="";
		for(int j=0; j!=n; ++j){
			if(map_1[i][j]+map_2[i][j]>0){
				map_element+="#";
			}
			else{
				map_element+=" ";
			}
		}
		answer.push_back(map_element);
	}
    
    return answer;
}

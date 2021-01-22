#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 0;
    vector<string> cloth_kind;
    vector<int> kind_num;
    vector<vector<string> >::size_type len = clothes.size();
	
	for(int i=0; i!=len; ++i){
		if(find(cloth_kind.begin(), cloth_kind.end(), clothes[i][1]) != cloth_kind.end()){
			kind_num[find(cloth_kind.begin(), cloth_kind.end(), clothes[i][1])] +=1;
		}
		else{
			cloth_kind.push_back(clothes[i][1]);
			kind_num[find(cloth_kind.begin(), cloth_kind.end(), clothes[i][1])] +=1;
		}
	} 
    vector<int>::size_type len2 = kind_num.size();
    
    for(int i=1; i<=len2; ++i){
    	vector<int> each_case(1, i);
    	while(each_case[0] < len2 - i + 1){
    		if()
		}
		}
    	
	}
    
    
    return answer;
}

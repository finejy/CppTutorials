#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
	/*
    int answer = 0;
    vector<int>::size_type len = arr.size();
    vector<vector<int>> arr_element;
    
    for(int i=0; i!=len; ++i){
    	arr_element.push_back({});
	    if(arr[i]>=2){
			for(int j=2; j!=arr[i]+1; ++j){
	    		if(arr[i]%2==0){
	    			arr_element[i].push_back(j);
	    			arr[i]/=j;
	    			--j;
				}
				if(j+1 > arr[i]) break;
			}
		}
	}
    
    int index_1=0;
    int index_2=0;
    while(arr_element.size()!=0){
    	for(int i=index_1; i!=len; ++i){
    		
		}
    	arr_element[index_1][index_2]
	}
    */
    int answer = 0;
    vector<int>::size_type len = arr.size();
    
    int maximum = max_element(arr.begin(), arr.end());
    
    vector<int> menu(1, 2);
    
    for(int i=3; i!=maximum; i+=2){
    	menu.push_back(i);
	}
	
	int index_1=1;
	int index_2=2;
	while(index_1 < menu.size()){
		
		if(menu[index_2]%menu[index_1]==0){
			menu.erase(menu.begin()+index_2);
		}
		else{
			++index_2;
		}
		if(index_2 > menu.size()){
			++index_1;
			index_2=index_1+1;
		}
	}
    
    vector<int>::size_type len_2 = menu.size();
    
    vector<int> count(len_2, 0);
    
    
    for(int i=0; i!=len; ++i){
    	int index_menu = 0;
    	int num_count = 0;
    	while(arr[i]!=1){
	    	if(arr[i]%menu[index_menu]==0){
	    		++num_count;
	    		arr[i]/=menu[index_menu];
			}
			else{
				if(count[index_menu] < num_count){
					count[index_menu]=num_count;
				}
				++index_menu;
				num_count = 0;
			}
		}
	}
    
    for(int i=0; i!=len_2; ++i){
    	answer+=menu[i]*count[i];
	}
    
    return answer;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int sum_weight=truck_weights[1];
    vector<int>::size_type len = truck_weights.size();
    vector<vector<int>> each_time;
    int i=1;
    int end=0;
    
    //for(int i=1; i!=len; ++i){
    while(end<len){
    	if(sum_weight+truck_weights[i] < weight){
    		each_time.push_back({0, truck_weights[i]});
    		sum_weight+=truck_weights[i];
    		++i;
		}
		vector<vector<int>>::size_type len_2 = each_time.size();
		for(int j=0; j!=len_2; ++j){
			if(each_time[j][0] < weight+1){
				++each_time[j][0];
				cout << each_time[j][0] << " " << each_time[j][1] << endl;
			}
			else{
				sum_weight-=each_time[0][1];
				++end;
				cout << "erase" << endl;
			}
		}
		++answer;
	}
    cout << answer << endl;  
    return answer;
}

int main(){
	int bridge_length=0;
	int weight=0;
	int len=0;
	vector<int> truck_weights;
	
	cin >> bridge_length;
	cin >> weight;
	cin >> len;
	for(int i=0; i!=len; ++i){
		cin >> truck_weights[i];
	}
	
	solution(bridge_length, weight, truck_weights);
	
	return 0;
}



#include <string>
#include <vector>
#include <iostream>
#include <random> 


using namespace std;

vector<vector<int>> sum(vector<vector<int>>& v, int n){
	vector<vector<int>> result(n/2, vector<int>(n/2, 2));
	for(int i=0; i!=n; i+=2){
		for(int j=0; j!=n; j+=2){
			if(v[i][j] == v[i+1][j] &&v[i][j] == v[i][j+1] &&
				v[i][j] == v[i+1][j+1] &&v[i][j]!=2){
				result[i/2][j/2] = v[i][j];
				v[i][j] = 2;
				v[i+1][j] = 2;
				v[i][j+1] = 2;
				v[i+1][j+1] = 2;
				
			}
		}
	}
	return result;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    vector<vector<int>>::size_type len = arr.size();
    
    while(len >1){
    	vector<vector<int>> new_arr = sum(arr, len);
    	//출력 예시 
		/*cout << "arr" << endl;
    	for(int x=0; x!=len; ++x){
    		for(int y=0; y!=len; ++y){
    			cout << arr[x][y] << " "<< ends;
			}
			cout << endl;
			cout << endl;
		}*/
		
    	for(int i=0; i!=len; ++i){
    		for(int j=0; j!=len; ++j){
    			if(arr[i][j] == 0) answer[0]+=1;
				else if(arr[i][j] == 1) answer[1]+=1;
			}
		}
		
		len /= 2;
		//출력 예시 
    	/*cout << "new_arr" << endl; 
    	for(int a=0; a!=len; ++a){
    		for(int b=0; b!=len; ++b){
    			cout << new_arr[a][b] << " " << ends;
			}
			cout << endl;
			cout << endl;
		}*/
		
		arr = new_arr;
	}
    if(len==1&&arr[0][0]!=2) ++answer[arr[0][0]];
    
    cout << answer[0] << " " << answer[1] << endl;
    return answer;
}

int main(){
	random_device rd;
	mt19937_64 rng(rd());
	
	uniform_int_distribution<__int64> dist1(0,1);
	int n;
	int element;
	cin >> n;
	vector<vector<int>> arr(n,vector<int>(n, 0));
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=n; ++j){
			//element = dist1(rng);
			//cout << element << " " << ends;
			//arr[i][j] = element;
			cout << arr[i][j] << " " << ends;
		}
		cout << endl;
		cout << endl;
	}
	solution(arr);
	
	return 0;
}

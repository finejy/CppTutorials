#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
vector<vector<string>> new_vector(int m, int n, vector<string> board){
	vector<vector<string>> new_vector(n, vector<string>(m, ""));
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			new_vector[j][m-i-1]=board[i].at(j);
		}
	}
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			cout << new_vector[i][j] << " " << ends;
		}
		cout << endl;
	}
	return new_vector;
}*/

int background(int& answer, int m, int n, vector<vector<string>>& new_vector){
	vector<vector<int>> delete_block (n, vector<int>(m, 0));
	int count = 0;
	for(int i=0; i!=n-1; ++i){
		int minimum=min_element(new_vector[i].size(), new_vector[i+1].size())-1;
		for(int j=0; j!=minimum; ++j){
			if(new_vector[i][j]==new_vector[i][j+1]&&new_vector[i][j]==new_vector[i+1][j]&&new_vector[i][j]==new_vector[i+1][j+1]){
				delete_block[i][j]=1;
				delete_block[i][j+1]=1;
				delete_block[i+1][j]=1;
				delete_block[i+1][j+1]=1;		
				++count;	
			}
		}
	}
	
	if(count==0) return 1;
	
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			if(delete_block[i][j]==1){
				new_vector[i].erase(new_vector[i].begin()+j);
				++answer;
			}
		}
	}
	return 0;
}



int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<string>> new_vector(n, vector<string>(m, ""));
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			new_vector[j][m-i-1]=board[i].at(j);
		}
	}
	for(int i=0; i!=n; ++i){
		for(int j=0; j!=m; ++j){
			cout << new_vector[i][j] << " " << ends;
		}
		cout << endl;
	}
	int tof=0;
    while(tof==0){
    	tof=background(answer, m, n, new_vector);
    	
    	cout << answer << endl;
    	
	}
    
    return answer;

}

int main(){
	int m=0;
	int n=0;
	cin >> m;
	cin >> n;
	vector<string> vec(m, "");
	
	for(int i=0; i!=m; ++i){
		cin >> vec[i];
	}
	
	solution(m, n, vec);
	
	return 0;
}

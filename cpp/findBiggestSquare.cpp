#include <iostream>
#include<vector>
using namespace std;
/*
int solution(vector<vector<int>> board)
{
    int answer = 1;
	vector<vector<int>>::size_type column = board.size();
	vector<int>::size_type row = board[0].size();
    if(column<2){
        int ans=0;
        for(int i=0; i!=row; ++i){
            ans+=board[0][i];
        }
        if(ans==0) return 0;
        else return answer;
    }
    else if(row<2){
        int ans=0;
        for(int i=0; i!=column; ++i){
            ans+=board[i][0];
        }
        if(ans==0) return 0;
        else return answer;
    }
    
	
	while(true){
		int count = 0;
		for(int i=0; i!=column-1; ++i){
			for(int j=0; j!=row-1; ++j){
				if(board[i][j]==board[i+1][j]&&board[i][j]==board[i][j+1]&&board[i][j]==board[i+1][j+1]&&board[i][j]!=0){
					++board[i][j];
					++count;
				}
			}
		}
		--column;
		--row;
		if(row<1||column<1||count==0) break;
		else ++answer;
	}
	
	answer = answer * answer;
    

    return answer;
}*/

int solution(vector<vector<int>> board){
	int answer = 0;
	
	vector<vector<int>>::size_type column = board.size();
	vector<int>::size_type row = board[0].size();
	
	vector<vector<int>> level(column, (vector<int>(row, 0)));
	vector<vector<int>> vertical = level;
	/*
	for(int i=0; i!=column; ++i){
		int seat = 0;
		int count = 1;
		for(int j=1; j!=row; ++j){
			if(board[i][seat]==board[i][j]){
				++count;
			}
			else{
				level[i][seat]=count;
				seat = j;
				count = 1;
			}
			cout << seat << " " << count << endl;
		}
	}
	for(int i=0; i!=row; ++i){
		int seat = 0;
		int count = 1;
		for(int j=1; j!=column; ++j){
			if(board[seat][i]==board[j][i]){
				++count;
			}
			else{
				vertical[seat][i]=count;
				seat = j;
				count = 1;
			}
		}
	}
	*/
	
	for(int i=0; i!=column; ++i){
		int seat = 0;
		int count = 1;
		for(int j=1; j!=row; ++j){
			if(board[i][seat]==board[i][j]&&board[i][seat]!=0){
				++count;
			}
			else if(board[i][seat]!=board[i][j]||j==row-1){
				if(board[i][seat]!=0) level[i][seat]=count;
				seat = j;
				count = 1;
			}
		}
	}
	
	for(int i=0; i!=row; ++i){
		int seat = 0;
		int count = 1;
		for(int j=1; j!=column; ++j){
			if(board[seat][i]==board[j][i]&&board[seat][i]!=0){
				++count;
			}
			else if(board[seat][i]!=board[j][i]||j==column-1){
				if(board[seat][i]!=0) vertical[seat][i]=count;
				seat = j;
				count = 1;
			}
		}
	}
	
	
	for(int i=0; i!=column-1; ++i){
		for(int j=0; j!=row-1; ++j){
			cout << level[i][j] << " " << ends;
			if(level[i][j]!=0&&vertical[i][j]!=0){
				int minimum = min(level[i][j], vertical[i][j]);
				if(answer < minimum){
					answer = minimum;
				}
			}
		}
		cout << endl;
	}
	
	++answer;
	answer = answer * answer;
	
	return answer;
	
}

int main(){
	vector<vector<int>> board={{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}};
	solution(board);
	return 0;
}

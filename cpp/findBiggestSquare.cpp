#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
	vector<vect<int>>::size_type column = board.size();
	vector<int>::size_type row = board[0].size();
	
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
		if(row==1||column==1||count==0) break;
		else ++answer;
	}
	
	answer = answer * answer;
    

    return answer;
}

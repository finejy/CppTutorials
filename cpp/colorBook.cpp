#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> background(int m, int n, vector<vector<int>>& picture){
	vector<vector<int>> background(m, vector<int> (n, 0));
	vector<int> result(2, 0);
	
	int x =0, y =0, num = 0;
	
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			if(picture[i][j]!=0{
				x = i;
				y = j;
				num = picture[i][j];
				++background[i][j];
				break;
			}
		}
	}
	
	int vec = 1, save_x = 0, save_y = 0;
	
	while(background[x][y] == 1 && num == background[x][y] && x<m && y<n){
		if(vec == 1){
			if(picture[x][y] == picture[x+1][y]){
				background[x+1][y]=1;
				if(picture[x][y] == picture[x][y+1]){
					background[x][y+1] = 1;
					save_x = x+1;
					save_y = y;
					++y;
				}
				else{
					++x;
					background[x][y] = 1;
					vec = 0;
					save_x = 0;
					save_y = 0;
				}
			}
			else{
				if(picture[x][y] == picture[x][y+1]){
					background[x][y+1] = 1;
					++y;
				}
				else{
					x = save_x;
					y = save_y;
					save_x = 0;
					xave_y = 0;
					vec = -1;
				}
			}
		}
		else if(vec == -1){
			if(picture[x][y] == picture[x+1][y]){
				background[x+1][y] = 1;
				if(picture[x][y] == picture[x][y-1]){
					background[x][y-1] = 1;
					save_x = x+1;
					save_y = y;
					--y;
				}
				else{
					++x;
					background[x][y] = 1;
					vec = 0;
					save_x = 0;
					save_y = 0;
				}
			}
			else{
				if(picture[x][y] == picture[x][y-1]){
					background[x][y-1] = 1;
					--y;
				}
				else{
					x = save_x;
					y = save_y;
					save_x = 0;
					save_y = 0;
					vec = 1;
				}
			}
		}
		else{
			if(picture[x][y] == picture[x][y-1]){
				if(picture[x][y] == picture[x][y+1]){
					save_x = x;
					save_y = y;
				}
			}
		}
	}	
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

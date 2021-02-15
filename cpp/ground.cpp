#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

	vector<vector<int>>::size_type len = land.size();
	int seat = 5;
	for(int i=0; i!=len; ++i){
		int maximum=0;
		int max_seat=0;
		for(int j=0; j!=4; ++j){
			if(j!=seat){
				if(maximum < land[i][j]){
					maximum = land[i][j];
					max_seat = j;
				}
			}
		}
		seat = max_seat;
		answer+=maximum;
	}

    return answer;
}

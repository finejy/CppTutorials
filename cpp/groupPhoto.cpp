#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//첫 번째 조건과 두 번째 조건에 중복되는 인원이 없는 경우 
int background_1(int first, int second, int& answer){
	for(int i=0; i!=6-first; ++i){
		vector<int> seat(8, 0);
		seat[i]=1;
		seat[i+1+first]=1;
		for(int j=0; j!=6-second; ++j){
			if(seat[j]!=1&&seat[j+1+second]!=1){
				answer += 4*3*2;
			}
		}
	}
	answer*=4;
	return 0;
}

//첫 번째 조건과 두 번째 조건에 중복이 1명 있는 경우 
int background_2(int first, int second, int& answer){
	if(first+second <= 5){
		answer+=(6-(first+second))*2*5*4*3*2;
	}
	int maximum = max(first, second);
	answer+=(6-maximum)*2*5*4*3*2;

	return 0;
}

//첫 번째 조건과 두 번째 조건에 중복이 2명인 경우
int background_3(int first, int& answer){
	answer+=2*7*6*5*4*3*2;
	return 0;
}
/*
int for_function(string range, int len, int& i, int function){
	if(range == "<"){
		for(i=0; i!=len; ++i){
			function;
		}
	}
	else if(range==">"){
		for(i=len; i!=7; ++i){
			function;
		}
	}
	else{
		int i=len;
		function;
	}
	return function;
}

int if_function(int same_num, int first, int second, int& answer){
	if(same_num==1){
		return background_2(first, second, answer);
	}
	else{
		return background_1(first, second, answer);
	}
}

int same_function(int first, int second, int& answer){
	if(first==second){
		return background_3(first, answer);
	}
}*/

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int first = 0;
    int second = 0;
    string number = "0123456789";
	vector<vector<string>> element(2, vector<string>(3, ""));
	
    first=number.find(data[0].at(4));
    second=number.find(data[1].at(4));
    
    for(int i=0; i!=2; ++i){
    	element[i][0]=data[i].at(0);
    	element[i][1]=data[i].at(2);
    	element[i][2]=data[i].at(3);
	}
	
	int same_num = 0;
	
	if(element[0][0]==element[1][0]) ++same_num;
	if(element[0][0]==element[1][1]) ++same_num;
	if(element[0][1]==element[1][0]) ++same_num;
	if(element[0][1]==element[1][1]) ++same_num;
    /*
    if(same_num==2){
    	for_function(element[0][2], first, for_function(element[1][2], second, same_function(i, j, answer)));
	}
	else for_function(element[0][2], first, for_function(element[1][2], second, if_function(same_num, i, j, answer)));
    cout << answer << endl;
    return answer;*/
    
    int i_start=0;
    int i_end=0;
    int j_start=0;
    int j_end=0;
    
    if(element[0][2]=="<"){
    	i_end=first;
	}
	else if(element[0][2]==">"){
		i_start=first+1;
		i_end=7;
	}
	else{
		i_start=first;
		i_end=first+1;
	}
	if(element[1][2]=="<"){
		j_end=second;
	}
	else if(element[1][2]==">"){
		j_start=second+1;
		j_end=7;
	}
	else{
		j_start=second;
		j_end=second+1;
	}
	
	for(int i=i_start; i!=i_end; ++i){
		for(int j=j_start; j!=j_end; ++j){
			if(same_num==0) background_1(i, j, answer);
			else if(same_num==1) background_2(i, j, answer);
			else if(same_num==2&&i==j) background_3(i, answer);
			cout << answer << " " << ends;
		}
		cout << endl;
	}
    
    return answer;
}

int main(){
	int n=0;
	vector<string> data(2, "");
	cin >> n;
	cin >> data[0];
	cin >> data[1];	
	
	solution(n, data);
	return 0;
}

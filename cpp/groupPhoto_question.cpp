#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//ù ��° ���ǰ� �� ��° ���ǿ� �ߺ��Ǵ� �ο��� ���� ��� 
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

//ù ��° ���ǰ� �� ��° ���ǿ� �ߺ��� 1�� �ִ� ��� 
int background_2(int first, int second, int& answer){
	if(first+second <= 5){
		answer+=(6-(first+second))*2*5*4*3*2;
	}
	int maximum = max(first, second);
	answer+=(6-maximum)*2*5*4*3*2;

	return 0;
}

//ù ��° ���ǰ� �� ��° ���ǿ� �ߺ��� 2���� ���
int background_3(int first, int& answer){
	answer+=2*7*6*5*4*3*2;
	return 0;
}

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
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
	int i=0;
	int j=0;
	
	if(element[0][0]==element[1][0]) ++same_num;
	if(element[0][0]==element[1][1]) ++same_num;
	if(element[0][1]==element[1][0]) ++same_num;
	if(element[0][1]==element[1][1]) ++same_num;
    
    if(same_num==2){
    	for_function(element[0][2], first, for_function(element[1][2], second, same_function(i, j, answer)));
	}
	else for_function(element[0][2], first, for_function(element[1][2], second, if_function(same_num, i, j, answer)));
    cout << answer << endl;
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


/*function�� reference�� ���� ������ ���� �ڵ��� ������ ����. answer�� ���� ���ǿ� rvalue�� ���� ����, �׸��� 
	function�� �̿��� ���� for���� �����ų ���� ���� �� ���� ������ Ȯ�εǹǷ� ������ ���� �� ���� ��Ȳ�� ���� ������ �ʿ���.(solution�� ���� �ڵ�� Ȯ���� ��)*/ 

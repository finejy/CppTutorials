#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
/*
long long solution(int w,int h) {
	/*
    int answer = 0;
    int mini = min(w,h);
    int maxi = max(w,h);
    
    
    int sys = maxi / mini;
    
    if(maxi % mini != 0) sys += 1;
    
    answer = w * h - (sys * mini);
    
    long long answer = 0;
	answer = w * h;
	int maximum = max(w, h);
	int minimum = min(w, h);
	
	answer -= maximum;
	
	long long new_mini = 0;
	double space = maximum / minimum;
	
	for(int i=1; i!=minimum; ++i){
		if((i*space)%1!=0){
			++new_mini;
		}
	}
	
	answer += new_mini;
    
    return answer;
}*/
/*�׳��� ���� ��Ȯ�� ���� ���, ���� ����
 
long long solution(int w,int h) {
    long long answer = 0;
	answer = w * h;
	double maximum = max(w, h);
	double minimum = min(w, h);
	
	answer -= maximum;
	
	double space = maximum / minimum;
	//���� ����->space = 1.5(w=8, h=12)
    cout << space << " " << (int)(space) <<endl;

    
	for(double i=1; i!=minimum; ++i){
		if((i*space)!=(int)(i*space)){
		//���� �߻� -> ������ ����, ������� ���������� �������� �ȵȴٴ°�	 
			--answer;
		}
	}
    
    cout << answer << endl;
    return answer;
}*/

/*����... 
int background(int w, int h){
	int result=0;
	int minimum = min(w, h);
	for(int i=2; i!=minimum; ++i){
		if(w%i==0&&h%i==0){
			result=i;
			break;
		}
	}
	return result;
	
}

long long solution(int w,int h) {
    long long answer = 0;
	answer = w * h;
	int same = background(w, h);
	int maximum = max(w, h);
	int minimum = min(w, h);
	
	answer -= maximum;
	
	int edge = 0;
	if(minimum%same==0){
		edge = minimum-minimum/same;
	}
	else{
		edge = minimum-1-minimum/same;
	}
	answer -= edge;
	
	
    return answer;
}*/

int main(){
	int w=0;
	int h=0;
	cin >> w;
	cin >> h;
	
	solution(w, h);
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

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
/*그나마 가장 정확도 높은 방법, 오류 있음*/
 
long long solution(int w,int h) {
    long long answer = 0;
	answer = (w-1) * h;
	
	double space = (double)h/ (double)w;
	//오류 없음->space = 1.5(w=8, h=12)
    
    //cout << space << endl;
    
    
	for(int i=1; i!=w; ++i){
		if((i*space)!=(int)(i*space)){
		//오류 발생 -> 컴파일 에러, 나누기는 가능하지만 나머지는 안된다는것	
		//cout << (i*space) << " " <<  (int)(i*space) << endl;
			--answer;
		}
	}
	cout << answer << endl;
    return answer;
}

/*실패...
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
	answer = w * h-h;
	int same = background(w, h);
	
	int edge = 0;
    if(same!=0){
        edge = w-w/same;

    }
    else{
        edge = w-1;
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

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long solution(int w,int h) {
	/*
    int answer = 0;
    int mini = min(w,h);
    int maxi = max(w,h);
    
    
    int sys = maxi / mini;
    
    if(maxi % mini != 0) sys += 1;
    
    answer = w * h - (sys * mini);
    */
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
}

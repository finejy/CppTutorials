#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ternary(int n){
	string result="";
    
	int i=1;
	while(n>0){
		result= to_string(n%3) + result;
		n/=3;
	}
	
	return result;
	
}

int opposite(string t){
	string::size_type len = t.size();
	string str_result="";
	
	for(int i=0; i!=len; ++i){
		str_result+=t.at(len-1-i);
	}
	
	int result=stoi(str_result);
	 
	return result;
}

int decimal(int n){
	int result=0;
	int term=1;
	
	while(n>0){
		result+=n%10*term;
		n/=10;
		term*=3;
	}
	return result;
	
}

int solution(int n) {
    int answer = 0;
    string ter="";
    int opp=0;
    //cout << answer << endl;
    ter = ternary(n);
    //cout << ter << endl;
    opp = opposite(ter);
    //cout << opp << endl;
    answer = decimal(opp);
    //cout << answer << endl;
    return answer;
}



int solution(int n) {
    int answer = 0;
    string ter="";
    int opp=0;
    
    ter = ternary(n);
    
    opp = opposite(ter);
    
    answer = decimal(opp);
    cout << answer << endl;
    return answer;
}


int main(){
	int n=0;
	cin >> n;
	solution(n);
	return 0;
}

//특정 상황에서 aborted(core dumped) 에러 발생.  

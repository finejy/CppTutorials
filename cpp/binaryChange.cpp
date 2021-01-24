#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <bitset>
 
using namespace std;

//10진수 -> 2진수 변환(int(long long) 출력 -> 해당 코드에서는long long 타입을 사용해도 용량 초과 오류 발생)(for문 사용하는 특이한 방식) 
/*
long long binary(int n){
	long long result = 0;
	for(int i=1; n > 0; i*=10){
		int bin = n % 2;
		result += bin * i;
		n /= 2;
	}
	
	return result;
}*/
//string 을 출력하는 새로운 함수
string str_binary(int n){
	string result = "";
	while(n > 0){
		int bin = n % 2;
		string str_bin = to_string(bin);
		result = str_bin + result;
		n /= 2;
	}
	return result;
} 


vector<int> solution(string s) {
	s.reserve(150000);
    vector<int> answer{0, 0};
	while(true){
		int new_len = 0;
	
   		string::size_type len = s.size();
   		 
		if(len <=1) break;
		else{
		    for(int i=0; i!=len; ++i){
				if(s.at(i) == '0'){
					answer[1] +=1;
				}
				else if(s.at(i) == '1') new_len +=1;
			}
			
			s = str_binary(new_len);
			answer[0] +=1;
		}	
		cout << s  << "!" << endl;
	}
	
    cout << answer[0] << ' ' << answer[1] << ends;
    
    return answer;
}

int main(){
	string num;
	/*
	for(int i=0; i!=75000; ++i){
		num +="10";
	}*/
	cin >> num;
	solution(num);
}

/*Solution : for문 이용해서 0을 제외한 원소들을 새로운 string에 입력, 해당 string의 size와 각 위치에서의 index를 이용해 2진수를 10진수로 변환하여 
	to_string 함수를 이용해 string 객체로 변경해 출력하는 함수를 만듬.(이때 이진법으로 변환하는 함수를 사용하는 경우, 하지않는 경우는 따로 작성하도록 하겠음.)*/ 
/*Q1. 코드 실행 시 시간 초과 에러가 나는 경우를 확인했음. while의 탈출 조건을 len_2 == 1에서  len_2 <=1로 변경하니 시간 초과 문제가 해결되는 것으로 보아 최종적으로
	 len_2가 0이 되는 경우가 있는 것으로 판단됨.*/ 


/*Q2. 입력값이 매우 클 경우 출력되는 s값이 음수가 되는 현상 발생. 아마 할당된 용량을 초과하기 때문인 것으로 보이나따로 할당하지 않더라도 기존에 할당된 용량을 
	초과하면 string은 할당량을 2배로 증가시킨다고 알고 있음. 확인 결과 binary 함수에서 오류가 발생한 것을 확인. binary 함수의 return값인 result의 허용 용량이
	코드에서 지원하는 string 입력값의 용량에 미치지 못하는 오류로 예상됨*/ 
	

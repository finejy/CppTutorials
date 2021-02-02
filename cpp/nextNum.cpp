#include <string>
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

string binary(int n){
	string result;
	
	while(n>0){
		result=to_string(n%2) + result;
		n/=2;
		//문제없음 
		cout << result<< endl;
	}
	
	return result;
}

string next_num(string n){
	string::size_type len = n.size();
	int tof=0;
	int index=0;
	string result;
	
	for(int i=len-1;i>=0; --i){
		if(n.at(i)=='1'){
			++tof;
		}
		else if(n.at(i)=='0'&&tof>0){
			index=i;
			--tof;
			break;
		}
	}
	int zero_num=0;
	
	if(index>0){
		zero_num=len-index-2-tof;
		result = n.substr(0,index); 
		result+="10";
	}
	else{
		++len;
		zero_num=len-tof;
	}
	//문제없음
	//cout << zero_num << endl; 
	
	for(int j=0; j!=len; ++j){
		if(index==0){
			if(j==0) result+="1";
			else if(zero_num>0){
				result+="0";
				--zero_num;
			}
			else{
				result+="1";
			}
		}
		else{
			if(j>index+1){
				if(zero_num>0){
					result+="0";
					--zero_num;
				}
				else{
					result+="1";
				}
			}
		}
	}
	cout << result << endl;
	return result; 
}

int bigger_num(string n){
	string::size_type len = n.size();
	int term=1;
	int result=0;
	
	for(int i=len-1; i>=0; --i){
		if(n.at(i)=='1'){
			result+=term;
		}
		term*=2;
	}
	
	return result;
}



int solution(int n) {
    int answer = 0;
    
    answer = bigger_num(next_num(binary(n)));
    
    cout << answer << endl;
       
    return answer;
}

int main(){
	//time_t start, end;
	//double result;
	
	//start = time(NULL);
	int n=0;
	cin >> n;
	solution(n);
	//end = time(NULL);
	//result = (double)(end-start);
	//cout << result<< endl;
	return 0;
}

/*Solution: i==len-1부터 --i연산을 하는 반복문을 이용해 뒷자리부터 가장 첫번째로 1다음으로 0이 나온 위치를검색, 해당 위치와 다음 위치의 0과 1을 변경하고
	그 전에 나온 1을 모두 끝자리로 옮겨 문제 조건에 성립되는 수를 계산한다. */
/*시간초과 에러 발생. 조금 더 코드를 가볍게 만들려면 세	함수를 합쳐 next_num 함수에서 index를 찾았을 때 그 앞 범위에 있는 수들에 대한
	연산을 다시 반복하지 않고, 해당 범위의 원소들은 바로 결과값에 대입하는 방식을 사용하면 될 것으로 판단됨.-> 그렇게 풀어도 문제 발생, */ 

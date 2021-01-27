#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
string solution(string number, int k) {
    string answer = "";
    int start = 0;
    while(k>0){
    	int maximum = 0;
    	int max_index = 0;
    	if(k>1){
			for(int i=start; i!=start + k+1; ++i){
    			const char *char_num=&number.at(i);
    			cout << "at" <<char_num << ends; 
    			int int_num = atoi(char_num);
    			cout << "int " << int_num << ends;
    			if(int_num > maximum){
    				maximum = int_num;
    				max_index = i;
    				//cout << maximum << ends;
				}
				//cout << "f" << i << ends;
			}
			//cout << "in" <<max_index << " " << ends;;
			k -= max_index;
			number.erase(start, max_index);
			start += 1;
			//cout << "k" << k << ends;
		}
		else{
			number.erase(start, 1);
			--k;
			//cout << "else" << ends;
		}
		//cout << start << " " << ends;
		
	}	
    
    return number;
}
*/
/*
string solution(string number, int k){
	string answer = "";
	int start = 0;
	vector<char> num;
	string num_line = "0123456789";
	
	for(int i=0; i!=10; ++i){
		num.push_back(num_line.at(i));
	}
	
	while(k > 0){
		int maximum = 0;
		int max_index = 0;
		if(k > 1){
			for(int i=start; i!=start + k+1; ++i){
				char n = number.at(i);
				vector<int>::iterator iter = find(num.begin(), num.end(), n);
				int seat = distance(num.begin(), iter);
				if(seat > maximum){
					maximum = seat;
					max_index = i;
				}
			}
			k -= max_index;
			number.erase(start, max_index);
			start +=1;
		}
		else{
			number.erase(start, 1);
			--k;
		}
	}
	return number;
} 

int main(){
	string number;
	int k = 0;
	cin >> number;
	cin >> k;
	cout << solution(number, k)<< ends;
	return 0;
	
}*/
/*실패. 예외를 고려해야하는 방법 임 
int background(int& n, int& k, string& number){
	string num = "0123456789";
	int maximum = 0;
	int max_index = 0;
	
	cout << number << " " << n << " " << k << endl;
	
	for(int i=n; i!=n+k; ++i){
		if(num.find(number.at(i)) > maximum){
			maximum = num.find(number.at(i));
			max_index = i;
			cout << maximum << " " << max_index << endl;
		}
	}
	number.erase(n, max_index-n);
	k=k+n-max_index;
	++n;
	
	return 0;
}*/

int background(int& k, string& number){
	string::size_type len = number.size();
	
	while(k > 1){
		while()
	}
} 

string solution(string number, int k){
	int n=0;
	while(k!=0){
		background(n, k, number);
	}
	
	return number;
}

int main(){
	string number;
	int k=0;
	cin >> number;
	cin >> k;
	cout << solution(number, k) << ends;
	
	return 0;
}

/*Solution1. while 문을 이용하여 시작점부터 이전에 제외하고 남은 k의 값만큼의
	범위 내에서 수의 최댓값의 위치를 찾고, 범위 내에서 그 최댓값 앞에 있는
	모든 원소들을 제거하여 k가 0이 될때까지 반복.*/
/*Q1. atoi 함수 사용 시의 문제, numbers.at(i)는 해당 위치의 원소 하나의 값만
	반환하지만, 타입을 맞춰주기 위해 const char로 정의한 *char_num을 쓰게 되면
	해당 범위 전체의 수를 다 반환한다. */
/*P1. atoi 함수에 들어가는 변수가 non-class 타입인 const char*이라 상황에 따라 해당 객체를 수정할 수 없다는 문제가 있음.
	-> 0부터 9까지의 자연수를 순서대로  원소로 가지는 vector을 만들어 해당 원소의 index를 찾아 비교하는 방식으로 변경.*/ 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

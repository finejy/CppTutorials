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
/*����. ���ܸ� ����ؾ��ϴ� ��� �� 
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

/*Solution1. while ���� �̿��Ͽ� ���������� ������ �����ϰ� ���� k�� ����ŭ��
	���� ������ ���� �ִ��� ��ġ�� ã��, ���� ������ �� �ִ� �տ� �ִ�
	��� ���ҵ��� �����Ͽ� k�� 0�� �ɶ����� �ݺ�.*/
/*Q1. atoi �Լ� ��� ���� ����, numbers.at(i)�� �ش� ��ġ�� ���� �ϳ��� ����
	��ȯ������, Ÿ���� �����ֱ� ���� const char�� ������ *char_num�� ���� �Ǹ�
	�ش� ���� ��ü�� ���� �� ��ȯ�Ѵ�. */
/*P1. atoi �Լ��� ���� ������ non-class Ÿ���� const char*�̶� ��Ȳ�� ���� �ش� ��ü�� ������ �� ���ٴ� ������ ����.
	-> 0���� 9������ �ڿ����� �������  ���ҷ� ������ vector�� ����� �ش� ������ index�� ã�� ���ϴ� ������� ����.*/ 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

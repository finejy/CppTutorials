#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

using namespace std;

string solution(string number, int k){
	string::size_type len = number.size();
	//list�� ��ȯ�� �� �ϴ� �۾��� string���� �ϴ� �۾��� ȿ���� Ȯ�� �ʿ� 
	list<int> num_element(len, 0);
	
	list<int>::iterator a = num_element.begin();
	for(int i=0; i!=len; ++i){
		char character = number.at(i);
		char *new_character = &character;
		(*a) = atoi(new_character);
		++a;
	}
	
	
	int start = 0;
	while(k>0){
		list<int>::iterator x = num_element.begin();
			
		if(start > 1){
			for(int j=0; j!=start; ++j){
				++x;
			}
		}
		
		if(k==1){
			
			while(x!=num_element.end()){
				list<int>::iterator y = x;
				++y;
				if((*x) < (*y)){
					x = num_element.erase(x);
					--k;
					break;
				}
			}
			if(k==1){
				num_element.erase(x);
				--k;
			}
		}
		
		else if(k > 1){
			int new_k = k;
			//list<int>::iterator count = num_element.begin();
			int max = 0;
			
			list<int>::iterator y = x;
			while(new_k>0){
				if((*x) > max){
					max = (*x);
					//count = x;
				}
				++x; 
				--new_k;
				//cout << new_k << " " << ends;
			}
			
			while((*y)<max){
				y = num_element.erase(y);
	            //cout << *count << " " << ends;
	            //count�� �̷��� ����ϸ� erase �Լ��� �۵��ϸ鼭 num_element�� iterator�̸鼭 y���� �ڿ��ִ� count�� �ʱ�ȭ�Ǹ鼭 �ǹ̾��� ���� ������ �ȴ�. 
				//--count;
				--k;
			}
			++start;
		}
		
		cout << k << endl;
	}
	string answer;
	for(list<int>::iterator i = num_element.begin(); i!=num_element.end(); ++i){
		answer += to_string(*i);
	}
	return answer;
}

int main(){
	string number;
	int k = 0;
	cin >> number;
	cin >> k;
	
	cout << solution(number, k) << endl;
}

 

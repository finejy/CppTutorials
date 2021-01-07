#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string s){
	
	long long answer = 0;
	
	vector<string>::size_type len = s.size();
	int part = 0;
	if(len == 1) return answer;
	//part�� ���� Ȯ�� 
	for(int i=0; i!=len-1; ++i){
		if(s.at(i) != s.at(i+1)) part +=1;
	}
	if(part <=1) return answer;
	
	//part�� ���� �� �ش� ���ĺ��� ���Ϳ� ���� 
	vector<int> part_len(part, 0);
	vector<string> part_alpha(part, "");
	
	for(int i=0; i!= part; ++i){
		for(int j=0; j!=len; ++j){
			if(s.at(i)!= s.at(i+1)) break;
			else{
				part_len[i] +=1;
				if(part_alpha[i]=="") part_alpha[i] = s.at(i);
			} 
			
		}
	}
	 
	
	int between=0;
	
	for(int i=0; i!=part-1; ++i){
		for(int j=i+1; j!=part; ++j){
			if(j-i==1){
				between=0;
			}
			else if(part_alpha[i] != part_alpha[j]){
				between=0;
				for(int k=i+1; k!=j; ++k){
					between += part_len[k];
				}
			}
			answer+=part_len[i]*part_len[j]*(between+1);
			
		}
	}
		
	cout << answer << endl;
	
	return answer;	
	
}

int main(){
	string s;
	cin >> s;
	solution(s);
	return 0;
}

//�̿��ϴ� ������ ���ڳ��� ������ part�� ������, ������ part�� ���� �Ÿ��� ���ؼ� ��� �Ƹ��ٿ��� ��� 
//21.01.07 part_len�� ���Ұ� 1�� ��� ������� 0�� ������ ���� �߻�, index�� ��� �����ε� 

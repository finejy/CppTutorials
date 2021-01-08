#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string s){
	
	long long answer = 0;
	
	vector<string>::size_type len = s.size();  
	if(len == 1) return answer;
	int part = 1;
	
	//part�� ���� Ȯ�� 
	for(int i=0; i!=len-1; ++i){
		if(s.at(i) != s.at(i+1)) part +=1;
	}
	cout << part << endl;
	if(part <=1) return answer;
	
	//part�� ���� �� �ش� ���ĺ��� ���Ϳ� ���� 
	vector<int> part_len(part, 0);
	vector<string> part_alpha(part, "");
	int part_now=0;
	
	/*�ݺ��� ����. ù ��° for���� �� ��° for�� ��ġ ���� �ʿ� 
	for(int i=0; i!= part; ++i){
		for(int j=0; j!=len-1; ++j){
			if(s.at(j)!= s.at(j+1)) break;
			else{
				part_len[i] +=1;
				if(part_alpha[i]=="") part_alpha[i] = s.at(j);
			} 
			
		}
	}*/
	for(int i=0; i!=len-1; ++i){
		if(part_alpha[part_now]=="") part_alpha[part_now] = s.at(i);
		
		if(s.at(i)!= s.at(i+1)){
			part_len[part_now]+=1;
			part_now +=1;
		}
		else{
			part_len[part_now]+=1;
			
		}
	}
	part_len[part-1]+=1;
  
	//������ ��  part ���̿� �����ϴ� �ٸ� part ��� �ش� part���� ������ �̿��� �� �����  �Ƹ��ٿ� ����. 
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
	
	return answer;	
	
}

int main(){
	string s;
	cin >> s;
	cout << solution(s) << endl;;
	return 0;
}

//�̿��ϴ� ������ ���ڳ��� ������ part�� ������, ������ part�� ���� �Ÿ��� ���ؼ� ��� �Ƹ��ٿ��� ��� 
//21.01.07 part_len�� ���Ұ� 1�� ��� ������� 0�� ������ ���� �߻�, index�� ��� �����ε� 
//ù��° ���� for������ s�� ���Ҹ� �޾ƿ��� �������� ���� i�� j�� �ٲ㼭 �ۼ��� ���� �߰�-> ���� �Ϸ�
//21.01.08 ������ ���������� ����ε� ����� ���. ������ ������ ���� ���� ��Ȳ ����, �Է°��� ũ�� �ð� �ʰ� ���� �߻�.
//���� ��ó programmers; https://programmers.co.kr/learn/courses/30/lessons/68938?language=cpp 

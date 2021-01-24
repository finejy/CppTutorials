#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <bitset>
 
using namespace std;

//10���� -> 2���� ��ȯ(int(long long) ��� -> �ش� �ڵ忡����long long Ÿ���� ����ص� �뷮 �ʰ� ���� �߻�)(for�� ����ϴ� Ư���� ���) 
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
//string �� ����ϴ� ���ο� �Լ�
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

/*Solution : for�� �̿��ؼ� 0�� ������ ���ҵ��� ���ο� string�� �Է�, �ش� string�� size�� �� ��ġ������ index�� �̿��� 2������ 10������ ��ȯ�Ͽ� 
	to_string �Լ��� �̿��� string ��ü�� ������ ����ϴ� �Լ��� ����.(�̶� ���������� ��ȯ�ϴ� �Լ��� ����ϴ� ���, �����ʴ� ���� ���� �ۼ��ϵ��� �ϰ���.)*/ 
/*Q1. �ڵ� ���� �� �ð� �ʰ� ������ ���� ��츦 Ȯ������. while�� Ż�� ������ len_2 == 1����  len_2 <=1�� �����ϴ� �ð� �ʰ� ������ �ذ�Ǵ� ������ ���� ����������
	 len_2�� 0�� �Ǵ� ��찡 �ִ� ������ �Ǵܵ�.*/ 


/*Q2. �Է°��� �ſ� Ŭ ��� ��µǴ� s���� ������ �Ǵ� ���� �߻�. �Ƹ� �Ҵ�� �뷮�� �ʰ��ϱ� ������ ������ ���̳����� �Ҵ����� �ʴ��� ������ �Ҵ�� �뷮�� 
	�ʰ��ϸ� string�� �Ҵ緮�� 2��� ������Ų�ٰ� �˰� ����. Ȯ�� ��� binary �Լ����� ������ �߻��� ���� Ȯ��. binary �Լ��� return���� result�� ��� �뷮��
	�ڵ忡�� �����ϴ� string �Է°��� �뷮�� ��ġ�� ���ϴ� ������ �����*/ 
	

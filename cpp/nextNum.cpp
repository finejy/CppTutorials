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
		//�������� 
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
	//��������
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

/*Solution: i==len-1���� --i������ �ϴ� �ݺ����� �̿��� ���ڸ����� ���� ù��°�� 1�������� 0�� ���� ��ġ���˻�, �ش� ��ġ�� ���� ��ġ�� 0�� 1�� �����ϰ�
	�� ���� ���� 1�� ��� ���ڸ��� �Ű� ���� ���ǿ� �����Ǵ� ���� ����Ѵ�. */
/*�ð��ʰ� ���� �߻�. ���� �� �ڵ带 ������ ������� ��	�Լ��� ���� next_num �Լ����� index�� ã���� �� �� �� ������ �ִ� ���鿡 ����
	������ �ٽ� �ݺ����� �ʰ�, �ش� ������ ���ҵ��� �ٷ� ������� �����ϴ� ����� ����ϸ� �� ������ �Ǵܵ�.-> �׷��� Ǯ� ���� �߻�, */ 

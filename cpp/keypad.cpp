#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int movement(int m, int n){
	return abs(m-n)/3+abs(m-n)%3;
}
/*
string add(string answer, string s, int n){
	for(int i=0; i!=n; ++i){
		answer+=s;
	}
	return answer;
}*/


string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int>::size_type len = numbers.size();
    
    //�ڵ��� ���Ǽ��� ���� index 0�� ������"#", index 1�� �޼� "*"���� �ΰ� ���� 
	vector<int> seat={12, 10};
    
	string h = "";
	vector<string> rol={"R", "L"};
	int main_hand = 0;
	
	if(hand == "right"){
		h="R";
		main_hand=0;
	}
	else{
		h="L";
		main_hand=1;
	}
	
	for(int i=0; i!=len; ++i){
		if(numbers[i]==0){
			numbers[i]=11;
		}
		//int move=0;
		if(numbers[i]%3==2){
			if(movement(numbers[i], seat[0])==movement(numbers[i], seat[1])){
				//move = movement(numbers[i], seat[main_hand]);
				seat[main_hand]=numbers[i];
				//add(answer, h, move);
				answer+=h;
			}
			else if(movement(numbers[i], seat[0])>movement(numbers[i], seat[1])){
				//move = movement(numbers[i], seat[1]);
				seat[1]=numbers[i];
				//add(answer, "L", move);
				answer+="L";
			}
			else{
				//move = movement(numbers[i], seat[0]);
				seat[0]=numbers[i];
				//add(answer, "R", move);
				answer+="R";
			}
		} 
		else{
			//move = movement(numbers[i], seat[numbers[i]%3]);
			seat[numbers[i]%3]=numbers[i];
			//add(answer, rol[numbers[i]%3], move);
			answer+=rol[numbers[i]%3];
		}
	}    
    
    return answer;
}

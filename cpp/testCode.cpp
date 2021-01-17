#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

int main(){
	/*문자열에 특수 기호 입력하는 법 
	cout << "This (\") is a quote, and this (\\) is a backslash." << ends;
	*/
	/*size() 함수의 결과값이 index로 나오는지 실제 숫자로 나오는지 확인 
	string s = "abcde";
	string::size_type len = s.size();
	cout << len << endl;
	*/
	
	
	/*모든 원소가 같은 크기의 int 타입인 벡터에서 index를 입력하면 어떻게 되나*/
	/*vector<int> same(5, 7);
	cout << same[1] << endl;
	for(int i=0; i!=5; ++i){
		cout << same[i] << ends;
	}
	*/
	
	
	/*이차원 vector에서 size() 함수를 어떻게 써야 하는가 -> 열을 출력한다*/
	/*int x =0;
	int y =0;
	vector<int> first;
	vector<vector<int> > second;
	while(cin >> x){
		first.push_back(x);
		cin >> y; 
		first.push_back(y);
	}
	int z =0;
	while(z < 10){
		second.push_back(first);
		++z;
	}
	cout << first.size() << " " << second.size() << endl;
	*/
	
	
	/*char(string)에서 int로의 형 변환이 가능한가*/
	/*string str_i = "77";
	
	int num = stoi(str_i);
	cout << num - 1 << endl;
	*/
	
	/*getline 함수로 줄바꿈 문자를 string으로 인식할 수 있는가*/ 
	string str1;
	string str2;
	
	getline(cin, str1);
	
	cin >> str2;
	
	cout << str1 << " " << str2 << ends;
	
	
	
	return 0; 
	
	return 0;
}

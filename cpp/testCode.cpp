#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

int main(){
	/*���ڿ��� Ư�� ��ȣ �Է��ϴ� �� 
	cout << "This (\") is a quote, and this (\\) is a backslash." << ends;
	*/
	/*size() �Լ��� ������� index�� �������� ���� ���ڷ� �������� Ȯ�� 
	string s = "abcde";
	string::size_type len = s.size();
	cout << len << endl;
	*/
	
	
	/*��� ���Ұ� ���� ũ���� int Ÿ���� ���Ϳ��� index�� �Է��ϸ� ��� �ǳ�*/
	/*vector<int> same(5, 7);
	cout << same[1] << endl;
	for(int i=0; i!=5; ++i){
		cout << same[i] << ends;
	}
	*/
	
	
	/*������ vector���� size() �Լ��� ��� ��� �ϴ°� -> ���� ����Ѵ�*/
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
	
	
	/*char(string)���� int���� �� ��ȯ�� �����Ѱ�*/
	/*string str_i = "77";
	
	int num = stoi(str_i);
	cout << num - 1 << endl;
	*/
	
	/*getline �Լ��� �ٹٲ� ���ڸ� string���� �ν��� �� �ִ°�*/ 
	string str1;
	string str2;
	
	getline(cin, str1);
	
	cin >> str2;
	
	cout << str1 << " " << str2 << ends;
	
	
	
	return 0; 
	
	return 0;
}

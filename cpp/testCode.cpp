#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <math.h>

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
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*��� ���Ұ� ���� ũ���� int Ÿ���� ���Ϳ��� index�� �Է��ϸ� ��� �ǳ�*/
	
	/*vector<int> same(5, 7);
	cout << same[1] << endl;
	for(int i=0; i!=5; ++i){
		cout << same[i] << ends;
	}
	*/
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
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
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*getline �Լ��� �ٹٲ� ���ڸ� string���� �ν��� �� �ִ°�*/ 
	
	/*string str1;
	string str2;
	
	getline(cin, str1);
	
	cin >> str2;
	
	cout << str1 << " " << str2 << ends;
	*/
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*������ vector���� ���� ���� ���� ���� �ٸ� �� sort�� ����� ��� �Ǵ°�*/
	
	/*vector<vector<int>> num = {{1, 2, 3, 4}, {1, 0, 1}, {1}, {2}};
	vector<vector<int>>::size_type len = num.size();
	
	sort(num.begin(), num.end());
	
	cout << num[2][3] << endl;
	
	for(int i=0; i!=len; ++i){
		vector<int>::size_type len2 = num[i].size();
		
		cout << len2 << endl;
		
		for(int j=0; i!=len2; ++j){
			//cout << num[i][j] << " " << ends;
		}
		
		cout << endl;
	} */
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*unique �Լ��� ������� �� �ڷ� �Ѿ�� ������ ���� ��� �ٲ���� Ȯ��
		-> �ڷ� �̵��ϴ� ������ ������ ���� �� +1�� �� ���·� �̵��� ���� Ȯ��(��°� {1, 2, 3, 2, 3})*/
		
	/*vector<int> s = {1, 1, 2, 2, 3};
	
	unique(s.begin(), s.end());
	
	//cout << unique(s.begin(), s.end()) << ends; 
	for(int i=0; i!=5; ++i){
		cout << s[i] << " " << ends;
	}*/
	
	/*binaryChange.cpp ���α׷� ���� Ȯ��-binary �Լ��� ���� ������ ������ �Ǵ�*/ 
	/*
	int n = 75000;
	
	int result = 0;
	for(int i=1; n > 0; i*=10){
		int bin = n % 2;
		result += bin * i;
		n /= 2;
	}
	//cout << result << endl;
	//cout<< to_string(result) << endl; 
	cout << bitset<150000>(n) << endl;
	*/
	
	/*for���� ���ǿ��� �����ϴ� ���� i�� ������ ������ ��� ��� �Ǵ°� -> ����. �׳� for������ i�� �ٽ� �������ָ� �ű⼭���� �ٽ� �����ϴ���*/
	/*int x = 0;
	for(int i=0; i!=10; ++i){
		
		cout << i << " " << ends;
		if(i==5 && x==0){
			i-=2;;
			++x;
		}
		
	} */
	
	/*vector���� min �� ���ϱ�*/
	/*vector<int> num = {1, 2, 3, 4, 5};
	int minimum = *min_element(num.begin(), num.end());
	
	cout << minimum;*/
	
	/*fmod �Լ� ����غ���->�������� �ƴ϶� �����̾�������*/
	/*double dou = fmod(12.12, 12.11);
	
	cout << dou << endl;*/
	 
	/*�⺻ ������ const ������ ���ʹ� ���� ��ü�� ������ �� �� ����, �̿� ���� ���纻�� ���� �Ұ����ϴ�.*/ 
	vector<double> homework = {1, 2, 3, 5, 4};
	
	const vector<double>& hw = homework;
	
	vector<double> hw2 = hw;
	
	sort(hw.begin(), hw.end());
	
	for(int i=0; i!=hw.size(); ++i){
		cout << hw[i] << " " << ends;
	}



	return 0;
	
}

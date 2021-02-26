#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <math.h>

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
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*모든 원소가 같은 크기의 int 타입인 벡터에서 index를 입력하면 어떻게 되나*/
	
	/*vector<int> same(5, 7);
	cout << same[1] << endl;
	for(int i=0; i!=5; ++i){
		cout << same[i] << ends;
	}
	*/
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
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
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*getline 함수로 줄바꿈 문자를 string으로 인식할 수 있는가*/ 
	
	/*string str1;
	string str2;
	
	getline(cin, str1);
	
	cin >> str2;
	
	cout << str1 << " " << str2 << ends;
	*/
	
	
	/*--------------------------------------------------------------------------------------------------------------------------------------*/
	
	
	/*이차원 vector에서 원소 별로 행의 수가 다를 때 sort의 결과는 어떻게 되는가*/
	
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
	
	
	/*unique 함수를 사용했을 때 뒤로 넘어가는 쓰레기 값이 어떻게 바뀌는지 확인
		-> 뒤로 이동하는 쓰레기 값들은 원래 값 +1을 한 형태로 이동한 것을 확인(출력값 {1, 2, 3, 2, 3})*/
		
	/*vector<int> s = {1, 1, 2, 2, 3};
	
	unique(s.begin(), s.end());
	
	//cout << unique(s.begin(), s.end()) << ends; 
	for(int i=0; i!=5; ++i){
		cout << s[i] << " " << ends;
	}*/
	
	/*binaryChange.cpp 프로그램 오류 확인-binary 함수의 범위 문제인 것으로 판단*/ 
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
	
	/*for문의 조건에서 정의하는 변수 i를 참조로 정의할 경우 어떻게 되는가 -> 실패. 그냥 for문에서 i를 다시 정의해주면 거기서부터 다시 시작하더라*/
	/*int x = 0;
	for(int i=0; i!=10; ++i){
		
		cout << i << " " << ends;
		if(i==5 && x==0){
			i-=2;;
			++x;
		}
		
	} */
	
	/*vector에서 min 값 구하기*/
	/*vector<int> num = {1, 2, 3, 4, 5};
	int minimum = *min_element(num.begin(), num.end());
	
	cout << minimum;*/
	
	/*fmod 함수 사용해보기->나눗셈이 아니라 뺄셈이었던것임*/
	/*double dou = fmod(12.12, 12.11);
	
	cout << dou << endl;*/
	 
	/*기본 벡터의 const 참조인 벡터는 벡터 자체의 변동을 줄 수 없고, 이에 대한 복사본도 변동 불가능하다.*/ 
	vector<double> homework = {1, 2, 3, 5, 4};
	
	const vector<double>& hw = homework;
	
	vector<double> hw2 = hw;
	
	sort(hw.begin(), hw.end());
	
	for(int i=0; i!=hw.size(); ++i){
		cout << hw[i] << " " << ends;
	}



	return 0;
	
}

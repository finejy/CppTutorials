#include <iostream>
#include <vector>
#include <string>
 
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
	vector<int> same(5, 7);
	cout << same[1] << endl;
	for(int i=0; i!=5; ++i){
		cout << same[i] << ends;
	}
	return 0;
}

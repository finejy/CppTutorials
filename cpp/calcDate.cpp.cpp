#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector<string> date = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
	vector<int> day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int a=0;
	int b=0;
	string answer="";
	
	cin >> a >> b >> endl;
	
	for(int i=0; i!=a-1; ++i){
		b += date[i];
	}
	
	answer = day[b%7];
	
	cout << answer << endl;
	
	return 0;
	
}

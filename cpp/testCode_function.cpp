#include <string>
#include <vector>
#include <iostream>

using namespace std;


int function(int& a, int len, int function){
	for(int i=0; i!=len; ++i){
		function;
		++a;
	}
}

int result(int a, int b){
	cout << a << " " << b << ends;
	return 0;
}

int main(){
	int a=0;
	int b=0;
	int len=5;
	function(a, len, function(b, len, result(a, b)));
	
	return 0;
}

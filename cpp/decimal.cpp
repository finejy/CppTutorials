#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
int solution(int n) {
    int answer = 0;
    vector<int> num(n-1, 0);
    vector<int> check(n-1, 1);
    if(n==2) return 1;
    else if(n==3) return 2;
    
	for(int i=0; i!=n-1; ++i){
    	num[i]=i+2;
	}
	
	for(int i=0; i!=n/2-1; ++i){
			
		for(int j=i+1; j!=n-1; ++j){
			if(num[j]%num[i]==0&&check[j]!=0){
				check[j]=0;
			}
		}
	}
	
	for(int i=0; i!=n-1; ++i){
		if(check[i]!=0){
			cout << num[i] << ends;
			++answer;
		}
	}
	cout << endl;
	cout << answer << endl;
	
    return answer;
}*/

int solution(int n) {
    int answer = 0;
    vector<int> num={2, 3};
    if(n==2) return 1;
    else if(n==3) return 2;
    
	for(int i=1; i!=n-1; ++i){
    	if((i+2)%2!=0&&(i+2)%3!=0){
    		num.push_back(i+2);
		}
	}
	
	int index_1=2;
	vector<int>::size_type len = num.size();
	/*
	while(num[index_1] <= n/2){
		int index_2=index_1+1;
		while(index_2 < len){
			if(num[index_2]%num[index_1]==0){
				num.erase(num.begin()+index_2);
				--len;
			}
			else{
				++index_2;
			}
		}
		++index_1;
		
	}*/
	
	int index_2 = 3;
	while(num[index_1] <= n/2){
		
		if(num[index_2]%num[index_1]==0){
			num.erase(num.begin()+index_2);
			--len;
		}
		else{
			++index_2;
		}
		if(index_2==len){
			++index_1;
			index_2 = index_1+1;
		}
		
	}
	
	cout << answer << endl;
	answer = len;
	
    return answer;
}

int main(){
	int n=0;
	cin >> n;
	
	solution(n);
	return 0;
}

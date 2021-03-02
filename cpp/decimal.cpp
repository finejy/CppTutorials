#include <string>
#include <vector>
#include <iostream>
#include <list>

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
/*list, iterator »ç¿ë ver.1 
int solution(int n) {
    int answer = 0;
    if(n==2) return 1;
    else if(n==3) return 2;
    
    list<int> num;
    num.push_back(2);
    num.push_back(3);
    
	for(int i=1; i!=n-1; ++i){
    	if((i+2)%2!=0&&(i+2)%3!=0){
    		num.push_back(i+2);
		}
	}
	
	cout << num.size() << endl;
	
	list<int>::iterator iter_1 = num.begin();
	++iter_1;
	++iter_1;
	list<int>::iterator iter_2 = ++iter_1;
	
	while(*iter_2 <= n/2){
		
		if(*iter_2%*iter_1==0){
			iter_2 = num.erase(iter_2);
		}
		else{
			++iter_2;
		}
		if(iter_2==num.end()){
			++iter_1;
			iter_2 = ++iter_1;
		}
		
	}
	
	answer = num.size();
	
	cout << answer << endl;
	
    return answer;
}*/
/*
int solution(int n) {
    vector<int> num={2, 3};
    if(n==2) return 1;
    else if(n==3) return 2;
    
	for(int i=1; i!=n-1; ++i){
    	if((i+2)%2!=0){
            if((i+2)%3!=0){
    		num.push_back(i+2);
            }
		}
	}
	
	int index_1=2;
	vector<int>::size_type len = num.size();

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
	cout << len << endl;
	
    return len;
}*/

int solution(int n) {
    list<int> num;
    num.push_back(2);
    num.push_back(3);
    
    if(n==2) return 1;
    else if(n==3) return 2;
    
	for(int i=1; i!=n-1; ++i){
    	if((i+2)%2!=0){
            if((i+2)%3!=0){
    		num.push_back(i+2);
            }
		}
	}
	
	list<int>::iterator iter_1 = num.begin();
	++iter_1;
	++iter_1;
	list<int>::iterator iter_2 = iter_1;
	++iter_2;
	while(*iter_1 <= n/2){
		list<int>::size_type len = num.size();
		if((*iter_2)%(*iter_1)==0){
			iter_2 = num.erase(iter_2);
			--len;
		}
		else{
			++iter_2;
			--len;
		}
		if(len == 0){
			++iter_1;
			iter_2 = iter_1;
			++iter_2;
		}
	}
	int answer = num.size();
	cout << answer << endl;
	
    return answer;
}

int main(){
	int n=0;
	cin >> n;
	
	solution(n);
	return 0;
}

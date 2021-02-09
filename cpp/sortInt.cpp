#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    while(n>0){
    	num.push_back(n%10);
    	n/=10;
	}
	sort(num.begin(), num.end(), greater<int>());
	vector<int>::size_type len = num.size();
	for(int i=0; i!=len; ++i){
		answer+=num[i];
        if(i!=len-1){
            answer*=10;    
        }
	}
    return answer;
}

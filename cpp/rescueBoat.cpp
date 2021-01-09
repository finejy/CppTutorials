#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int>::size_type len = people.size();
	sort(people.begin(), people.end());
	
	int i=0;
	int j=1;
	while (true){
		if(i>len-j){
			//cout << "1 " << people[i] << " " << people[len -j] << endl;
			break;
		}
		
		else if(i == len - j){
			answer +=1;
			break;
		}
		if(people[i]==people[len-j]&&people[i]+people[len-j] > limit){
			
		}
		if(people[i]+people[len-j]<=limit){
			//cout << "2 " << people[i] << " " << people[len -j] << endl;
			answer+=1;
			i+=1;
			j+=1;	
		}
		
		else if(people[i]+people[len-j]>limit){
			//cout << "3 " << people[i] << " " << people[len -j] << endl;
			answer+=1;
			j+=1;
		}
	}
	return answer;
}



int main(){
	vector<int> people;
	int x =0;
	for(int i=0; i!=6; ++i){
		cin >> x;
		people.push_back(x);
	}
	int limit;
	cin >> limit;
	cout << solution(people, limit);
	return 0;
}

/*Solution: people 벡터를 크기 순으로 정렬하고 가장 작은 값과 큰 값부터 순차적으로 합이 limit보다 큰지 작은지 비교해서 필요한 구명 보트의 갯수를 계산*/
/*#1. 간단한 케이스에서는 오류 없이 실행되지만  결과값이 틀리는 케이스 발생 ->  케이스에 따라 오류가 생기거나 예외처리하지 않은 부분이 있는 것으로 판단
	=> people[i] == people[len-j]&&people[i]+people[len-j]<limit 인 경우 인식이 안되는 오류 확인
	=> while문의 조건이 people[i] <= limit/2인 경우 이므로 앞선 경우 해당 범위가 while 문의 인식 범위 바깥이므로 오류 발생
	=> 어차피 while문의 조건을 따로 지정하지 않아도 while문 내부의 break로 인해 무한 루프에 빠지지 않으므로 bool값인 true를 사용하기로함 */
//Question Clear!

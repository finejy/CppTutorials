#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int answer_index=0;
    
    answer_index=find(seoul.begin(), seoul.end(), "Kim")-seoul.begin();
    
    answer = "김서방은 " + to_string(answer_index) + "에 있다"; 
    
    return answer;
}

/*vector의 원소를 find 함수로 검색하는 경우 해당 위치의 iterator이 출력된다.
 	이 때 iterator끼리 차이를 계산하면 각 iterator간의 거리가 나타난다는 점을 이용해
	해당 위치의 index를 검색한다,*/ 

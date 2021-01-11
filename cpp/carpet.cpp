#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x=((brown - 4)/2 + sqrt(power((brown - 4)/2, 2) - 4 * yellow))/2 ;
    int y=((brown - 4)/2 - sqrt(power((brown - 4)/2, 2) - 4 * yellow))/2;
    answer.push_back(x+2);
    answer.push_back(y+2);
    return answer;
}



//Solution : 근의 공식 이용
 

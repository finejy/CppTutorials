#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> solution(int n) {
    vector<int> answer(n * (n + 1) / 2, 0);
    
    int num = 0;
    if(n % 3 != 0) num = n / 3 + 1;
    else num = n / 3;
    
    int start_num = 1;
    
    for(int a=0; a!=num; ++a){
        int l = n - 1 - 3 * a;
        int second_start = 2 * a * (1 + a) + (l * (1 + l)) / 2 + 2 * a * l;
        int last_start = second_start + l;
        for(int i=0; i!=l; ++i){
            answer[2 * a * (1 + a) + (i * (1 + i)) / 2 + 2 * a * i] = start_num + i;
            answer[second_start + i] = start_num + i + l;
            answer[last_start - (1 + i * (2 * n - 1)) / 2 - 2 * a * i] = start_num + i + 2 * l;
        }
        start_num += l * 3;
    }
    for(int i=0; i!= (n * (n+1))/2; ++i){
        cout << answer[i] << ends;
    }
    
    return answer;
}

int main(){
	int n;
	cin >> n;
	solution(n);
	return 0;
} 

/*num 맞는지 다시 확인(n = 6일 때 19는 2번째 삼각형에 포함된건데 다음 삼각형 조합에도 들어감)
	->	n % 3이 0일때와 아닐때 경우가 달라지므로 조건문으로 케이스 분리*/
/*삼각형 세번째 면 계산 오류 확인
	->	세번째 면이 시작하는 위치부터 위치를 이동할 때 등차 수열의 합 공식을 이용해 수식 수정*/ 
//현재 삼각형 마지막 면의 입력 위치에 문제가 발생 (n = 5 일때 12의 위치가 0의 인덱스에 있음) 
// n=6인 경우 core dumped 에러 발생 

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
   		if(n % 3 == 1 && l == 0) answer[2 * a * (1 + a)] = start_num;
		else{
			for(int i=0; i!=l; ++i){
            	answer[2 * a * (1 + a) + (i * (1 + i)) / 2 + 2 * a * i] = start_num + i;
            	answer[second_start + i] = start결_num + i + l;
            	answer[last_start - (i * (2 * l + 3 - i)) / 2 - 2 * a * i] = start_num + i + 2 * l;
        	}
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

/* P1. num 맞는지 다시 확인(n = 6일 때 19는 2번째 삼각형에 포함된건데 다음 삼각형 조합에도 들어감)
	->	n % 3이 0일때와 아닐때 경우가 달라지므로 조건문으로 케이스 분리*/
/* P2. 삼각형 세번째 변 계산 오류 확인
	->	세번째 변이 시작하는 위치부터 위치를 이동할 때 등차 수열의 합 공식을 이용해 수식 수정*/ 
// P3. 현재 삼각형 마지막 변의 입력 위치에 문제가 발생 (n = 5 일때 12의 위치가 0의 인덱스에 있음) -> 마지막 변 계산에서 다시 등차 수열의 합 공식 오류 발생 
// P4. n=6인 경우 core dumped 에러 발생 -> P3의 등차 수열의 합 공식 오류때문
// P5. n % 3 == 1인 경우 가장 중앙의 삼각형(원소가 1개)이 입력되지 않는 오류 -> l == 0이 되므로 두 번째 for문이 실행되지 않는 문제 발생 -> 조건문으로 상황 분리 
// 21.01.06 P1, P2 해결; P3, P4 발생
// 21.01.07 P3, P4 해결; P5 발생; P5 해결, 문제 해결
/*이차원 벡터 사용, index와 이동하는 규칙 찾아서 푸는 방법도 있음*/ 


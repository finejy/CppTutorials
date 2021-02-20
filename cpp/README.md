##README

Question list_calcGrade.cpp
while 문과 연산자 cin으로 임의의 양만큼 입력을 받을 때, enter로 인한 줄바꿈을 인식해 while문을 종료시킬 수 있나.

-------------------------------------------------------------------------------------------

New grammar
#1
조건문 간결하게 쓰는 방식
(변수) = (조건) ? (결과1) : (결과2);

=>
if(조건) (변수) = (결과1);
else (변수) = (결과2);
	
#2
#include <algorithm>
#include <functional>

vector<type> x;
sort(x.begin(), x.end(), greater<type>()); -> 내림 차순 정렬


#3
#include <algorithm>
#include <vector>

vector<int> s = {3, 1, 1, 2, 3};
sort(s.begin(), s.end());

s.erase(unique(s.begin(), s.end()), s.end());
-> s = {1, 2, 3}

/*unique(s.begin(), s.end());
-> s = {1, 2, 3, 1, 3};


-------------------------------------------------------------------------------------------

simple tips
#1
string과 vector 라이브러리 중 size()의 경우 string과 vector의 실제 길이를 나타내므로 반복문 등의 index에
넣을 때에는 주의할 것.

#2
vector의 경우 변수 뒤에 [index]를 입력해 해당 위치의 원소를 가져올 수 있지만, string의 경우 string 라이브
러리에 내장되어있는 .at(index) 함수를 사용해야 원소를 가져올 수 있다.



-------------------------------------------------------------------------------------------

Check again!

beautifulString.cpp
H_index.cpp
Tiling.cpp
triangleSnail.cpp
scoville.cpp
binaryChange.cpp(10진수 -> 2진수 변환 시 값이 큰 10진수를 2진수로 변경할 때 2진수의 용량이 long long 타입이 허용한 용량을 초과하는 문제)


-------------------------------------------------------------------------------------------


Memo

2021.01.02
C++ 문제 풀이 시작

2021.01.16
C++ 문제 풀이 중단/기본 문법 및 함수, library 공부부터 시작(Accelerated C++)

##binaryChange.cpp -> for문 범위 설정하는 방식 확인할 것
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    vector<int>::size_type len = nums.size();
    int my_len = len / 2;
    
    sort(nums.begin(), nums.end());
    //nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
	//erase 대신 resize 함수를 사용하는 경우*/ 
	nums.resize(unique(nums.begin(), nums.end()) - nums.begin()); 
    
    vector<int>::size_type own_len = nums.size();
    
    if(my_len < own_len) return my_len;
    else return own_len;
    
}

 

int main(){
	/*
	int num[] = {3, 1, 2, 3};
	vector<int> nums (num, num 3);
	*/
	vector<int> nums = {3, 1, 2, 3};
	
	cout << solution(nums) << endl;
}

/*Solution : 입력받은 vector nums를 sort 함수로 정렬하고, unique 함수를 이용해 이웃된 중복 원소를 
	맨 뒤로 보내는 작업을 진행한다. 이때 unique 함수는 vector의 끝까지 작업을 마치고 첫 번째 쓰레기값을
	반환해주기 때문에, 이 반환값을 이용해 erase 함수를 실행, 남은 값들과 nums/2를 비교하여 결과값을 출력한다.
*/ 
/*erase와 resize
	erase 함수는 unique 함수로 반환한 index부터 vector의 마지막 index까지의 데이터를 삭제한다.
	resize 함수는 vector의 시작점 부터 unique로 반환한 index까지의 범위로  해당 vector의 할당된 사이즈를 수정한다. 
		이로써 뒤에 붙어있던 쓰레기 값들은 지워지게 되는 것이다.*/ 

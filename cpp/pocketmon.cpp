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
    
	//erase ��� resize �Լ��� ����ϴ� ���*/ 
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

/*Solution : �Է¹��� vector nums�� sort �Լ��� �����ϰ�, unique �Լ��� �̿��� �̿��� �ߺ� ���Ҹ� 
	�� �ڷ� ������ �۾��� �����Ѵ�. �̶� unique �Լ��� vector�� ������ �۾��� ��ġ�� ù ��° �����Ⱚ��
	��ȯ���ֱ� ������, �� ��ȯ���� �̿��� erase �Լ��� ����, ���� ����� nums/2�� ���Ͽ� ������� ����Ѵ�.
*/ 
/*erase�� resize
	erase �Լ��� unique �Լ��� ��ȯ�� index���� vector�� ������ index������ �����͸� �����Ѵ�.
	resize �Լ��� vector�� ������ ���� unique�� ��ȯ�� index������ ������  �ش� vector�� �Ҵ�� ����� �����Ѵ�. 
		�̷ν� �ڿ� �پ��ִ� ������ ������ �������� �Ǵ� ���̴�.*/ 

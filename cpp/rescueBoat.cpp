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

/*Solution: people ���͸� ũ�� ������ �����ϰ� ���� ���� ���� ū ������ ���������� ���� limit���� ū�� ������ ���ؼ� �ʿ��� ���� ��Ʈ�� ������ ���*/
/*#1. ������ ���̽������� ���� ���� ���������  ������� Ʋ���� ���̽� �߻� ->  ���̽��� ���� ������ ����ų� ����ó������ ���� �κ��� �ִ� ������ �Ǵ�
	=> people[i] == people[len-j]&&people[i]+people[len-j]<limit �� ��� �ν��� �ȵǴ� ���� Ȯ��
	=> while���� ������ people[i] <= limit/2�� ��� �̹Ƿ� �ռ� ��� �ش� ������ while ���� �ν� ���� �ٱ��̹Ƿ� ���� �߻�
	=> ������ while���� ������ ���� �������� �ʾƵ� while�� ������ break�� ���� ���� ������ ������ �����Ƿ� bool���� true�� ����ϱ���� */
//Question Clear!

//#�ڵ��׽�Ʈ #C++ #2�ܰ� #��ɰ��� 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//�� ������ ���� ���� �ð��� ����ϴ� �Լ� 
int background(int progress, int speed){
	int time=0;
	if((100-progress)%speed==0){
		time=(100-progress)/speed;
	}
	else{
		time=(100-progress)/speed +1;
	}
	cout << time << " " << ends;
	return time;
}

vector<int> solution(vector<int> progresses, vector<int> speeds){
	vector<int> answer;
	vector<int>::size_type len = progresses.size();
	vector<int> times(len, 0);
	
	//times ���Ϳ� �� ������ ���� ���� �ð��� ���� 
	for(int i=0; i!=len; ++i){
		times[i]=background(progresses[i], speeds[i]);
	}
	
	int maximum=times[0];
	int amount=1;
	
	//�ݺ����� �̿��� ���ÿ� �۾��� �����ϴ� ���ҵ��� ������ Ȯ��, answer�� ���ҷ� �� ��	 
	for(int i=1; i!=len; ++i){
		if(times[i]>maximum){
			answer.push_back(amount);
			amount=1;
			maximum=times[i];
		}
		else{
			++amount;
		}
		if(i==len-1){
			answer.push_back(amount);
		} 
	}
	
	for(int i=0; i!=answer.size(); ++i){
		cout << answer[i] << " " << ends;
	}
	
	return answer;
	
}

int main(){
	int len=0;
	cin >> len;
	
	vector<int> progresses(len, 0);
	vector<int> speeds(len, 0);
	
	for(int i=0; i!=len; ++i){
		cin >> progresses[i];
	}
	for(int i=0; i!=len; ++i){
		cin >> speeds[i];
	}
	
	solution(progresses, speeds);
	
	return 0;
}

/*Solution: ������ ���ҵ��� ������ �����ϴµ� �ɸ��� �ð��� ����ϴ� �Լ� background�� �����, �̷��� ���� ��������� times ���Ϳ� �����ϰ� ������ ������
	maximum�� �̿��� ���������� ���Ͽ� maximum���� ū ���Ұ� ��Ÿ���ų� �ݺ����� ����� �� answer�� amount ���� �����ϴ� ��� ���*/ 
	
 

/*���� Ǯ ��:maximum�� �������� �ʰ� time�� �̿��� ���ҵ� ���� ���踦 �̿��� �ڵ� �ۼ�	 

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    vector<int>::size_type len = progresses.size();
    
    for(int i=0; i!=len; ++i){
        int each_time = 0;
        if((100-progresses[i])%speeds[i]==0) each_time =(100-progresses[i])/speeds[i]; 
        else each_time = (100-progresses[i])/speeds[i] + 1;
        time.push_back(each_time);
        //cout << each_time << endl;
    }
    
    int count = 0;
    int start = time[0];
    
    for(int j=0; j!=len; ++j){
        if(time[j] < time[j+1]){
            start = time[j+1];
            count +=1;
            answer.push_back(count);
            count = 0;
        }
        else{
            count +=1;
        }
        if(j==len-1){
        	answer.push_back(count);
		}
        //cout << count << endl;
    }
    
    return answer;
}

//for �� ���� ������ �� for�� ���ο��� for���� ������ �ʰ��ϴ� ������ ���Ե� ������ ��Ÿ���� ��� ����? �������� �ʳ�(segmentation error)
//(������ time[j+1]���� ��� j�� len-1�� �� time[len]�� �Ǳ� ������ time ������ ������ �ʰ���.)
//�� ������ �ذ��Ϸ��� for �� ������ �ڵ带 ���� ��� ���ľ� �ϴµ�, ���ܸ� ����� ������ �ٿ��� �� �ڵ�ó�� �ۼ��ϴ� ���� ���� ������ ����.(j=len-1)�� ������ ����(21.02.01) 
*/

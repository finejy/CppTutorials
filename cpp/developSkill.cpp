//#코딩테스트 #C++ #2단계 #기능개발 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//각 원소의 업무 종료 시간을 계산하는 함수 
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
	
	//times 벡터에 각 원소의 업무 종료 시간을 대입 
	for(int i=0; i!=len; ++i){
		times[i]=background(progresses[i], speeds[i]);
	}
	
	int maximum=times[0];
	int amount=1;
	
	//반복문을 이용해 동시에 작업을 종료하는 원소들의 범위를 확인, answer의 원소로 대 입	 
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

/*Solution: 각각의 원소들이 업무를 수행하는데 걸리는 시간을 계산하는 함수 background를 만들고, 이렇게 만든 결과값들을 times 벡터에 저장하고 저장한 값들을
	maximum을 이용해 순차적으로 비교하여 maximum보다 큰 원소가 나타나거나 반복문이 종료될 때 answer에 amount 값을 대입하는 방식 사용*/ 
	
 

/*예전 풀 이:maximum을 정의하지 않고 time의 이웃된 원소들 간의 관계를 이용해 코드 작성	 

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

//for 문 범위 설정할 때 for문 내부에서 for문의 범위를 초과하는 영역이 포함된 변수가 나타나면 어떻게 하지? 오류나지 않나(segmentation error)
//(본문의 time[j+1]같은 경우 j가 len-1일 때 time[len]이 되기 때문에 time 벡터의 범위를 초과함.)
//이 문제를 해결하려면 for 문 내부의 코드를 전부 뜯어 고쳐야 하는데, 예외를 만들어 수정할 바에는 위 코드처럼 작성하는 것이 좋을 것으로 보임.(j=len-1)의 문제도 포함(21.02.01) 
*/

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

/*num �´��� �ٽ� Ȯ��(n = 6�� �� 19�� 2��° �ﰢ���� ���ԵȰǵ� ���� �ﰢ�� ���տ��� ��)
	->	n % 3�� 0�϶��� �ƴҶ� ��찡 �޶����Ƿ� ���ǹ����� ���̽� �и�*/
/*�ﰢ�� ����° �� ��� ���� Ȯ��
	->	����° ���� �����ϴ� ��ġ���� ��ġ�� �̵��� �� ���� ������ �� ������ �̿��� ���� ����*/ 
//���� �ﰢ�� ������ ���� �Է� ��ġ�� ������ �߻� (n = 5 �϶� 12�� ��ġ�� 0�� �ε����� ����) 
// n=6�� ��� core dumped ���� �߻� 

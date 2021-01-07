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
            	answer[second_start + i] = start��_num + i + l;
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

/* P1. num �´��� �ٽ� Ȯ��(n = 6�� �� 19�� 2��° �ﰢ���� ���ԵȰǵ� ���� �ﰢ�� ���տ��� ��)
	->	n % 3�� 0�϶��� �ƴҶ� ��찡 �޶����Ƿ� ���ǹ����� ���̽� �и�*/
/* P2. �ﰢ�� ����° �� ��� ���� Ȯ��
	->	����° ���� �����ϴ� ��ġ���� ��ġ�� �̵��� �� ���� ������ �� ������ �̿��� ���� ����*/ 
// P3. ���� �ﰢ�� ������ ���� �Է� ��ġ�� ������ �߻� (n = 5 �϶� 12�� ��ġ�� 0�� �ε����� ����) -> ������ �� ��꿡�� �ٽ� ���� ������ �� ���� ���� �߻� 
// P4. n=6�� ��� core dumped ���� �߻� -> P3�� ���� ������ �� ���� ��������
// P5. n % 3 == 1�� ��� ���� �߾��� �ﰢ��(���Ұ� 1��)�� �Էµ��� �ʴ� ���� -> l == 0�� �ǹǷ� �� ��° for���� ������� �ʴ� ���� �߻� -> ���ǹ����� ��Ȳ �и� 
// 21.01.06 P1, P2 �ذ�; P3, P4 �߻�
// 21.01.07 P3, P4 �ذ�; P5 �߻�; P5 �ذ�, ���� �ذ�
/*������ ���� ���, index�� �̵��ϴ� ��Ģ ã�Ƽ� Ǫ�� ����� ����*/ 


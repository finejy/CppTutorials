#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*
int background(int m, int n, vector<int>& result, vector<vector<int>>& picture){
	vector<vector<int>> background(m, vector<int> (n, 0));
	
	int x =0, y =0, num = 0, maximum = 0;
	
	vector<vector<int>> test = picture; 
	
	//�ش� �������� ���� ���� ��ġ Ž �� 
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			if(picture[i][j]!=0){
				num = picture[i][j];
				background[i][j]=1;
				test[i][j] = 0;
				++maximum;
				//cout << i << " " << j << endl;
				break;
			}
		}
		if(maximum==1) break;
	}
	
	//������ ���� �˻� ��� ��� ���Ұ� 0�� �� 0 ��� 
	if(maximum==0) return 0;
	
	
	//�� ������ �����¿� ���Ұ��� ��, ���ǿ� ������ maximum, picture, background ��ü�� ������ ���� �� �� 
	for(int i=0; i!=m; ++i){
		
		//cout << maximum << endl;
		for(int j=0; j!=n; ++j){
			if(picture[i][j] == num && background[i][j]!=1){
				if(0<i && i<m-1 && 0<j && j<n-1){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) || (picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) ||
						(picture[i][j]==picture[i][j-1]&&background[i][j-1]==1) || (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==0 && j==0){
					if((picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) || (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==0 && j==n-1){
					if((picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) || (picture[i][j]==picture[i][j-1]&&background[i][j-1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==m-1 && j==0){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) || (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==m-1 && j==n-1){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) ||(picture[i][j]==picture[i][j-1]&&background[i][j-1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==0){
					if((picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) || (picture[i][j]==picture[i][j-1]&&background[i][j-1]==1) 
						|| (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(i==m-1){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) || (picture[i][j]==picture[i][j-1]&&background[i][j-1]==1) 
						|| (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(j==0){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) || (picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) 
						|| (picture[i][j]==picture[i][j+1]&&background[i][j+1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
				else if(j==n-1){
					if((picture[i][j]==picture[i-1][j]&&background[i-1][j]==1) || (picture[i][j]==picture[i+1][j]&&background[i+1][j]==1) ||
						(picture[i][j]==picture[i][j-1]&&background[i][j-1]==1)){
						background[i][j] = 1;
						test[i][j] = 0;
						++maximum;
					}
				}
			}
		}
	}
	picture = test;
	
	for(int i=0; i!=m; ++i){
    		for(int j=0; j!=n; ++j){
    			cout << background[i][j] << " " << ends;
			}
			cout << endl;
		}
	
	++result[0];
	return maximum;
}*/


//New way
int background(int m, int n, vector<int>& answer, vector<vector<int>>& picture){
	vector<vector<int>> background(m, vector<int>(n, 0));
	int maximum = 0, num = 0;
	vector<vector<int>> test(m, vector<int>(n,0));
	test = picture;
	
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			if(picture[i][j]!=0){
				num = picture[i][j];
				background[i][j]=1;
				test[i][j] = 0;
				++maximum;
				cout << i << " " << j << endl;
				break;
			}
		}
		if(maximum==1) break;
	}
	
	if(maximum==0) return 0;
	int start_line = 0;
	
	for(int i=0; i!=m; ++i){
		for(int j=0; j!=n; ++j){
			if(start_line == 1){
				j-=1;
				start_line=0;
			}
	
			else if(start_line == 2){
				j-=2;
				start_line=0;
			}
			
			if(background[i][j]==1){
				if(i>0){
					if(background[i-1][j]!=1 && picture[i-1][j]==num){
						++background[i-1][j];
						++maximum;
						test[i-1][j]=0;
						--i;
						if(j==0){
							start_line=1;
						}
						else{
							--j;
						}
						continue;
					}
				}
				if(i<m-1){
					if(background[i+1][j]!=1 && picture[i+1][j]==num){
						++background[i+1][j];
						++maximum;
						test[i+1][j]=0;
					}
				}
				if(j<n-1){
					if(background[i][j+1]!=1){
						if(picture[i][j+1]==num){
							++background[i][j+1];
							++maximum;
							test[i][j+1]=0;
						}
					}
				}
				if(j>0){
					if(background[i][j-1]!=1){
						if(picture[i][j-1]==num){
							++background[i][j-1];
							++maximum;
							test[i][j-1]=0;
							if(j==1){
								start_line=2;
							}
							else{
								j-=2;
							}
							
						}
					}
				}
			}
		}
	}
	picture = test;
	++answer[0];
	return maximum; 
}



// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<int> answer(2, 0);
    
    int maximum = 0;
	int mount = 1; 
    
    while(mount !=0){
    	mount = background(m, n, answer, picture);
    	if(maximum < mount) maximum = mount;
    	/*cout << "testcode" << endl;
    	for(int i=0; i!=m; ++i){
    		for(int j=0; j!=n; ++j){
    			cout << picture[i][j] << " " << ends;
			}
			cout << endl;
		}
		cout << endl;*/
	}
	answer[1] = maximum;
    
    //cout << answer[0] << " " << answer[1] << endl;
    
    return answer;
}

int main(){
	int m;
	int n;
	cin >> m;
	cin >> n;
	cout << endl;
	
	
	vector<vector<int>> picture(m, vector<int>(n, 0));
	
	for(int i=0; i!=m; ++i){
		int x;
		for(int j=0; j!=n; ++j){
			cin >> x;
			picture[i][j] = x;
		}
		cout << endl;
	}
	solution(m, n, picture);
	
	return 0;
}

/*Solution : ������ vector picture�� �����ϴ� vector background�� ���� �ش� ���������� ���� �����ϴ� ��ġ�� background�� ǥ��,
	�� �� picture�� ��� ��ġ���� ��, ��, ��, ���� background�� ǥ�ø� Ȯ���ϰ� ǥ�ÿ� picture������ �ش� ������ ���� ��� ������ �����ϴ� 
	������ ������ ���� �Լ� background�� �����, while���� �̿��� picture�� ��� ���Ұ� 0�� �ɶ����� �ش� �۾��� �ݺ�*/

/*P1. 1�� �õ� �� background �Լ��� ù ��° for ������ background�� 1�� �Ǵ� ��ġ�� �ϳ� �̻� ������ ���� Ȯ��
	-> ���� for���� ����� �� break �Լ��� �� ���� ������ָ� ������ ������ ���������� ������ �߻��� �� ����.*/
/*P2. P1�� ���� �ذ��� ���� �ٱ��� for���� Ż���ϱ� ���� break ���ǹ��� �������� �� ��° for���� ����� ������� �ʴ� ������ Ȯ�� -> �Է� ����, �ذ� �Ϸ�*/
/*P3. for ���� ���� ���Ҹ� ������� Ȯ���ϸ� �� �߻��ϴ� ���� Ȯ��. �ֺ��� �ٲ� background�� ������ �ش� ��ġ�� background�� �����ϴ� ����� ���������
	�ٸ� ����� ã�ƺ��� �� ��*/ 

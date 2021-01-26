#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*
int background(int m, int n, vector<int>& result, vector<vector<int>>& picture){
	vector<vector<int>> background(m, vector<int> (n, 0));
	
	int x =0, y =0, num = 0, maximum = 0;
	
	vector<vector<int>> test = picture; 
	
	//해당 루프에서 시작 지점 위치 탐 색 
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
	
	//이차원 벡터 검색 결과 모든 원소가 0일 때 0 출력 
	if(maximum==0) return 0;
	
	
	//각 원소의 상하좌우 원소값을 비교, 조건에 맞으면 maximum, picture, background 객체에 적합한 수정 요 구 
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



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
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

/*Solution : 이차원 vector picture에 대응하는 vector background를 만들어서 해당 루프에서의 색이 시작하는 위치를 background에 표시,
	그 후 picture의 모든 위치에서 상, 하, 좌, 우의 background의 표시를 확인하고 표시와 picture에서의 해당 원소의 값이 모두 조건을 만족하는 
	원소의 갯수를 세는 함수 background를 만들고, while문을 이용해 picture의 모든 원소가 0이 될때까지 해당 작업을 반복*/

/*P1. 1차 시도 시 background 함수의 첫 번째 for 문에서 background가 1이 되는 위치가 하나 이상 나오는 것을 확인
	-> 이중 for문을 사용할 시 break 함수를 한 번만 사용해주면 안쪽의 루프만 빠져나오는 오류가 발생할 수 있음.*/
/*P2. P1의 문제 해결을 위해 바깥쪽 for문을 탈출하기 위한 break 조건문을 실행하자 두 번째 for문이 제대로 종료되지 않는 문제를 확인 -> 입력 오류, 해결 완료*/
/*P3. for 문에 따라 원소를 순서대로 확인하면 서 발생하는 문제 확인. 주변에 바뀐 background가 있으면 해당 위치의 background를 변경하는 방식을 사용했지만
	다른 방법을 찾아봐야 할 듯*/ 

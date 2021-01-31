#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string>::size_type len = s.size();
    int minimum = len;
    
    for(int i=1; i!=len/2+1; ++i){
    	cout << "i: " << i << " " << endl;
    	int len_2 = len%i==0 ? len/i : len/i+1 ;
    	vector<string> element(len_2, "");
    	vector<int> element_num(1, 1);
    	int term=0;
    	int index_1=0;
    	int index_2=0;
    	
    	while(index_2 < len){
    		if(term == i){
    			term=0;
    			++index_1;
			}
			element[index_1]+=s.at(index_2);
			++index_2;
			++term;
		}
		
		int index_num=0;
    	vector<string> element_del;
    	element_del.push_back(element[0]);
    	cout << "element: " << element[0] << " " << ends;
		for(int j=1; j!=len_2; ++j){
			cout << element[j] << " " << ends;
			if(element[j]==element[j-1]){
				++element_num[index_num];
			}
			else{
				element_num.push_back(1);
				element_del.push_back(element[j]);
				++index_num;
				
			}
		}
		cout << endl;
		string new_string="";
		vector<string>::size_type len_3 = element_del.size();
		
		if(element == element_del){
			new_string = s;
		}
		else{	
			for(int k=0; k!=len_3; ++k){
				if(element_num[k]!=1) new_string+=to_string(element_num[k]);
				new_string+=element_del[k];
			}
		}
		cout << "new_string: " << new_string << endl;
		string::size_type last_len = new_string.size();
		if(last_len < minimum) minimum = last_len;
		cout <<"minimum: " <<minimum << " " << endl;
	}
	
	answer = minimum;
	
    return answer;
}

int main(){
	string s="";
	cin >>s;
	
	solution(s);
	return 0;
}

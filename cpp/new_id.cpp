#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

string solution(string new_id) {
    string answer = "";
    string::size_type len = new_id.size();
    
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    int index=0;
    string menu="abcdefghijklmnopqrstuvwxyz-_.";
    
    while(index < len-1){
    	if(new_id.at(index)=='.'&&index==0){
			new_id.erase(0);
			--len;
		}
		else if(find(menu.begin(), menu.end(), new_id.at(index))==menu.end()){
    		new_id.erase(index);
    		--len;
		}
		else if(new_id.at(index)=='.'&&new_id.at(index+1)=='.'&&index<len-1){
			new_id.erase(index);
			--len;
		}
		else if(new_id.at(index)=='.'&&index==len-1){
			new_id.erase(index);
			break;
		}
		else{
			++index;
		}
		cout << new_id << endl;
	}
	
	if(len==0){
		new_id+="a";
		++len;
	}
	if(len > 14){
		new_id.erase(new_id.begin()+15, new_id.end());
	}
	if(len <3){
		char end_word=new_id.at(len);
		while(len==3){
			new_id+=end_word;
			++len;
		}
	}
	
	answer=new_id;
	cout << answer<< endl;
	
	
	return answer;
}

int main(){
	string new_id="";
	cin >> new_id;
	
	solution(new_id);
	
	return 0;
}

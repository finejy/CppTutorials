#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iterator>

using namespace std;

bool space(char c){
	return isspace(c);
} 

bool not_space(char c){
	return !isspace(c);
}


vector<string> split(const string& str){
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	while(i!=str.end()){
		i = find_if(i, str.end(), not_space);
		
		iter j = find_if(i, str.end(), space);
		
		if(i!=str.end()){
			ret.push_back(string(i, j));
		}
		i=j;
	}
	return ret;
}

string::size_type width(const vector<string>& v){
	string::size_type maxlen = 0;
	
	for(vector<string>::size_type i = 0; i!=v.size()); ++i){
		maxlen = max(maxlen, v[i].size());
	}
	
	return maxlen;
}


vector<string> frame(const vector<string>& v){
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');
	
	ret.push_back(border);
	
	for(vector<string>::size_type i = 0; i!=v.size(); ++i){
		ret.push_back("*" + v[i] + string(maxlen - v[i].size(), ' ') + "*");
	}
	
	ret.push_back(border);
	return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom){
	vector<string> ret = top;
	/*기존코드. copy 알고리즘으로 수정 가능 
	ret.insert(ret.end(), bottom.begin(), bottom.end()); 
	*/
	//back_inserter 함수 : ret 컨테이너에서 bottom 컨테이너의 요소들을 추가할 위치를 반환(마지막 자리) 
	copy(bottom.begin(), bottom.end(), back_inserter(ret));
	 
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right){
	vector<string> ret;
	
	string::size_type width1 = width(left) + 1;
	
	vector<string>::size_type i=0; j=0;
	
	while(i!=left.size()||j!=right.size()){
		string s;
		
		if(i!=left.size()){
			s = left[i++];
		}
		
		s+=string(width1 - s.size(), ' ');
		
		if(j!=right.size()){
			s+=right[j++];
		}
		
		ret.push_back(s);
	}
	return ret;
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
	static const string sep = "://";
	typedef string::const_iterator iter;
	
	iter i = b;
	while((i=search(i, e, sep.begin()), sep.end()) != e){
		if(i!=b && i + sep.size())!=e){
			iter beg = i;
			while (beg !=sb && isalpha(beg[-1])){
				--beg;
			}
			if(beg != i && !not_url_char(i[sep.size()])){
				return beg;
			}
		}
		i +=sep.size();
	}
	return e;
}



bool not_url_char(char c){
	static const string url_ch = "~;/?:@=&$-_.+*'(),";
	
	return !=(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) !=url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
	return find_if(b, e, not_url_char);
}


vector<string> find_urls(const string& s){
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	
	while(b != e){
		b = url_beg(b, e);
		if(b!=e){
			iter after = url_end(b, e);
			ret.push_back(string(b,after));
			b = after;
		}
	}
	return ret;
}

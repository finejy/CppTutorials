#include "calcGrade_median.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

double median(vector<double> vec){
	vector<double>::size_type len = vec.size();
	
	vector<double>::size_type halfLen = len/2;
	
	if(len == 0) throw domain_error("median of an empty vector");
	
	sort(vec.begin(), vec.end());
	
	return len%2==0 ? (vec[halfLen] + vec[halfLen-1])/2 : vec[halfLen];
}

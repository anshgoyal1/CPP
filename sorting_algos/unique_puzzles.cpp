#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector <int> v = {1,5,23,90,15,35};
	
	make_heap(v.begin(),v.end());
	v.push_back(80);
	
	push_heap(v.begin(), v.end());
	pop_heap(v.begin(), v.end());
	v.pop_back();
	
	cout<<v.front();
	
	return 0;
}
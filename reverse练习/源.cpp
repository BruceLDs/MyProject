#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void test(){
	string s = "abcdef";
	reverse(s.begin(), s.end());
	cout << s << endl;
	vector<int> arr = { 1, 2, 3, 4, 5 };
	reverse(arr.begin(), arr.end());
	for (auto& e : arr)
		cout << e << " ,  ";
	cout << endl;
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	reverse(l.begin(), l.end());
	for (auto& e : l)
		cout << e << " -> ";
	cout << endl;
}
int main(){
	test();
	return 0;
}
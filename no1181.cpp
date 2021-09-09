#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 1181(단어 정렬)

bool comp_length(const string& a, const string& b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length())
		return a < b;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<string> v;
	set<string> sv;

	for (int i = 0; i < N; i++) 
	{
		string x; cin >> x;
		sv.insert(x);
	}

	set<string>::iterator iter;
	for (iter = sv.begin(); iter != sv.end(); iter++)
	{
		v.push_back(*iter);
	}
	// set으로 중복 제거


	sort(v.begin(), v.end(), comp_length);
	vector<string>::iterator viter;

	for (viter = v.begin(); viter != v.end(); viter++)
	{
		cout << *viter << '\n';
	}

	return 0;
}
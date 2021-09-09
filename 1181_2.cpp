#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 번호: 1181(단어 정렬) - 2
// set 없이 풀이함

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

	for (int i = 0; i < N; i++)
	{
		string x; cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), comp_length);
	v.erase(unique(v.begin(), v.end()), v.end());
	// 벡터.erase(unique(시작, 끝), 끝)
	// 벡터 뒤에 쌓인 중복 값들을 제거하는 형식으로 중복을 제거한다.

	vector<string>::iterator viter;
	for (viter = v.begin(); viter != v.end(); viter++)
	{
		cout << *viter << '\n';
	}

	return 0;
}

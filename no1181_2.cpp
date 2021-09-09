#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 1181(�ܾ� ����) - 2
// set ���� Ǯ����

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
	// ����.erase(unique(����, ��), ��)
	// ���� �ڿ� ���� �ߺ� ������ �����ϴ� �������� �ߺ��� �����Ѵ�.

	vector<string>::iterator viter;
	for (viter = v.begin(); viter != v.end(); viter++)
	{
		cout << *viter << '\n';
	}

	return 0;
}
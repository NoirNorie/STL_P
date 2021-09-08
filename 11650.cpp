#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 11650(��ǥ �����ϱ�)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> v;

	int N; cin >> N;
	
	for (int i = 0; i <N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());
	// pair ��ü�� ���� ���͵� ��������


	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}


// Timeout(limit = 1s)

//for (int i = 0; i < v.size(); i++)
//{
//	for (int j = i + 1; j < v.size(); j++)
//	{
//		if (v[i].first > v[j].first) // x���� ū��?
//		{
//			pair<int, int> tmp = make_pair(v[i].first, v[i].second);
//			v[i] = v[j];
//			v[j] = tmp;
//		}
//		else if(v[i].first == v[j].first && v[i].second > v[j].second) // x���� ������ y ���� �� ū��?
//		{
//			pair<int, int> tmp = make_pair(v[i].first, v[i].second);
//			v[i] = v[j];
//			v[j] = tmp;
//		}
//	}
//}
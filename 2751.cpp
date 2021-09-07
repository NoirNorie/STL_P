#include <iostream>
#include <vector>
using namespace std;

// 문제 번호: 2751(수 정렬하기 2)

int main()
{
	vector<int> v;
	int N; cin >> N;

	for(int i = 0 ; i < N; i ++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < v.size() -1; i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				int tmp = v[j];
				v[j] = v[i];
				v[i] = tmp;
			}
		}
	}

	for (int i = 0; i < v.size() ;i++)
	{
		cout << v[i] << endl;
	}
	
	return 0;
}

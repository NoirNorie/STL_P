#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제 번호: 1316(그룹 단어 체커)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	vector<string> vs(T);
	for (int i = 0; i < T; i++)
	{
		cin >> vs[i];
	}

	int cnt = 0;
	vector<string>::iterator vsiter = vs.begin();
	while (vsiter != vs.end())
	{
		vector<bool> vc(26, true);
		int i = 0;
		for (i; i < vsiter->length() - 1; i++)
		{
			if (vc[vsiter->at(i) - 97] == false) break; // 더 이상 검사할 필요가 없어진다.
			
			if (vsiter->at(i) != vsiter->at(i + 1)) // 같은 알파벳이 존재할 경우 조건을 만족하지 못한다
			{
				vc[vsiter->at(i) - 97] = false; // 조건 벡터에 표기한다.
			}
		}

		if (vc[vsiter->at(i) - 97] == false) // 마지막 원소를 검사하지 못하므로 체크해준다.
		{
			vsiter++;
			continue;
		}
		if (i >= vsiter->length() - 1) // 조건을 완수한 경우 그룹 단어가 되므로 카운트
		{
			cnt++;
		}
		vsiter++;	
	}

	cout << cnt << '\n';

	return 0;
}
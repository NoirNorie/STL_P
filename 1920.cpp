#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ��ȣ: 1920(�� ã��)

vector<int> target_v;
// �������� ������ ������ �ð� �ʰ��� �ذ��ϱ� ���ؼ� ����� ������
// ���͸� �Լ� ȣ�⸶�� �̵���Ű�� �͵� �ð��� ��Ƹ��� ����

void Binary_srch(int num)
{
	int left = 0, right = target_v.size() - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (target_v[mid] == num)
		{
			cout << 1 << '\n';
			return;
		}
		else if (target_v[mid] > num) right = mid - 1;
		else left = mid + 1;
	}

	// ã�� ���Ͽ��ٸ�
	cout << 0 <<'\n';
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		target_v.push_back(num);
	}

	sort(target_v.begin(), target_v.end());

	int M; cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		Binary_srch(num);
	}

	return 0;
}
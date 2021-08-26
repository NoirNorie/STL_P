#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int RangeCalc(int x1, int y1, int r1, int x2, int y2, int r2);

int main()
{
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, r1 = 0, r2 = 0;
	// �� ��ǥ �ʱ�ȭ
	// 1���� ������, 2���� ���ȯ
	// r�� �������� �Ÿ�
	vector<int> Result_V; // ����� ���� ���� ����
	
	// �׽�Ʈ���̽� �Է�
	int T; cin >> T;

	for (int i = 0; i < T; i++) // �׽�Ʈ ���̽� �ݺ�
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		// �ش� �׽�Ʈ ���̽��� ��ǥ, �Ÿ� �� �Է�

		Result_V.push_back(RangeCalc(x1, y1, r1, x2, y2, r2));
		//cout << RangeCalc(x1, y1, r1, x2, y2, r2) << endl;
	}

	vector<int>::iterator iter; // ��� ���
	for (iter = Result_V.begin(); iter != Result_V.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}

int RangeCalc(int x1, int y1, int r1, int x2, int y2, int r2)
{
	double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (x1 == x2 && y1 == y2 && r1 == r2) // �� ��ü�� ��ġ
	{
		return -1;
	}
	else if(dist == r1 + r2) // �����ϴ� ���
	{
		return 1;
	}
	else if (dist == abs(r1-r2)) // �����ϴ� ���
	{
		return 1;
	}
	else if (dist > r1 + r2) // �� ���� ���� ������ �ְ� ���� X
	{
		return 0;
	}
	else if (dist <= abs(r1-r2) ) // ���� �ٸ� �� ���ο� ����, ���� X
	{
		return 0;
	}
	else // �� ���� ���� ��� �� ������ ������.
	{
		return 2;
	}
}
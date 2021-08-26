#include <iostream>
#include <vector>
using namespace std;

vector<int> memo; // Memoization Vector

int cnt0 = 0; int cnt1 = 0;

int Memoization_fibo(int n);

int main()
{
    vector<pair<int, int>> Result_V; // ����� ���� ����

    int Trial, N;
    cin >> Trial; // Ƚ���� �Է¹���

    for (int i = 0; i < Trial; i++)
    {
        cin >> N; // �׽�Ʈ ���̽� �Է�


        memo = { 0, 1 }; // �ʱ�ȭ

        Memoization_fibo(N);
        Result_V.push_back(make_pair(cnt0, cnt1)); // ��� ����

        memo.clear();
        cnt0 = 0; cnt1 = 0; // �������� �ʱ�ȭ
    }

    vector<pair<int, int>>::iterator iter; // �׽�Ʈ ���̽� ���
    for (iter = Result_V.begin(); iter != Result_V.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

int Memoization_fibo(int n)
{
    int result;

    if (n == 0)
    {
        cnt0++;
        result = n;
    }
    else if (n == 1)
    {
        cnt1++;
        result = n;
    }
    else // 2 �̻��� ���
    {
        int index = n;
        if (index >= memo.size()) // ������ ũ�⺸�� �ݺ� Ƚ���� ū ���
        {
            memo.push_back(Memoization_fibo(index - 1) + Memoization_fibo(index - 2)); // ���Ӱ� ���� ����Ѵ�.
            result = memo[index];
        }     
        else // �ƴ� ��� ���� �Ѱ��ش�.
        {
            result = memo[index];
        }
    }
    return result;
}


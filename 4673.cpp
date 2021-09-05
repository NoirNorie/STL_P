#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 문제 번호: 4673(셀프 넘버)

void d()
{
	int res;
	vector<int> arr;
	arr.assign(10001, 0);
    for (int i = 1; i <= 10000; i++) {
        if (i < 10) {
            res = i + i;
            arr[res] = 1;
        }
        else if (i < 100) {
            res = i + (i / 10) + (i % 10);
            arr[res] = 1;
        }
        else if (i < 1000) {
            res = i + (i / 100) + ((i % 100) / 10) + ((i % 100) % 10);
            arr[res] = 1;
        }
        else if (i < 10000) {
            res = i + (i / 1000) + ((i % 1000) / 100) + (((i % 1000) % 100) / 10) + (((i % 1000) % 100) % 10);
            
        }
        if (res <= 10000)    arr[res] = 1;
    }

	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] != 1)
		{
			cout << i << '\n';
		}
	}
}


int main()
{
	d();

	return 0;
}

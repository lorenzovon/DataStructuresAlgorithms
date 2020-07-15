#include <iostream>
using namespace std;
int binSearch(uint64_t data[], int left, int right, int key);
int main()
{
	uint64_t n, m;
	cin >> n;
	uint64_t data[n];
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
	}
	cin >> m;
	uint64_t search[m];
	for (int i = 0; i < m; i++)
	{
		cin >> search[i];
	}
	for (int i = 0; i < m; i++)
	{
		cout << binSearch(data, 0, n - 1, search[i]) << " ";
	}
	cout << endl;

	return 0;
}
int binSearch(uint64_t data[], int left, int right, int key)
{
	while (left <= right)
	{
		int mid = left + ((right - left) / 2);
		if (key == data[mid])
		{
			return mid;
		}
		else if (key > data[mid])
		{
			return binSearch(data, mid + 1, right, key);
		}
		else
		{
			return binSearch(data, left, mid - 1, key);
		}
	}
	return -1;
}
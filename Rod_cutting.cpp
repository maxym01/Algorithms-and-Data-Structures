
#include <iostream>
using namespace std;

void optimize(unsigned int item[], unsigned int K[], unsigned int n, unsigned int m)
{
	K[0] = 0;
	K[1] = item[1];
	cout << K[1] << '\n';
	for (int i = 2; i < m + 1; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			if (j == 1)
			{
				K[i] = item[j] + K[i - j];
			}
			if (K[i] < item[j] + K[i - j])
			{
				K[i] = item[j] + K[i - j];
			}
			else
				continue;

		}
		cout << K[i] << '\n';
	}
}

int main()
{
	unsigned int n, m;

	cin >> n;
	unsigned int* a = new unsigned int[n + 1];
	a[0] = 0;
	for (int i = 1; i < n + 1; i++)
		cin >> a[i];

	cin >> m;
	unsigned int* b = new unsigned int[m + 1];
	b[0] = 0;
	for (int i = 1; i < m + 1; i++)
		cin >> b[i];

	optimize(a, b, n, m);
	delete[] a;
	delete[] b;

	return 0;
}

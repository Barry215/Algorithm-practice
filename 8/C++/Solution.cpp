#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
	int nQueens(int n)
	{
		int count = 0;
		int *a = new int[n + 1];
		Queens1(a, 1, n, count);
		return count;
	}
	void Queens1(int a[], int i, int n, int &count)
	{
		if (i > n)
		{
			count++;
			return;
		}
		for (int j = 1; j <= n; j++)
		{
			a[i] = j;
			if (Place(a, i))
				Queens1(a, i + 1, n, count);
		}
	}

	bool Place(int *a, int i)
	{
		for (int j = 1; j < i; j++)
			if ((a[j] == a[i]) || (a[j] - a[i] == (j - i)) || (a[j] - a[i] == i - j))
				return 0;
		return 1;
	}
};

int main()
{

	Solution solution;
	cout << solution.nQueens(8) << endl;

	return 0;
}
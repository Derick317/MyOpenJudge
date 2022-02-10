//放苹果
#include<iostream>
using namespace std;

int f(int m, int n);

int main()
{
	int num = 0;
	int m, n;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	return 0;
}

int f(int m, int n)
{
	if (n == 1 || m == 0)  return 1;  //Bug: 注意m=0的边界条件
	else if (m <= n - 1) return f(m, m);
	else return (f(m, n - 1) + f(m - n, n));
}

#include<iostream>
#include<math.h>
using namespace std;
#define Q 1.618033988749895

int main()
{
	int x = 0, y = 0;
	int b = 0;

	while (cin >> x >> y)
	{
		if (x > y)
		{
			x = x ^ y;
			y = y ^ x;
			x = x ^ y;
		}
		b = floor((y - x) * Q) != x;
		cout << b << endl;

	}
	return 0;
}

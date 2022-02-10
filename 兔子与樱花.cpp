#include <iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[30][500];
	int m[35][35] ;
	int temp,j,k,temp2;
	int dnum;  //点的个数
	int dist;
	char b[500], c[500];
	bool MIN[35] = { 0 };
	int pre[35];
	int mind[35];
	int root[35];
	for (j = 0; j < 35; j++)
		for (k = 0; k < 35; k++)
			if (j == k)
				m[k][j] = 0;
			else
				m[k][j] = m[j][k] = -1;
	cin >> dnum;
	for (int i = 1; i <= dnum; i++)
		cin >> a[i];

	cin >> temp;
	for (int i = 1; i <= temp; i++)
	{
		cin >> b>>c;
		for (j = 1; strcmp(a[j] , b); j++);
		for (k = 1; strcmp(a[k], c); k++);
		cin >> m[k][j];
		m[j][k] = m[k][j];
	}
	cin >> temp;
	for (int i = 1; i <= temp; i++)
	{
		for (int t = 1; t <= dnum; t++)  //Bug:有多组数据的，做完一组要把所用数组等归位
			MIN[t] = 0;
		cin >> b >> c;
		for (j = 1; strcmp(a[j], b); j++);
		for (k = 1; strcmp(a[k], c); k++);
		MIN[j] = 1;//初始化MIN
		for (int r = 1; r <= dnum; r++)
		{
			mind[r] = m[j][r];
			pre[r] = j;
		}
		for (int r = 1; r < dnum; r++)
		{
			//找到新的最小点
			int add = 1;
			for (add = 1; MIN[add]; add++);
			for (int t=add; t <= dnum; t++)
			{
				if (MIN[t])continue;
				if (mind[t] != -1 && mind[add] != -1 && mind[t] < mind[add])  //如果t的距离比add小
					add = t;
				else if (mind[t] != -1 && mind[add] == -1)
					add = t;
			}
			MIN[add] = 1;
			for (int t = 1; t <= dnum; t++)
			{
				if (MIN[t]) continue;
				if (mind[t] != -1 && mind[add] != -1 && m[add][t]!=-1 && mind[t] > mind[add] + m[add][t])//Bug: 保证m[add][t]也不是无穷大
				{
					mind[t] = mind[add] + m[add][t];
					pre[t] = add;
				}
				else if (mind[t] == -1 && mind[add] != -1&& m[add][t]!=-1)//Bug: 保证m[add][t]也不是无穷大,且==不要写成=
				{
					mind[t] = mind[add] + m[add][t];
					pre[t] = add;
				}
			}

		}
		for (temp2= 1; temp2==1||pre[root[temp2-1]] != j; temp2++)
		{
			if (temp2 == 1)
				root[temp2] = k;
			else {
				root[temp2] = pre[root[temp2-1]];
			}
		}
		root[temp2] = j;
		cout << a[j];
		if (j != k)
		{
			for (int r = temp2 - 1; r >= 1; r--)
				cout << "->(" << m[root[r + 1]][root[r]] << ")->" << a[root[r]];
			cout << endl;
		}
		else
			cout  << endl;
	}
	
	return 0;
}

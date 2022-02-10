#include<iostream>
using namespace std;

int MergeSort(int* a, int* temp, int* count, int n);
int Merge(int a[], int temp[], int count[],int n, int middle);

int main()
{
	int a[20005] = { 0 }, temp[20005], count[20005];
	int N = 0,revnum;

	cin >> N;
	while (N)
	{
		for (int i = 0; i < N; i++)
			cin >> a[i];
		revnum = MergeSort(a, temp, count, N);
		cout << revnum << endl;
		cin >> N;
	}
}

int MergeSort(int* a, int* temp, int* count, int n)
{
	if (n <= 1) return 0;  //Bug: 递归出口
	int revleft = 0, revright = 0, revbetween = 0;
	int middle = n / 2;  //middle 实际上指左边子列元素个数
	revleft = MergeSort(a, temp, count, middle);
	revright = MergeSort(a + middle, temp + middle, count + middle, n - middle);
	revbetween = Merge(a, temp, count,n, middle);

	return (revleft + revright + revbetween);
}
int Merge(int a[], int temp[], int count[],int n, int middle)
{
	int left = 0, right = middle,revnum=0,rank=1,drevnum=0;
	if (n <= 1) return 0;
	
	for (int i = 0; i < n; i++)  //把原数组转移到 temp 中.
		temp[i] = a[i];
	
	for (int i = 0; i < n; i++)
	{
		if (left < middle && right < n)
		{
			if (temp[left] <= temp[right])
			{
				if (i==0) count[left] = 1;
				else
				{
					if (temp[left] == a[i - 1])
						count[left] = rank;
					else
						count[left] = i + 1;
				}
				rank = count[left];
				a[i] = temp[left++];
			}
			else
			{
				if (i == 0) count[right] = 1;
				else
				{
					if (temp[right] == a[i - 1])
						count[right] = rank;
					else
						count[right] = i + 1;
				}
				rank = count[right];
				a[i] = temp[right++];
			}

		}
		else if (right==n)  //Bug: 注意互斥的条件一定要写else，不要直接写if
		{
			if (i == 0) count[left] = 1;
			else
			{
				if (temp[left] == a[i - 1])  //Bug: 写==不是=
					count[left] = rank;
				else
					count[left] = i + 1;
			}
			rank = count[left];
			a[i] = temp[left++];
		}
		else if (left==middle)
		{
			if (i == 0) count[right] = 1;
			else
			{
				if (temp[right] == a[i - 1])
					count[right] = rank;  //Bug: 注意是改count而不是temp
				else
					count[right] = i + 1;
			}
			rank = count[right];
			a[i] = temp[right++];
		}
	}
	for (int i = 0; i < middle; i++)
	{
		if (i == 0 || temp[i] > temp[i - 1])
			drevnum = count[i] - 1 - i;
		revnum += drevnum;//Bug: 注意这条语句要写在for循环块里面
	}
		
//		revnum += count[i] - 1-i;  //Bug: 由于前面可能有重复，所以不能简单地这样算
	return revnum;
}

#include <iostream>       // std::cout
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int* a = new int[n + 5];
	int* b = new int[n - k + 5];  //用于存放最大值或者最小值
	int head, tail;  //head是挑选最值的一端，tail是进来的一端
	int* pre = new int[n+5];  //记录靠近tail的一个
	int* next = new int[n+5];//记录靠近head的一个
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	//下面先处理最小值
	b[0] = a[1];
	tail = head = 1;
	pre[head] = next[head] = -1;
	/*for (int i = 1; i <= k; i++)  //把前k个中最小的，且指标最大的找出来
		if (a[i] <= b[0])
		{
			b[0] = a[i];
			head = i;
		}
	tail = head;
	pre[head] = next[head] = -1;*/ //Bug: 这里不能只把前k个数中的最小数塞入口，还是必须把每个数依次塞入并排好队
	for (int i = 1; i <= n; i++)  //下面依次往窗口中塞入数
	{
		if (a[i] <= a[head])  //如果进来的数比队列中所有数都要小，那么把这个数当成队列
		{
			if (i <= k) b[0] = a[i];  //Bug:在debug时，由于把两个情况合并，所以需要修改
			else
				b[i - k] = a[i];
			head = tail = i;
			pre[i] = next[i] = -1;
		}
		else
		{
			while (a[tail] >= a[i])
				tail = next[tail];
			next[i] = tail;
			pre[i] = -1;
			pre[tail] = i;
			tail = i;
			//下面从头开始清理最小的，直到找到下标在窗口内的
			while (head <= i - k)
				head = pre[head];
			if (i <= k) b[0] = a[head];
			else
				b[i - k] = a[head];
			next[head] = -1;
		}
	}
	for (int i = 0; i <= n - k; i++)
		cout << b[i] << ' ';
	cout << endl;
	//然后处理最大值
	b[0] = a[1];
	tail = head=1;
	pre[head] = next[head] = -1;
	for (int i = 1; i <= n; i++)  //下面依次往窗口中塞入数
	{
		if (a[i] >= a[head])  //如果进来的数比队列中所有数都要大，那么把这个数当成队列
		{
			if (i <= k) b[0] = a[i];
			else
				b[i - k] = a[i];
			head = tail = i;
			pre[i] = next[i] = -1;
		}
		else
		{
			while (a[tail] <= a[i])
				tail = next[tail];
			next[i] = tail;
			pre[i] = -1;
			pre[tail] = i;
			tail = i;
			//下面从头开始清理最大的，直到找到下标在窗口内的
			while (head <= i - k)
				head = pre[head];
			if (i <= k) b[0] = a[head];
			else
				b[i - k] = a[head];
			next[head] = -1;
		}
	}
	for (int i = 0; i <= n - k; i++)
		cout << b[i] << ' ';
	cout << endl;

	return 0;
}

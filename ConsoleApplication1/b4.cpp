#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& a, int p, int q, int r,int k,int& cnt)
{
	vector<int> tmp(r-p+1);
	int i = p, j = q + 1, t = 0;
	while (i <= q && j <= r)
	{
		if (a[i] <= a[j]) tmp[t++] = a[i++];
		else tmp[t++] = a[j++];

		cnt++;
		if (cnt == k) return tmp[t - 1];
	}
	while (i <= q)
	{
		tmp[t++] = a[i++];

		cnt++;
		if (cnt == k) return tmp[t - 1];
	}
		
	while (j <= r)
	{
		tmp[t++] = a[j++];

		cnt++;
		if (cnt == k) return tmp[t - 1];
	}
		
	for (int i = p, t = 0; i <= r; ++i, ++t) {
		a[i] = tmp[t];
	}

	return -1;  // K번째 저장이 발생하지 않은 경우
}

 int merge_sort(vector<int>& a,int p,int r,int k ,int& cnt )
{
	 int q;
	 if (p < r)
	 {
		 int q = (p + r) / 2;
		 int result = merge_sort(a, p, q, k, cnt);		//전반부 정렬
		 if (result != -1) return result;
		 result = merge_sort(a, q + 1, r, k, cnt);		//후반부 정렬
		 if (result != -1) return result;
		 return merge(a, p, q, r, k, cnt);		//병합
	 }
	 return -1;
}

int main()
{
	int n, k;

	cin >> n >> k;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	int result = merge_sort(a, 0, a.size() - 1,k,cnt);

	cout << result << endl;

	return 0;
}
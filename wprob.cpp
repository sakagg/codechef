
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int val[150];

vector<int> v;

LL merge(char a[], int start, int mid, int end)
{
	LL inv = 0;
	v.clear();
	int i, j;
	for(i=start, j=mid+1; i<=mid && j<=end;)
	{
		if(val[a[i]] <= val[a[j]])
		{
			v.pb(a[i]);
			i++;
		}
		else
		{
			v.pb(a[j]);
			j++;
			inv += mid-i + 1;
		}
	}
	while(i<=mid)
		v.pb(a[i++]);
	while(j<=end)
		v.pb(a[j++]);
	copy(v.begin(), v.end(), a+start);
	return inv;
}

LL mergeSort(char a[], int start, int end)
{
	if(start >= end)
		return 0;
	int mid = (start + end)/2;
	LL inv = mergeSort(a, start, mid);
	inv += mergeSort(a, mid+1, end);
	inv += merge(a, start, mid, end);
	return inv;
}

char s[100100], tmp[100100];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int len = strlen(s);
		LL mn = 1e15;
		for(int i=0; i<6; i++)
		{
			copy(s, s+len, tmp);
			val['r'] = i/2;
			val['g'] = 2-i%3;
			val['b'] = 1;
			if(i==1 || i==2)
				val['b'] = 2;
			else if(i==3 || i==4)
				val['b'] = 0;
			LL tmn = mergeSort(tmp, 0, len-1);
			mn = min(mn, tmn);
//			printf("%lld %d %d %d\n", tmn, val['r'], val['g'], val['b']);
		}
		printf("%lld\n", mn);
	}
	return 0;
}

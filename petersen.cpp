#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

char ans[100100];

int check(int start, char a[])
{
	ans[0] = start+'0';
	int i;
	for(i=1; a[i]; i++)
	{
		if(a[i] == a[i-1])
			start = (start+5)%10;
		else if(start < 5)
		{
			if(a[i]-'A' == ((a[i-1]-'A')+4)%5)
				start = (start+4)%5;
			else if(a[i]-'A' == ((a[i-1]-'A')+1)%5)
				start = (start+1)%5;
			else
				return 0;
		}
		else
		{
			if(a[i]-'A' == ((a[i-1]-'A')+3)%5)
				start = 5 + (start+3)%5;
			else if(a[i]-'A' == ((a[i-1]-'A')+2)%5)
				start = 5 + (start+2)%5;
			else
				return 0;
		}
		ans[i] = start + '0';
	}
	ans[i] = 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		char a[100100];
		scanf("%s", a);
		int start = a[0]-'A';
		if(check(start, a))
			printf("%s\n", ans);
		else if(check(start+5, a))
			printf("%s\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}


#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

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

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, num;
	char c;
	map<int, int> a[5];
	double count[5] = {0};
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		getchar();
		scanf("%c %d", &c, &num);
		c-='A';
		if(a[c].find(num) == a[c].end())
			a[c][num] = 1;
		else
			a[c][num]++;
		count[c]++;
	}
	for(int i=0; i<5; i++)
	{
		int none = 1;
		for(int j=0; j<=100; j++)
			if(a[i][j]/count[i] > 0.1)
			{
				printf("%d ", j);
				none = 0;
			}
		if(none)
			printf("Nothing Unusual");
		printf("\n");
	}
	return 0;
}


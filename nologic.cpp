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
	int T;
	char s[1000];
	scanf("%d", &T);
	while(T--)
	{
		int count[26] = {0};
		getchar();
		scanf("%[^\n]", s);
		for(int i=0; s[i]; i++)
		{
			if(isupper(s[i]))
				count[s[i]-'A'] = 1;
			else if(islower(s[i]))
				count[s[i]-'a'] = 1;
		}
		int i;
		for(i=0; i<26; i++)
			if(!count[i])
			{
				printf("%c\n", 'a'+i);
				break;
			}
		if(i==26)
			printf("~\n");
	}
	return 0;
}


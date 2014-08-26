#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cctype>

using namespace std;

void print(char *str, int start, int end)
{
	if(start>end)
		printf("0");
	else
	{
		str[end+1] = 0;
		printf("%s", str+start);
	}
	putchar('\n');
}

int main()
{
	int t, n, start, end, len, decimal;
	char map[127], c, p;
	char str[1000000];
	cin>>t;
	while(t--)
	{
		memset(map, 0, 127);
		scanf("%d", &n);
		while(n--)
		{
			getchar();		//Accomodate NewLine
			c = getchar();
			getchar();		//Accomodate Space
			p = getchar();
			map[c] = p;
		}
		scanf("%s", str);
//		printf("-----%s-------\n", str);
		for(int i=0; str[i]; i++)
		{
			c = map[str[i]];
			if(c)
				str[i] = c;
		}
		start = 0;
		decimal = 0;
		while(str[start] && str[start]=='0')
			start++;
		len = strlen(str);
		end = len-1;
		while(str[end]=='0' && end>start)
			end--;
		for(int i=start; i<=end; i++)
			if(str[i]=='.')
			{
				decimal = 1;
				break;
			}
		if(decimal)
		{
			if(str[end]=='.')
				end--;
			print(str, start, end);
		}
		else
			print(str, start, len-1);
	}
	return 0;
}

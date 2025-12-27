#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 110
string str[MAXN];
int day[MAXN], month[MAXN], year[MAXN];
int main()
{
    int N, i, Min, Max;

    while(scanf("%d", &N)==1)
    {

        for(i=1; i<=N; i++)
            cin >> str[i],scanf("%d %d %d", &day[i], &month[i], &year[i]);

        Min=Max=1;

        for(i=2; i<=N; i++)
        {
            //printf("%d %d\n%d %d\n %d %d\n", day[Min], day[i], month[Min], month[i], year[Min], year[i]);

                if(year[i] > year[Min])
                {
                    Min = i;
                    continue;
                }
                else if(year[i] == year[Min])
                {
                    if(month[i] > month[Min])
                    {
                        Min = i;
                        continue;
                    }
                    else if(month[i] == month[Min])
                    {
                        if(day[i] > day[Min])
                        {
                            Min = i;
                            continue;
                        }
                    }
                }

            if(year[i] < year[Max])
                {
                    Max = i;
                    continue;
                }
                else if(year[i] == year[Max])
                {
                    if(month[i] < month[Max])
                    {
                        Max = i;
                        continue;
                    }
                    else if(month[i] == month[Max])
                    {
                        if(day[i] < day[Max])
                        {
                            Max = i;
                            continue;
                        }
                    }
                }
        }

        cout<<str[Min]<<'\n'<<str[Max]<<'\n';
    }

    return 0;
}

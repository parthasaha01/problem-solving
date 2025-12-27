#include<bits/stdc++.h>
using namespace std;
#define Mx 10002
int rac[Mx+2];
void Ractangles()
{
    int cnt=0,sqr,i;
    for(int num=1; num<=Mx; num++)
    {
        sqr=sqrt(num);
        i=1;
        while(i<=sqr)
        {
            if(num%i==0)
                ++cnt;

            i++;
        }
        rac[num]=cnt;
    }
}
int main()
{
    Ractangles();
    int N;
    while(cin >> N)
    {
        cout << rac[N] << endl;
    }

    return 0;
}

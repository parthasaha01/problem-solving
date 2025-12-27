#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x,d;
    char ch;

    //while(scanf("%ld%ld",&n,&x)==2)
    //{
        cin >> n >> x;
        long long int cnt=0;

        for(int i=0; i<n; i++)
        {
            //getchar();
            //scanf("%c %ld",&ch,&d);
            cin >> ch >> d;

            if(ch=='-'){
                if(d<=x){
                    x -= d;
                }
                else{
                    ++cnt;
                }
            }
            else{
                x+=d;
            }
        }

        //printf("%ld %ld\n",x,cnt);
        cout << x << " " << cnt << endl;
    //}

    return 0;
}

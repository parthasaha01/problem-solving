#include<bits/stdc++.h>
using namespace std;
#define Max 1000000
int seq[Max+5];
int nextpos[Max+5];
int main()
{
    long N,i,Min,Minx,left,right;
    int T,M,K,cnt,test;

    cin >> T;

    for(test=1; test<=T; test++)
    {
        cin >> N >> M >> K;

        seq[1]=1, seq[2]=2, seq[3]=3;

        for(i=4; i<=N; i++)
        {
            seq[i]=(seq[i-1]+seq[i-2]+seq[i-3])%M + 1;
        }

        int pos[1005];
        memset(pos, 0, sizeof(pos));

        for(i=N; i>0; i--)
        {
            nextpos[i]=pos[seq[i]];
            pos[seq[i]]=i;
        }

        bool freq[1005];
        memset(freq, false, sizeof(freq));

        int cnt=0,left=1,right=0;

        for(i=1; i<=N; i++)
        {
            if(seq[i]<=K && freq[seq[i]]==false)
            {
                freq[seq[i]]=true;
                cnt++;
            }
            if(cnt==K)
            {
                right=i;
                break;
            }
        }

        if(right==0)
        {
            cout << "Case " << test << ": sequence nai" << endl;
        }
        else
        {
            Min=right-left+1;

            //cout << left << " " << right << " "<<  Min << endl;

            while(left<right)
            {
                if(seq[left]>K)
                {
                    left++;
                }
                else if(nextpos[left]==0)
                {
                    break;
                }
                else if(nextpos[left]<=right)
                {
                    left++;
                }
                else
                {
                    right=nextpos[left];
                    left++;
                }

                Minx=right-left+1;

                if(Minx<Min)
                {
                    Min=Minx;
                }
            }

            cout << "Case " << test << ": " << Min << endl;
        }

    }

    return 0;
}

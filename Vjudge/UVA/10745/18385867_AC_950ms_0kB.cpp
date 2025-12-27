#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <string> str;
    string c;
    int cnt = 0;
    while(cin>>c)
    {
        str.push_back(c);
        cnt++;
    }
    sort(str.begin(), str.end());
    int A[130];
    int B[130];
    int C[15100];
    int lenA,lenB;
    int count =0;
    int flag;
    for(int i=0;i<cnt;i++)
    {
        memset(A,0,sizeof(A));
        lenA=str[i].size();
        for(int k=0;k<lenA;k++)
        {
            A[str[i][k]]++;
        }
        flag=1;
        for(int j=0;j<cnt;j++)
        {
            if(j==i)
            {
                continue;
            }
            lenB=str[j].size();
            if (lenB<lenA)
            {
                flag=0;
                continue;
            }
            memset(B,0,sizeof(B));
            for(int l=0;l<lenB;l++)
            {
                B[str[j][l]]++;
            }
            for(int x=0;x<lenA;x++)
            {
                if(A[str[i][x]]>B[str[i][x]])
                {
                    flag=0;
                    break;
                }
                flag=1;
            }
            if(flag)
            {
                break;
            }

        }
        if(flag==0)
        {
            C[count]=i;
            count++;
        }
    }
    for(int i=0;i<count;i++)
    {
        cout<<str[C[i]]<<endl;
    }
    str.clear();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*char ch='A';
    for(int i=1; i<=26; i++){
        printf("%c %d\n",ch++,i);
    }*/

    int T,r;
    scanf("%d",&T);
    string s;
    char a[100];
    a[95]='_';

    while(T--)
    {
        cin >> s;
        scanf("%d",&r);

        //cout << s << " " << r << endl;

        for(int i=65; i<=90; i++){
            a[i]=i;
        }

        /*for(int i=65; i<=90; i++){
            printf("%c ",a[i]);
        }
        printf("\n");*/

        char de,so;
        for(int q=0; q<r; q++)
        {
            getchar();
            scanf("%c %c",&de,&so);
            //printf("%c %c\n",de,so);

            for(int i=65; i<=90; i++)
            {
                if(a[i]!='_'){
                    if(a[i]==so){
                        a[i]=de;
                    }
                }
            }
        }

        int sz=s.size();

        for(int i=0; i<sz; i++)
        {
            s[i] = a[s[i]];
        }

        cout << s << endl;
    }

    return 0;
}

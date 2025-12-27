#include<bits/stdc++.h>
using namespace std;
//vector<string>v[15],vl[15];
string s;
/*void init()
{
    v[3].push_back("one");
    v[3].push_back("two");
    v[3].push_back("six");
    v[3].push_back("ten");
    vl[3].push_back("1");
    vl[3].push_back("2");
    vl[3].push_back("6");
    vl[3].push_back("10");

    v[4].push_back("zero");
    v[4].push_back("four");
    v[4].push_back("five");
    v[4].push_back("nine");
    vl[4].push_back("0");
    vl[4].push_back("4");
    vl[4].push_back("5");
    vl[4].push_back("9");

    v[5].push_back("three");
    v[5].push_back("seven");
    v[5].push_back("eight");
    v[5].push_back("forty");
    v[5].push_back("fifty");
    v[5].push_back("sixty");
    vl[5].push_back("3");
    vl[5].push_back("7");
    vl[5].push_back("8");
    vl[5].push_back("40");
    vl[5].push_back("50");
    vl[5].push_back("60");

    v[6].push_back("eleven");
    v[6].push_back("twelve");
    v[6].push_back("twenty");
    v[6].push_back("thirty");
    v[6].push_back("eighty");
    v[6].push_back("ninety");
    vl[6].push_back("11");
    vl[6].push_back("12");
    vl[6].push_back("20");
    vl[6].push_back("30");
    vl[6].push_back("80");
    vl[6].push_back("90");

    v[7].push_back("fifteen");
    v[7].push_back("sixteen");
    v[7].push_back("seventy");
    vl[7].push_back("15");
    vl[7].push_back("16");
    vl[7].push_back("70");

    v[8].push_back("thirteen");
    v[8].push_back("fourteen");
    v[8].push_back("eighteen");
    v[8].push_back("nineteen");
    vl[8].push_back("13");
    vl[8].push_back("14");
    vl[8].push_back("18");
    vl[8].push_back("19");

    v[9].push_back("seventeen");
    vl[9].push_back("17");
}
int func(int len)
{
    int sz=v[len].size();

    for(int k=0; k<sz; k++)
    {
        string tm=v[len][k];
        int cnt=0;

        for(int i=0; i<len; i++)
        {
            if(s[i]!=tm[i])
            {
                ++cnt;

                if(cnt>1)
                    break;
            }
        }

        if(cnt==1){
                return k;
        }
    }
}*/
int main()
{
    //init();

    int T,res;
    scanf("%d",&T);

    for(int test=1; test<=T; test++)
    {
        cin >> s;
        int len=s.size();
        int cnt=0;

        if(len==5)
            res=3;
        else
        {
            if(s[0]=='o') ++cnt;
            if(s[1]=='n') ++cnt;
            if(s[2]=='e') ++cnt;

            if(cnt>=2)
                res=1;
            else
                res=2;
        }

        printf("%d\n",res);
    }

    return 0;
}

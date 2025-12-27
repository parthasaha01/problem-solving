#include<bits/stdc++.h>
using namespace std;
int la,lb,dp[50][50];
string a,b;
vector<string>vv;
vector<int>uu;
int editDistance(int i,int j)
{
    if(i==la)return lb-j;   // insert
    if(j==lb)return la-i;   // delete

    if(dp[i][j] != -1)return dp[i][j];

    int ret1,ret2,ret3,ret4;

    if(a[i]==b[j]){
        ret1 = editDistance(i+1,j+1);
    }
    else{
        ret2 = 1 + editDistance(i+1,j+1);   // change
        ret3 = 1 + editDistance(i,j+1);     // insert
        ret4 = 1 + editDistance(i+1,j);     // delete

        ret1 = min(ret2,min(ret3,ret4));
    }

    return dp[i][j] = ret1;
}
void path(int i,int j,int p)
{
    if(i==la)return;
    if(j==lb)return;

    int ret1,ret2,ret3,ret4;

    if(a[i]==b[j]){
        path(i+1,j+1,p+1);
        if(i+1==la){
            int x=1;
            for(int k=j+1; k<lb; k++,x++){
                string ss;
                ss += "I"; ss += b[k];
                if(p+x<10) ss+= "0";
                vv.push_back(ss);
                uu.push_back(p+x);
            }
        }
        if(j+1==lb){
            for(int k=i+1; k<la; k++){
                string ss;
                ss += "D"; ss += a[k];
                if(p+1<10) ss+= "0";
                vv.push_back(ss);
                uu.push_back(p+1);
            }
        }
    }
    else{
        ret2 = 1 + editDistance(i+1,j+1);   // change
        ret3 = 1 + editDistance(i,j+1);     // insert
        ret4 = 1 + editDistance(i+1,j);     // delete

        if(ret2<=ret3 && ret2<=ret4)    // change
        {
            string ss;
            ss += "C"; ss += b[j];
            if(p<10) ss+= "0";
            vv.push_back(ss);
            uu.push_back(p);

            path(i+1,j+1,p+1);

            if(i+1==la){
                int x=1;
                for(int k=j+1; k<lb; k++,x++){
                    string ss;
                    ss += "I"; ss += b[k];
                    if(p+x<10) ss+= "0";
                    vv.push_back(ss);
                    uu.push_back(p+x);
                }
            }
            if(j+1==lb){
                for(int k=i+1; k<la; k++){
                    string ss;
                    ss += "D"; ss += a[k];
                    if(p+1<10) ss+= "0";
                    vv.push_back(ss);
                    uu.push_back(p+1);
                }
            }
        }
        else if(ret3<=ret2 && ret3<=ret4)   // insert
        {
            string ss;
            ss += "I"; ss += b[j];
            if(p<10) ss+= "0";
            vv.push_back(ss);
            uu.push_back(p);

            path(i,j+1,p+1);

            if(j+1==lb){
                for(int k=i; k<la; k++){
                    string ss;
                    ss += "D"; ss += a[k];
                    if(p+1<10) ss+= "0";
                    vv.push_back(ss);
                    uu.push_back(p+1);
                }
            }
        }
        else    // delete
        {
            string ss;
            ss += "D"; ss += a[i];
            if(p<10) ss+= "0";
            vv.push_back(ss);
            uu.push_back(p);
            path(i+1,j,p);
            if(i+1==la){
                int x=1;
                for(int k=j; k<lb; k++,x++){
                    string ss;
                    ss += "I"; ss += b[k];
                    if(p+x-1<10) ss+= "0";
                    vv.push_back(ss);
                    uu.push_back(p+x-1);
                }
            }
        }
    }
}
int main()
{
    while(cin>>a)
    {
        if(a=="#")break;

        cin>>b;
        la = a.size();
        lb = b.size();

        memset(dp,-1,sizeof(dp));
        int cnt = editDistance(0,0);

        path(0,0,1);

        for(int i=0; i<vv.size(); i++){
            cout << vv[i] << uu[i];
        }
        cout << "E" << endl;

        vv.clear();
        uu.clear();
    }
    return 0;
}

/*
xyzbcpqde bcgfe
xyzbcdepq bcgfe
xyzbcde bcgfe
xyzbcdep bcgfe

*/


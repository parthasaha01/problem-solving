#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
string s;
int sz;
int main()
{
    cin>>s;

    int sz = s.size();

    if(s[0]=='b')vv.push_back(0);

    int cnt = 1;
    for(int i=1; i<sz; i++)
    {
        if(s[i]==s[i-1]){
            cnt++;
        }
        else{
            vv.push_back(cnt);
            cnt = 1;
        }
    }

    vv.push_back(cnt);


    if(s[sz-1]=='b')vv.push_back(0);

    int vz = vv.size();


    int maxx = 0;
    for(int i=0; i<vz; i+=2)
    {
        int val = 0;
        if(i<vz) val+= vv[i];
        if(i+1<vz) val+= vv[i+1];
        if(i+2<vz) val+= vv[i+2];

        maxx = max(maxx,val);
    }

    int sum=0;

    for(int i=0; i<sz; i+=2)
    {
        sum+=vv[i];
    }

    int rem = 0;

    for(int i=1; i<vz; i+=2){
        rem = max(rem,vv[i]);
    }

    int tmm = sum+rem;

    maxx = max(maxx,tmm);

    //cout << "max=" << maxx << endl;

    sum = 0;

    sum += vv[0];
    sum += vv[vz-1];

    //cout << vv[0] << " " << vv[vz-1] << endl;

    for(int i=1; i<vz; i+=2){
        sum += vv[i];
    }

    maxx = max(maxx,sum);
    printf("%d\n",maxx);

    return 0;
}


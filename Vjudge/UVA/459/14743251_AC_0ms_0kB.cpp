#include<bits/stdc++.h>
using namespace std;
int parent[30];
int cc=0;
int find_parent(int u)
{
    if(parent[u]==u) return u;
    return parent[u]=find_parent(parent[u]);
}
void union_set(int u,int v)
{
    int a = find_parent(u);
    int b = find_parent(v);
    if(a!=b){
        if(a>b) parent[a]=b;
        else parent[b]=a;
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    int test;
    cin>>test;
    map<char,int>mp;
    char ch='A';
    for(int i=1; i<=26; i++){
        mp[ch++] = i;
    }
    //cin.ignore();


    for(int ks=1; ks<=test; ks++)
    {
        //cin.ignore();
        //getchar();
        string str;
        for(int i=1; i<=28; i++){
            parent[i]=i;
        }

        cin>>str;
        getchar();
        char st_r = str[0];
        cc=st_r-'A'+1;

        while(1)
        {
            getline(cin,str);
            if(str.size()==0)break;
            union_set(mp[str[0]],mp[str[1]]);
        }

        int coun=0;
        for(int i=1; i<=mp[st_r]; i++){
            int p = find_parent(i);
            if(p==i)coun++;
        }

        if(ks!=1)printf("\n");
        cout<<coun<<endl;
    }
    return 0;
}


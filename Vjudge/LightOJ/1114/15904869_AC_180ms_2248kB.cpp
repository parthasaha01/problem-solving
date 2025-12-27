#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1; // FOR UNORDERED MAP

typedef long long ll;

const long long mod = 23333333333333333;
unordered_map<ll, int> mp;

ll gethash(string& s){
    int l = s.size();
    ll sum = 0;
    for(int i = 0; i < l; i++){
        sum *= 2333;
        sum += s[i];
        sum %= mod;
    }
    return sum;
}

void Insert(string& s){
    ll hashvalue = gethash(s);
    if(mp.find(hashvalue) != mp.end()) mp[hashvalue]++;
    else mp[hashvalue] = 1;
}

int Search(string& s){
    ll hashvalue = gethash(s);
    if(mp.find(hashvalue) != mp.end()) return mp[hashvalue];
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    for(int ks = 1; ks <= T; ks++) {

        mp.clear();
        string word, sentence;

        int n; cin >> n;
        for(int i = 1; i <= n; i++)
        {
            string word; cin >> word;
            if(word.size() > 2)
                sort(word.begin() + 1, word.end() - 1);

            Insert(word);
        }

        printf("Case %d:\n", ks);
        int m; cin >> m;
        cin.ignore(); //important

        for(int i = 1; i <= m; i++)
        {
            getline(cin, sentence);
            stringstream ss(sentence);
            int res = 1;

            while(ss >> word)
            {
                if(word.size() > 2)
                    sort(word.begin() + 1, word.end() - 1);

                res *= Search(word);
                if(res == 0) break;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
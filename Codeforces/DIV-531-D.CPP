#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        string s; cin>>s;
        int zero = 0, one=0, two=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0')zero++;
            else if(s[i]=='1')one++;
            else two++;
        }

        if(zero==one && one==two){
            cout<<s<<endl;
        }else{
            int each = n/3;
            if(one<each && two<each){
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='0' && two<each){
                        s[i] = '2';
                        zero--;
                        two++;
                    }
                }
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='0' && one<each){
                        s[i] = '1';
                        zero--;
                        one++;
                    }
                }
                cout<<s<<endl;

            }else if(zero<each && two<each){
                for(int i=0; i<n; i++){
                    if(s[i]=='1' && zero<each){
                        s[i] = '0';
                        one--;
                        zero++;
                    }
                }
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='1' && two<each){
                        s[i] = '1';
                        one--;
                        two++;
                    }
                }
                cout<<s<<endl;

            }else if(zero<each && one<each){
                for(int i=0; i<n; i++){
                    if(s[i]=='2' && zero<each){
                        s[i] = '0';
                        two--;
                        zero++;
                    }
                }
                for(int i=0; i<n; i++){
                    if(s[i]=='2' && one<each){
                        s[i] = '1';
                        two--;
                        one++;
                    }
                }
                cout<<s<<endl;

            }else if(two<each){
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='0' && zero>each){
                        s[i] = '2';
                        zero--;
                        two++;
                    }else if(s[i]=='1' && one>each){
                        s[i] = '2';
                        one--;
                        two++;
                    }
                }
                cout<<s<<endl;

            }else if(one<each){
                for(int i=0; i<n; i++){
                    if(s[i]=='2' && two>each){
                        s[i] = '1';
                        two--;
                        one++;
                    }
                }
                for(int i=n-1; i>=0; i--){
                    if(s[i]=='0' && zero>each){
                        s[i] = '1';
                        zero--;
                        one++;
                    }
                }
                cout<<s<<endl;

            }else if(zero<each){
                for(int i=0; i<n; i++){
                    if(s[i]=='1' && one>each){
                        s[i] = '0';
                        one--;
                        zero++;
                    }else if(s[i]=='2' && two>each){
                        s[i] = '0';
                        two--;
                        zero++;
                    }
                }
                cout<<s<<endl;
            }
        }
    }
    return 0;
}


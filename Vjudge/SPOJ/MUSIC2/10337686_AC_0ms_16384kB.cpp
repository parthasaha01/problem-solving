#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main()
{
    mp["A major"] = "UNIQUE";
    mp["A minor"] = "UNIQUE";

    mp["B major"] = "UNIQUE";
    mp["B minor"] = "UNIQUE";

    mp["C major"] = "UNIQUE";
    mp["C minor"] = "UNIQUE";

    mp["D major"] = "UNIQUE";
    mp["D minor"] = "UNIQUE";

    mp["E major"] = "UNIQUE";
    mp["E minor"] = "UNIQUE";

    mp["F major"] = "UNIQUE";
    mp["F minor"] = "UNIQUE";

    mp["G major"] = "UNIQUE";
    mp["G minor"] = "UNIQUE";

    mp["A# major"] = "Bb major";
    mp["A# minor"] = "Bb minor";
    mp["Bb major"] = "A# major";
    mp["Bb minor"] = "A# minor";

    mp["C# major"] = "Db major";
    mp["C# minor"] = "Db minor";
    mp["Db major"] = "C# major";
    mp["Db minor"] = "C# minor";

    mp["D# major"] = "Eb major";
    mp["D# minor"] = "Eb minor";
    mp["Eb major"] = "D# major";
    mp["Eb minor"] = "D# minor";

    mp["F# major"] = "Gb major";
    mp["F# minor"] = "Gb minor";
    mp["Gb major"] = "F# major";
    mp["Gb minor"] = "F# minor";

    mp["G# major"] = "Ab major";
    mp["G# minor"] = "Ab minor";
    mp["Ab major"] = "G# major";
    mp["Ab minor"] = "G# minor";

    string ss;
    int ks=0;
    while(getline(cin,ss))
    {
        printf("Case %d: ",++ks);
        cout << mp[ss] << endl;
    }

    return 0;
}

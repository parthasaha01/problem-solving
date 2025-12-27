#include <iostream>
#include <queue>

using namespace std;

struct hambaa
{
string apprnce;
int age;
hambaa(string s, int nmbr){apprnce=s; age=nmbr;}
bool operator < ( const hambaa& p) const { return p.age < age; }
};

main ()
{
    priority_queue <hambaa> pq;
    pq.push(hambaa("bachhur",1));
    pq.push( hambaa("boro goru",16 ));
    pq.push( hambaa("majhari goru", 6));
    pq.push(hambaa("majhari boro goru", 10));

    while ( !pq.empty() )
    {
        cout << pq.top().apprnce<< " " << pq.top().age << endl;
        pq.pop();
    }
}

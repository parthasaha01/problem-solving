#include<bits/stdc++.h>
using namespace std;
struct Job{
    string id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    if(a.profit>b.profit)
        return true;
    else
        return false;
}
void JobSequence(Job arr[], int n)
{
    sort(arr+1,arr+n+1,compare);

    /*cout << "The list of Job at decreasing Profit:" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i].id << " " << arr[i].deadline << " " << arr[i].profit << endl;
    }*/

    int result[n+1];
    bool slot[n+1];
    int TotalProfit=0;
    memset(slot,false,sizeof(slot));

    for(int i=1; i<=n; i++)
    {
        for(int j=min(n,arr[i].deadline); j>0; j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                TotalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << endl << "Job Sequence:" << endl;
    for(int i=1; i<=n; i++)
    {
        if(slot[i]==true)
        {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << endl << endl << "Total Profit: " << TotalProfit << endl << endl;
}
int main()
{
    int n;
    cout << "Enter the number of Job: ";
    cin >> n;
    Job arr[n+1];
    cout << "Enter the name, deadline, profit of all Jobs:\n" << endl;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    JobSequence(arr,n);

    return 0;
}

/*
T1 7 15
T2 2 20
T3 5 30
T4 3 18
T5 4 18
T6 5 10
T7 2 23
T8 7 16
T9 3 25
*/

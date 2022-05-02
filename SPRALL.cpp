#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long int getNaturalSum(long long int n)
{
    return ((n*(n+1))/2);
}

int main() 
{
    ifstream cin("input.txt");
    int t,n,q;

    cin>>t;

    while(t--)
    {
        cin>>n>>q;

        unordered_map<int,int> deg;

        for(int i=0;i<n-1;i++)
        {
            int x,y;

            cin>>x>>y;
            deg[x]++;
            deg[y]++;
        }

        long long int sum=0;
        for(auto x:deg)
        {
            sum+=getNaturalSum(x.second);
            
        }
        sum-=(n-1);
        cout<<sum<<endl;

        for(int i=0;i<q;i++)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            long long int ans = sum-(deg[a]);
            deg[a]--;
            ans = ans - deg[b];
            deg[b]--;

            ans += (deg[c]+1);
            deg[c]++;
            ans += deg[d]+1;
            deg[d]++;

            deg[a]++;
            deg[b]++;
            deg[c]--;
            deg[d]--;

            cout<<ans<<endl;
        }
    }
}
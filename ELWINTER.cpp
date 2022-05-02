#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{
    private:
        vector< vector<int> > gr;
        queue<int> q;
        unordered_set<int> s;

    public:
        
        Solution(vector< vector<int> > &g)
        {
            gr = g;
        }

        bool processQueries(int t,int x)
        {
            if(t==1)
            {
                if(s.find(x)==s.end())
                {
                    s.insert(x);
                    q.push(x);
                }
            }
            else if(t==2)
            {
                for(int i=0;i<x && !q.empty();i++)
                {
                    int si = q.size();
                    for(int j=0;j<si;j++)
                    {
                        int temp = q.front();
                        q.pop();
                        for(int k=0;k<gr[temp].size();k++)
                        {
                            if(s.find(gr[temp][k])==s.end())
                            {
                                s.insert(gr[temp][k]);
                                q.push(gr[temp][k]);
                            }
                        }
                    }
                }
            }
            else
            {
                return (s.find(x)!=s.end());
            }

            return true;
        }
};

int main() 
{
    ifstream cin("input.txt");

    int n,m,q;
    cin>>n>>m>>q;
    vector< vector<int> > graph(n+1);

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    Solution sol(graph);

    for(int i=0;i<q;i++)
    {
        int t,x;
        cin>>t>>x;
        bool ans = sol.processQueries(t,x);
        if(t==3)
        {
            cout<<(ans?"YES":"NO")<<endl;
        }
    }
}
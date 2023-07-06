#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>


using namespace std;

long long int number = 1e9 + 7;
//function to print the matrix
void printMatrix(vector<vector<long long int> > matrix, long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



class triple{
    public:
    long long int a;
    long long int b;
    long long int c;
};

//function to print the adjacency list
void printAdj(vector<triple> adj[], long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (long long int j = 0; j < adj[i].size(); j++)
        {
            cout << "("<< adj[i][j].a << " " << adj[i][j].b << " " << adj[i][j].c << ")" << " ";
        }
        cout << endl;
    }
}








int main()
{
    long long int n, m;
    cin >> n >> m;


    vector<vector<long long int> > matrix(m, vector<long long int>(4));
    vector<triple> adj[n+1];
    vector<long long int> visited(n+1, 0);

    for (long long int i = 0; i < m; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] >> matrix[i][3];
        if(matrix[i][0]!=matrix[i][1])
        {
            triple v;
            v.a = matrix[i][1];
            v.b = matrix[i][2];
            v.c = matrix[i][3];
            adj[matrix[i][0]].push_back(v);

            // adj[matrix[i][0]].push_back(matrix[i][1]);
            // adj[matrix[i][0]].push_back(matrix[i][2]);
            // adj[matrix[i][0]].push_back(matrix[i][3]);

            triple v1;
            v1.a = matrix[i][0];
            v1.b = matrix[i][2];
            v1.c = matrix[i][3];
            adj[matrix[i][1]].push_back(v1);

            // adj[matrix[i][1]].push_back(matrix[i][0]);
            // adj[matrix[i][1]].push_back(matrix[i][2]);
            // adj[matrix[i][1]].push_back(matrix[i][3]);
        }
    
    }

    if(m==0){
        if(n==1){
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
        return 0;
    }

    printAdj(adj, n+1);


    // vector<vector<long long int> > dp(3, vector<long long int>(n+1,1));
    //dp[0][0] = dp[1][0] = 1; //base case

    priority_queue<pair<long long int, long long int>,vector<pair<long long int,long long int> >,greater<pair<long long int,long long int> > > pq;

    vector<long long int> totaltime(n+1,1e15);
    totaltime[0] = 0; totaltime[1] = 0;
    pq.push({totaltime[1],1});

    while(!pq.empty()){
        long long int time = pq.top().first;
        long long int node = pq.top().second;
        pq.pop();
        if(visited[node]==2){
            continue;
        }
        visited[node] = 1;

        for(auto it : adj[node]){

            class triple p = it;  

            long long int adjNode = p.a;
            long long int X = p.b;
            long long int Y = p.c;
            long long int tprev = time;
            long long int twait = 0;

            long long int Ysqrt = ceil(sqrt(Y));
            if(Ysqrt - tprev - 1>0){
                twait = (Ysqrt - tprev - 1);
            }

            long long int tamount = (Y/(tprev+twait+1)) + X + twait;
            tamount = tamount + time;
            if(tamount < totaltime[adjNode]){
                totaltime[adjNode] = tamount;
                pq.push({totaltime[adjNode],adjNode});
            }
        }
        visited[node] = 2;
        
    }

    if(visited[n]!=2){
        cout<<-1<<endl;
        return 0;
    }

    // for(long long int i=1;i<=n;i++){
    //     cout<<totaltime[i]<<" ";
    // }
    cout<<totaltime[n]<<endl;







    
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>


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

//function to print the dp matrix
void printdp(vector<vector<long long int> > matrix, long long int n, long long int m)
{
    for (long long int i = 0; i < m; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//function to print the adjacency list
void printAdj(vector<long long int> adj[], long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (long long int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
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


triple dfs(vector<long long int> adj[], vector<vector<long long int> >& dp, vector<long long int>& visited, long long int node)
{
    if(visited[node] == 2)
    {
        class triple p;
        p.a = (dp[0][node]) % number;
        p.b = (dp[1][node]) % number;
        p.c = (dp[2][node]) % number;
        return p;
    }

    visited[node] = 1;
    int flag = 0;
    for (long long int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]] == 0)
        {
            class triple p = dfs(adj, dp, visited, adj[node][i]);
            dp[0][node] = (dp[0][node] * p.b) % number;
            dp[1][node] = (dp[1][node] * p.c) % number;
            flag = 1;
        }
    }

    visited[node] = 2;

    if(flag==0){
        dp[0][node] = 1;
        dp[1][node] = 1;
        dp[2][node] = 2;
    }
    else{
        dp[2][node] = (dp[0][node] + dp[1][node]) % number;
    }

    class triple p;
    p.a = (dp[0][node]) % number;
    p.b = (dp[1][node]) % number;
    p.c = (dp[2][node]) % number;
    return p;

    

}




int main()
{
    long long int n;
    cin >> n;

    vector<vector<long long int> > matrix(n+1, vector<long long int>(2));
    vector<long long int> adj[n+1];
    vector<long long int> visited(n+1, 0);

    for (long long int i = 0; i < n-1; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
        adj[matrix[i][0]].push_back(matrix[i][1]);
        adj[matrix[i][1]].push_back(matrix[i][0]);

    }


    vector<vector<long long int> > dp(3, vector<long long int>(n+1,1));
    //dp[0][0] = dp[1][0] = 1; //base case

    

    class triple p = dfs(adj, dp, visited, 1);



    
    //cout<<"Here is the matrix:"<<endl;
    //printMatrix(matrix, n);

    // cout<<"Here is the adjacency list:"<<endl;
    // printAdj(adj, n+1);

    // cout<<"Here is the dp:"<<endl;
    // printdp(dp, n+1, 3);

    //cout << dp[n][2] << endl;
    cout<<(p.c % number)<<endl;



    
    return 0;
}

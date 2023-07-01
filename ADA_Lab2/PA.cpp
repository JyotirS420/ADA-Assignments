#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

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




int main()
{
    long long int n;
    cin >> n;

    vector<vector<long long int> > matrix(n, vector<long long int>(2));


    for (long long int i = 0; i < n; i++)
    {
        cin >> matrix[i][0] >> matrix[i][1];
    }


    vector<vector<long long int> > dp(2, vector<long long int>(n,0));
    dp[0][0] = dp[1][0] = 1; //base case

    //for storing the previous element
    vector<vector<long long int> > prev(2, vector<long long int>(n,0));
    prev[0][0] = matrix[0][0];
    prev[1][0] = matrix[0][1];

    long long int num1, num2, prev1, prev2;
    long long int number = 998244353;
    int flag0 = 0, flag1 = 0;
    long long int factor = 1;

    for(long long int i = 1; i<n; i++){
        
        num1 = matrix[i][0];
        num2 = matrix[i][1];

        prev1 = prev[0][i-1];
        prev2 = prev[1][i-1];
        if(prev1==prev2){
            factor = 2;
        }
        else{
            factor = 1;
        }

        if(flag0==1){
            dp[0][i] = 0;
        }
        //if num1 is not equal to prev1 and prev2
        else if(num1!=prev1 && num1!=prev2){
            dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % number;
        }
        //if num1 is equal to prev1 but not to prev2
        else if(num1==prev1 && num1!=prev2){
            dp[0][i] = (dp[1][i-1]) % number;
        }
        //if num1 is equal to prev2 but not to prev1
        else if(num1!=prev1 && num1==prev2){
            dp[0][i] = (dp[0][i-1]) % number;
        }
        //else no possible arrangement
        else{
            dp[0][i] = 0;
            flag0 = 1;
        }


        if(flag1==1){
            dp[1][i] = 0;
        }
        //if num2 is not equal to prev1 and prev2
        else if(num2!=prev1 && num2!=prev2){
            dp[1][i] = (dp[0][i-1] + dp[1][i-1]) % number;
        }
        //if num2 is equal to prev1 but not to prev2
        else if(num2==prev1 && num2!=prev2){
            dp[1][i] = (dp[1][i-1]) % number;
        }
        //if num2 is equal to prev2 but not to prev1
        else if(num2!=prev1 && num2==prev2){
            dp[1][i] = (dp[0][i-1]) % number;
        }
        //else no possible arrangement
        else{
            dp[1][i] = 0;
            flag1 = 1;
        }

        dp[0][i] = dp[0][i] / factor;
        dp[1][i] = dp[1][i] / factor;
        
        prev[0][i] = matrix[i][0];
        prev[1][i] = matrix[i][1];


    }


    
    //cout<<"Here is the matrix:"<<endl;
    //printMatrix(matrix, n);

    long long int count = (dp[0][n-1] + dp[1][n-1]);
    count = count % number;
    if(matrix[n-1][0]==matrix[n-1][1]){
        count = count/2;
    }

    //long long int mid = floor(n/2);
    //printMatrix(matrix+mid, n-mid);

    //cout << count << endl;

    cout<<count<<endl;

    
    return 0;
}
/*
3
1 2
4 2
3 4


4
1 5
2 6
3 7
4 8
*/

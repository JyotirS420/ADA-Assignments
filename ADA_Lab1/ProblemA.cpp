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



vector<vector<long long int> > combine(vector<vector<long long int> > left, vector<vector<long long int> > right, long long int n, long long int *count){

    vector<vector<long long int> > result(n, vector<long long int>(2));

    long long int mid = floor(n/2);
    long long int i = 0;
    long long int j = 0;
    long long int k = 0;

    //merge the two arrays on the basis of the [1] element
    while(i<mid && j<n-mid){
        if(left[i][1]<=right[j][1]){
            result[k][0] = left[i][0];
            result[k][1] = left[i][1];
            i++;
        }
        else{
            result[k][0] = right[j][0];
            result[k][1] = right[j][1];
            if(left[i][0]!=right[j][0]){
                *count = *count + (mid-i);
            }
            j++;
        }
        k++;
    }
    //cout<<" "<<*count<<endl;
    
    //copying the remaining elements
    while(i<mid){
        result[k][0] = left[i][0];
        result[k][1] = left[i][1];
        i++;
        k++;
    }
    while(j<n-mid){
        result[k][0] = right[j][0];
        result[k][1] = right[j][1];
        j++;
        k++;
    }
    //cout<<"Here"<<endl;

    return result;
}


vector<vector<long long int> > merge(vector<vector<long long int> > matrix, long long int n, long long int *count){
    
    if(n==1){
        return matrix; // base case
    }

    long long int mid = floor(n/2);

    vector<vector<long long int> > matrixhalf1;
    vector<vector<long long int> > matrixhalf2;
    //copy the first half of the matrix
    for(long long int i=0; i<mid; i++){
        matrixhalf1.push_back(matrix[i]);
    }
    //copy the second half of the matrix
    for(long long int i=mid; i<n; i++){
        matrixhalf2.push_back(matrix[i]);
    }
    
    vector<vector<long long int> > left = merge(matrixhalf1, mid, count);
    vector<vector<long long int> > right = merge(matrixhalf2, n-mid, count);
    vector<vector<long long int> > result (n, vector<long long int>(2));
    result = combine(left, right, n, count);

    // vector<vector<long long int> > right = merge(matrix, n-mid, count);
    // vector<vector<long long int> > result = combine(left, right, n, count);



    return result;
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

    
    sort(matrix.begin(), matrix.end());


    
    //cout<<"Here is the matrix:"<<endl;
    //printMatrix(matrix, n);

    long long int count = 0;

    //long long int mid = floor(n/2);
    //printMatrix(matrix+mid, n-mid);

    vector<vector<long long int> > result = merge(matrix, n, &count);

    cout << count << endl;

    
    return 0;
}
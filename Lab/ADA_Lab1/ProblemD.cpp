#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool sloppyshuffle(string s1, string s2){

    //if the strings are equal, return true
    //base case
    if(s1==s2){
        return true;
    }
    //if the strings are not equal and the length is 1, return false
    if(s1.length()==1 && s2.length()==1){
        return false;
    }
    if(s1.length()%2==1){
        return false;
    }


    //breaking the string into two halves
    long long int mid = floor(s1.length()/2);
    string s1left = s1.substr(0, mid);
    string s1right = s1.substr(mid, s1.length()-mid);
    string s2left = s2.substr(0, mid);
    string s2right = s2.substr(mid, s2.length()-mid);

    return (sloppyshuffle(s1left, s2left) && sloppyshuffle(s1right, s2right)) || (sloppyshuffle(s1left, s2right) && sloppyshuffle(s1right, s2left));


}


int main(){

    long long int t;
    cin >> t;
    long long int n;
    

    vector <bool> result;

    while(t--){
        
        cin >> n;
        string s1; string s2;
        cin >> s1; cin >> s2;
        bool a = false;

        
        //checking if the strings are equal length
        if(s1.length()!=s2.length()){
            a = false;
        }
        else if(s1.length()!=n){
            a = false;
        }
        else{a = sloppyshuffle(s1, s2);}
        result.push_back(a);
        // cout << s1 << endl;
        // cout << s2 << endl;
    }
    

    for(long long int i=0;i<result.size();i++){
        if(result[i]){cout << "YES" << endl;}
        else{cout << "NO" << endl;}
    }


    return 0;
}
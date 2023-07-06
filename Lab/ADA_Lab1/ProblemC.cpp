#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Node{
    public:
    int data;
    string s;
};


bool sloppyshufflecheck(string s1, string s2){

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

    return (sloppyshufflecheck(s1left, s2left) && sloppyshufflecheck(s1right, s2right)) || (sloppyshufflecheck(s1left, s2right) && sloppyshufflecheck(s1right, s2left));


}


Node sloppyshuffle(string s1, string s2){

    Node n;

    if(sloppyshufflecheck(s1, s2)==true){
        n.data = 0;
        n.s = s2;
        //cout<<"Here"<<endl;
        return n;
    }

    if(s1.size()%2==1){
        
        if(s1==s2){
            n.data = 0;
            n.s = s2;
            return n;
        }
        else{
            
            int count = 0;
            for(int i=0; i<s1.length(); i++){
                if(s1[i]!=s2[i]){
                    if(s2[i]=='0'){
                        s2[i] = '1';
                    }
                    else{
                        s2[i] = '0';
                    }
                    count++;
                }
            }

            n.data = count;
            n.s = s2;
            return n;
        }
    } 



    //breaking the string into two halves
    long long int mid = floor(s1.length()/2);
    string s1left = s1.substr(0, mid);
    string s1right = s1.substr(mid, s1.length()-mid);
    string s2left = s2.substr(0, mid);
    string s2right = s2.substr(mid, s2.length()-mid);

    class Node a = sloppyshuffle(s1left, s2left);
    class Node b = sloppyshuffle(s1right, s2right);
    class Node c = sloppyshuffle(s1left, s2right);
    class Node d = sloppyshuffle(s1right, s2left);

    //class Node n;
    if(a.data+b.data<=c.data+d.data){
        //construcing the required string
        n.data = a.data+b.data;
        n.s = a.s+b.s;
        return n;
    }
    else{
        n.data = c.data+d.data;
        n.s = d.s+c.s;
        return n;
    }


}


int main(){

    long long int t;
    cin >> t;
    long long int n;
    

    vector <int> result;
    vector<string> strings;

    while(t--){
        
        cin >> n;
        string s1; string s2;
        cin >> s1; cin >> s2;
        int a; string b;
        class Node node;


        node = sloppyshuffle(s1, s2);
        result.push_back(node.data);
        strings.push_back(node.s);

        // cout << s1 << endl;
        // cout << s2 << endl;
    }

    for(long long int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
        cout<<strings[i]<<endl;
    }


    return 0;
}
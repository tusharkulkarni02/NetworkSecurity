#include <bits/stdc++.h>
using namespace std;

string user;
string pass;

string def_user = "admin";
string def_pass = "admin";

int main(){
    cout<<"Enter your username: \n";
    cin>>user;
    cout<<"Enter you default password \n";
    cin>>pass;
    if (pass == def_pass && user == def_user){
        cout<<"Login successfull!!";
    }
    else{
        cout<<"Wrong credentials!";
    }
	
    return 0;
}

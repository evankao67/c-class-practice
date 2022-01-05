#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <cstdio>
using namespace std;
int DFS(int,int);
string s;
int main(){ 
    cin>>s;
    int result=DFS(0,s.size()-1);
    cout<<result<<'\n';  
  
}
int DFS(int le,int ri){
  int c=0;
  for(int i=ri;i>=le;i--){  
    if (s[i]==')') c++;        
    if (s[i]=='(') c--;
    if (s[i]=='+' && c==0){ 
      return DFS(le,i-1)+DFS(i+1,ri);
    }
    if (s[i]=='-' && c==0){
      return DFS(le,i-1)-DFS(i+1,ri);
    }  
  }    
  for(int i=ri;i>=le;i--){   
    if (s[i]==')') c++;          
    if (s[i]=='(') c--;
    if (s[i]=='*' && c==0){ 
      return DFS(le,i-1)*DFS(i+1,ri);
    }
    if (s[i]=='/' && c==0){
      return DFS(le,i-1)/DFS(i+1,ri);
    }         
  }    
  if ((s[le]=='(')&&(s[ri]==')')) return DFS(le+1,ri-1);  
  int num=0;
  for(int i=le;i<=ri;i++) num=num*10+s[i]-'0';
  return num;
}

#include<iostream>
#include<string>
using namespace std;
char map[30][30];
bool flag = false;
bool visited[30][30];
void P(int i,int j){
    if(visited[i][j]){
        return ;
    }
    if(i<30&&j<30){
        if(map[i+1][j]=='o'||map[i][j+1]=='o'){
            flag = true;
        }
        else {
            if(map[i+1][j]=='x'){
             P(i+1,j);
             visited[i+1][j] = true;
            }
            if(map[i][j+1]=='x'){
             P(i,j+1);
             visited[i][j+1] = true;
            }
        }
    }
    }
int main(){
    int A,B;
    int a,b;
    cin>>A>>B;
    for(a=0;a<A;a++){
        for(b=0;b<B;b++){
            cin>>map[a][b];
        }
    }
    
    P(1,1);
    if(flag==true){
        cout<<"True";
    }
    else if(flag==false){
        cout<<"False";
    }
    return 0;
}
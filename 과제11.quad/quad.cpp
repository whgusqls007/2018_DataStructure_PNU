#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vec;
ofstream out("quad.out");

int recurse(int x1, int y1, int x2, int y2){
    int temp1 = vec[x1][y1], temp2;
    bool breakpoint = false;
    for(int i=x1;i<x2;i++){
        for(int j=y1;j<y2;j++){
            temp2 = vec[i][j];
            if(temp1!=temp2){
                breakpoint = true;
                break;
            }
        }
        if(breakpoint==true)
            break;
    }
    if(temp1==1&&breakpoint==false){
        out << "1" << " ";
    }
    else if(temp1==0&&breakpoint==false){
        out << "0" << " ";
    }
    else if(breakpoint==true){
        out << "2 ";
        out << '(' << " ";
        recurse(x1,(y1+y2)/2,(x1+x2)/2,y2);
        recurse(x1,y1,(x1+x2)/2,(y1+y2)/2);
        recurse((x1+x2)/2,y1,x2,(y1+y2)/2);
        recurse((x1+x2)/2,(y1+y2)/2,x2,y2);
        out << ')' << " ";
    }

}
int main(){
    ifstream in("quad.inp");
    int N;
    in >> N;
    for(int i=0;i<pow(2,N);i++){
        vector<int> Vtemp;
        string Stemp;
        in >> Stemp;
        for(int j=0;j<Stemp.size();j++){
            if(Stemp[j]=='#')
                Vtemp.push_back(1);
            else if(Stemp[j]=='_')
                Vtemp.push_back(0);
        }
        vec.push_back(Vtemp);
    }
    in.close();
    recurse(0,0,pow(2,N),pow(2,N));
}

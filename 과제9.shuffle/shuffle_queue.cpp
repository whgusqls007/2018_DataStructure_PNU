//201424542
//Á¶Çöºó
#include <bits/stdc++.h>
using namespace std;
typedef queue<int> Q;

int main(){
    ifstream input("3.inp");
    int N, K;
    input >> N >> K;
    Q q;
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    for(int i=0;i<K;i++){
        string s;
        input >> s;
        if(s=="Shuffle"){
            Q t1, t2;
            int counter = 0;
            while(counter!=N/2){
                t1.push(q.front());
                q.pop();
                counter++;
            }
            while(counter!=N){
                t2.push(q.front());
                q.pop();
                counter++;
            }
            while(!t1.empty()){
                q.push(t1.front());
                q.push(t2.front());
                t1.pop(); t2.pop();
            }
        }
        else if(s=="Cut"){
            Q t1, t2;
            int a, b;
            input >> a >> b;
            int counter = 1;
            while(!q.empty()){
                if(counter>=a && counter <= b)
                    t2.push(q.front());
                else
                    t1.push(q.front());
                q.pop();
                counter++;
            }
            while(!t1.empty()){
                q.push(t1.front());
                t1.pop();
            }
            while(!t2.empty()){
                q.push(t2.front());
                t2.pop();
            }
        }
    }
    int counter = 1;
    while(!q.empty()){
        if(counter == 1 || counter == N/2 || counter == N){
            cout << q.front() << " ";
        }
        q.pop();
        counter++;
    }
}

//201424542
//Á¶Çöºó
#include <bits/stdc++.h>
using namespace std;

typedef list<int> List;
void makecard(List &L, int N);
void shuffle(List &L, int N);
void cut(List &L, int a, int b);

int main(){
    ifstream input("shuffle.inp");
    int N, K;
    List L;
    input >> N >> K;
    makecard(L, N);
    for(int i=0;i<K;i++){
        string s;
        input >> s;
        if (s=="Shuffle"){
            shuffle(L, N);
        }
        else if(s=="Cut"){
            int a, b;
            input >> a >> b;
            cut(L, a, b);
        }
    }
    input.close();
    auto it = L.begin();
    advance(it, N/2-1);
    ofstream output("shuffle.out");
    output << L.front() << " " << *it << " " <<L.back() << endl;
    output.close();
}

void makecard(List &L, int N){
    for(int i=0;i<N;i++){
        L.push_back(i+1);
    }
}

void shuffle(List &L, int N){
    auto it = L.begin();
    for(int i=0;i<N;i++){
        if(i%2==0){
            L.push_back(*it);
        }
        else if(i%2==1){
            advance(it, N/2);
            L.push_back(*it);
            advance(it, -(N/2));
            it++;
        }
    }
    it = L.begin();
    advance(it, N);
    L.erase(L.begin(), it);
}

void cut(List &L, int a, int b){
    auto start = L.begin();
    auto finish = L.begin();
    advance(start, a-1);
    advance(finish, b);
    L.splice(L.end(), L, start, finish);
}


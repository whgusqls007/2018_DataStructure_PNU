#include <bits/stdc++.h>

using namespace std;

typedef forward_list<int> List;
void makeset(List &L, int a, int b);
void zosep(List &L);

int main(){
    List L;
    int a, b;
    cin >> a >> b;
    auto it = L.before_begin();
    for(int i=a;i<=b;i++){
        it = L.emplace_after(it, i);
    }
    int temp;
    it = L.before_begin();
    int c = *L.begin();
    for(int i=0;i<b-a;i++){
        c = (*it)%3+1;

    }
}

#include <bits/stdc++.h>
#include <time.h>

using namespace std;

typedef list<int> List;
void makelist(List &L, int a, int b);
void josep(List &L);

int main()
{
    clock_t start1, start2, end1, end2;
    float res1, res2;
    ifstream input("1.inp");
    List L;
    int a, b;
    cin >> a >> b;
    input.close();
    start1 = clock();
    makelist(L, a, b);
    end2 = clock();
    res2 = (float)(end2 - start1)/CLOCKS_PER_SEC;
    cout << res2 << endl;
    josep(L);
    ofstream output("i.out");
    auto it = L.begin();
    cout << *it << endl;
    output.close();
    end1 = clock();
    res1 = (float)(end1 - start1)/CLOCKS_PER_SEC;
    cout << res1 << endl;
}
void makelist(List &L, int a, int b){
    for(int i=a;i<=b;i++){
        L.push_back(i);
    }
    /*int temp = a;
    while(temp != b-a-1){
        L.push_back(temp);
        temp++;
    }*/
}
void josep(List &L){
    auto it = L.begin();
    while(L.size()!=1){
        int c;
        c = (*it)%3+2;
        if(it == --(L.end())){
            L.erase(it);
            it = L.begin();
        }
        else
            it = L.erase(it);
        for(int i=1;i<c;i++){
            if(*(it) == *(--(L.end())))
                it = L.begin();
            else
                it++;
        }
    }
}

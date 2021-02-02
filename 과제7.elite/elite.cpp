#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> Tuple;
typedef vector<tuple<int, int, int>> Vector;
typedef stack<tuple<int, int, int>> Stack;

bool Compare(const Tuple &a, const Tuple &b);
void Output(Vector a);

class elite{
public:
    int N, c, h, index;
    Tuple tup;
    Vector vec;
    Stack stk;
    int Vec_to_Stk(Stack &a, Vector &b);
    int Stk_to_Vec(Stack &a, Vector &b);
};

int main()
{
    ifstream input("2.inp");
    elite E;
    input >> E.N;
    for(int i=0; i<E.N; i++){
        E.index = i;
        input >> E.c >> E.h;
        E.tup = make_tuple(E.c, E.h, E.index);
        E.vec.push_back(E.tup);
    }
    sort(E.vec.begin(),E.vec.end());
    E.Vec_to_Stk(E.stk, E.vec);
    E.vec.clear();
    E.Stk_to_Vec(E.stk, E.vec);
    sort(E.vec.begin(),E.vec.end(),Compare);
    Output(E.vec);
    input.close();
}

bool Compare(const Tuple &a, const Tuple &b){
    return (get<2>(a) < get<2>(b));
}

void Output(Vector a){
    ofstream output("2.out");
    for(int i=0;i<a.size();i++){
        output << get<2>(a[i]) + 1 << endl;
    }
    output.close();
}

int elite::Vec_to_Stk(Stack &a, Vector &b){
    for(int i=0;i<b.size();i++){
        if(i==0)
            a.push(b[i]);
        else{
            if(get<1>(a.top()) < get<1>(b[i])){
                if(get<0>(a.top()) != get<0>(b[i])){
                    while(!a.empty() && get<1>(a.top()) < get<1>(b[i])){
                        a.pop();
                    }
                    a.push(b[i]);
                }
                else
                    a.push(b[i]);
            }
            else
                a.push(b[i]);
        }
    }
}

int elite::Stk_to_Vec(Stack &a, Vector &b){
    while(!a.empty()){
        auto s = a.top();
        tie(elite::c, elite::h, elite::index) = s;
        b.push_back(s);
        a.pop();
    }
}

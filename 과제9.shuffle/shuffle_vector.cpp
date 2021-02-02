#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Vec;

void makecard(Vec &vec1, int N);
void shuffle(Vec &vec1, int N);
void cut(Vec &vec1, int a, int b);

int main()
{
    ifstream input("3.inp");
    Vec vec1;
    int N, K;
    input >> N >> K;
    makecard(vec1, N);
    for(int i=0;i<K;i++){
        string CS;
        input >> CS;
        if(CS == "Shuffle"){
            shuffle(vec1, N);
        }
        else if(CS == "Cut"){
            int a,b;
            input >> a >> b;
            cut(vec1, a, b);
        }
    }
    input.close();
    ofstream output("shuffle.out");
    cout << vec1[0] << " " << vec1[(N/2)-1] << " " << vec1[N-1] << endl;
    output.close();
}

void makecard(Vec &vec1, int N){
    for(int i=0;i<N;i++){
        vec1.push_back(i+1);
    }
}

void shuffle(Vec &vec1, int N){
    for(int i=0;i<N/2;i++){
        vec1.push_back(vec1[i]);
        vec1.push_back(vec1[N/2+i]);
    }
    vec1.erase(vec1.begin(), vec1.begin()+N);
}

void cut(Vec &vec1, int a, int b){
    for(int i=a;i<=b;i++){
        vec1.push_back(vec1[i-1]);
    }
    vec1.erase(vec1.begin()+a-1, vec1.begin()+b);
}

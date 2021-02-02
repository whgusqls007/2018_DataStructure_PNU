#include <bits/stdc++.h>

using namespace std;
int num_of_fx, num_of_term, counter = 0;
long long int coe, dgr;
array<long long int, 1001> Arr1 ={0};
array<long long int, 1001> Arr2 ={0};// 전역 변수 설정
void Fin();
void Fout(); // 함수 prototype

int main(){
    Fin();
    Fout();
}
void Fin(){
    ifstream input("1.inp");
    input >> num_of_fx;
    for(int i=0;i<num_of_fx;i++){
        input >> num_of_term;
        for(int j=0;j<num_of_term;j++){
            input >> coe >> dgr;
            if(i==0){
                Arr1[dgr] = Arr1[dgr] + coe;
            }
            else{
                for(int k=0;k<Arr1.size();k++){
                    if(Arr1[k]!=0){
                        Arr2[k + dgr] = Arr2[k + dgr] + (Arr1[k] * coe);
                    }
                }
            }
        }
        if(i!=0){
            Arr1.swap(Arr2);
            Arr2.fill(0);
        }
    }
    input.close();
}
void Fout(){
    ofstream output("1.out");
    for(int i=0;i<Arr1.size();i++){
        if (Arr1[i]!=0){
            counter++;
        }
    }
    output << counter << endl;
    for(int i=Arr1.size()-1;i>=0;--i){
        if (Arr1[i]!=0){
            output <<Arr1[i] << " " << i << endl;
        }
    }
    output.close();
}

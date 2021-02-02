#include <iostream>
#include <fstream> // ���� ����� �������
#include <array> // ��� �ش�����
typedef long long int LL;
using namespace std;
int num_of_fx, num_of_term, counter = 0;
LL coe, dgr;
array<LL, 10001> Arr1 ={0};
array<LL, 10001> Arr2 ={0};// ���� ���� ����
void Fin();
void Fout(); // �Լ� prototype

int main(){
    Fin();
    Fout();
}
void Fin(){
    ifstream input("2.inp");
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
    ofstream output("2.out");
    for(int i=0;i<Arr1.size();i++){
        if (Arr1[i]!=0){
            counter++;
        }
    }
    output << counter << endl;
    if(counter == 0){
        output << 0 << " " << 0 << endl;
    }
    for(int i=Arr1.size()-1;i>=0;--i){
        if (Arr1[i]!=0){
            output <<Arr1[i] << " " << i << endl;
        }
    }
    output.close();
}

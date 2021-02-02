#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input("3.inp");
    array<long int, 1001> Arr1 ={0};
    array<long int, 1001> Arr2 ={0};
    int num_of_fx, num_of_term, coe, dgr, temp, counter = 0;
    input >> num_of_fx;
    for(int i=0;i<num_of_fx;i++){
        input >> num_of_term;
        for(int j=0;j<num_of_term;j++){
            input >> coe >> dgr;
            if(i==0){
                Arr1[dgr] = Arr1[dgr] + coe;
            }
            else if(i!=0){
                for(long int k=0;k<Arr1.size();k++){
                    if(Arr1[k]!=0){
                        Arr2[k + dgr] = Arr2[k + dgr] + (Arr1[k] * coe);
                    }
                }
            }
        }
        if(i!=0){
            Arr1 = Arr2;
            Arr2.fill(0);
        }
    }
    input.close();

    ofstream output("3.out");
    for(long int i=0;i<Arr1.size()-1;i++){
        if (Arr1[i]!=0){
            counter++;
        }
    }
    output << counter << endl;
    for(long int i=Arr1.size()-1;i>-1;i--){
        if (Arr1[i]!=0){
            output <<Arr1.at(i) << " " << i << endl;
        }
    }
    output.close();
    return 0;
}

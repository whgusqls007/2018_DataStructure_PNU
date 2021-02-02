//201424542
//  조현빈
#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream input("polyadd.inp");
    ofstream output("polyadd.out");
    int arr[1001] = {0, };
    int num_of_fx;
    input >> num_of_fx;
    int num_of_term, coe, dgr;
    int temp = 0;
    for (int i=0;i<num_of_fx;i++){
        input >> num_of_term;
        for(int j=0;j<num_of_term;j++){
            input >> coe >> dgr;
            if(temp < dgr){
                temp = dgr;
            }
            arr[dgr] = arr[dgr] + coe;
        }
    }
    int counter = 0;
    for(int i=temp;i>-1;i--){
        if(arr[i]!=0){
            counter++;
        }
    }
    output << counter << endl;
    if (counter == 0){
        output << "0 0" <<endl;
    }
    else{
        for(int i=temp;i>-1;i--){
            if(arr[i]!=0){
                output << arr[i] << " " << i << endl;
            }
        }
    }
    input.close();
    output.close();
}

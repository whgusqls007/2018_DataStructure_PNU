//201424542
//Á¶Çöºó
#include <iostream>
#include <fstream>
//#include <vector>
#include <array>
#include <time.h>
using namespace std;

int a, b, counter, counter2, index;
int arr[5000000];

int main(){
    clock_t start, end;
    start = clock();
    ifstream in("1.inp");
    in >> a >> b;
    in.close();
    index = a;
    do{
        arr[index] = 1;
        for(int i=index%3+2;i>0;arr[index]==0?i--:i){
            index++;
            if(index==b+1)
                index = a;
        }
        counter++;
    }while(counter!=b-a);
    //ofstream out("zosep.out");
    cout << index << endl;
    //out.close();
    end = clock();
    float time = (float)(end-start)/CLOCKS_PER_SEC;
    cout << time << endl;
}

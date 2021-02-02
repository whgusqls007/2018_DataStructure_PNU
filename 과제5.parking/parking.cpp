#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//shrink_to_fit()

int main()
{
    ifstream input("3.inp");
    ofstream output("3.out");
    int K, N, car, counter = 0;
    input >> K >> N;
    vector<int> park_z;
    vector<int> temp;
    park_z.reserve(K);
    for(int i=0;i<N;i++){
        bool a = false;
        input >> car;
        if(i==0){
            park_z.push_back(car);
        }
        else{
            if(car>0){
                for(int j=0;j<park_z.size();j++){
                    if(park_z[j]==-1){
                        park_z[j]=car;
                        break;
                    }
                }
                for(int j=0;j<park_z.size();j++){
                    if(park_z[j]==car){
                        a = true;
                        break;
                    }
                }
                if(a==false){
                    park_z.push_back(car);
                }
            }
            else if(car<0){
                for(int j=0;j<park_z.size();j++){
                    if(park_z[j] == abs(car)){
                        park_z[j] = -1;
                        break;
                    }
                }
            }
            for(int j=0;j<park_z.size();j++){
                if(park_z[j]!=-1){
                    counter++;
                }
            }
            if(park_z.capacity()/3 == counter){
                if(park_z.capacity()/2 >= K){
                    temp.swap(park_z);
                    park_z.resize(0);
                    park_z.shrink_to_fit();
                    park_z.reserve(temp.capacity()/2);
                    for(int j=0;j<temp.size();j++){
                        if(temp[j]!=-1){
                            park_z.push_back(temp[j]);
                        }
                    }
                }
                else if(park_z.capacity()/2 < K){
                    temp.swap(park_z);
                    park_z.resize(0);
                    park_z.shrink_to_fit();
                    park_z.reserve(K);
                    for(int j=0;j<temp.size();j++){
                        if(temp[j]!=-1){
                            park_z.push_back(temp[j]);
                        }
                    }
                }
            }
        }
        counter = 0;
    }
    for(int i=0;i<park_z.size();i++){
        if(park_z[i]!=0 && park_z[i]!=-1)
            output << i+1 << " " << park_z.at(i) << endl;
    }
}

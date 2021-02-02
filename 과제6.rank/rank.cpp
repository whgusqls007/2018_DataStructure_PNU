#include <bits/stdc++.h>
using namespace std;
//typedef struct { string name ;  vector<int> report; }  Stud ;
struct Stud{
    string name;
    vector<int> report;
};

bool myfun ( Stud a, Stud b)   {
    if (a.report.size()==b.report.size()){
        if(*(a.report.end()-1)==*(b.report.end()-1)){
            auto aIterator = a.report.begin();
            auto bIterator = b.report.begin();
            while(*aIterator==*bIterator) {
                aIterator++;
                bIterator++;
                if(aIterator==a.report.end() && bIterator==b.report.end())
                    return a.name < b.name;
            }
            return *(aIterator)>*(bIterator);
        }
        else
            return(*(a.report.end()-1)>*(b.report.end()-1));
    }
    else
        return (a.report.size()>b.report.size()) ;
}
void outclass( vector < Stud > Pclass ){
    ofstream output("2.out");
    for(auto s : Pclass) {
        output << s.name << endl;
    }
    output.close();
}

int main() {

    int i, N, score ;
    string xname ;
    Stud   body ;
    vector < Stud > Pclass ;
    ifstream in("2.inp");
    in >> N ;
    for(i=0 ; i < N ; i++){
        int sum = 0;
        in >> xname ;
        body.name = xname ;
        body.report.clear();
        while(1){
            in >> score ;
            sum = sum + score;
            if( score <= 0) break ;
            else {
                body.report.push_back( score ) ;
            }
        }
        sort( body.report.begin(),  body.report.end() ) ;
        body.report.push_back( sum );
        Pclass.push_back( body );
    }
    sort( Pclass.begin(), Pclass.end(), myfun) ;
    outclass( Pclass ) ;
}

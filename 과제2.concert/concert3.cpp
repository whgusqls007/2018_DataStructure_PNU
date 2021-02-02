#include <bits/stdc++.h>

using namespace std;
int M, N, stage_row, stage_col, t_row, t_col, s_row, s_col, counter;
vector <tuple<double, double, double, double, double> > Concert, Concert_copy;
vector <int> Stage_row, Stage_col, Toilet_row, Toilet_col, Seat_row, Seat_col;
ifstream input("1.inp");
ofstream output("1.out");
int stage(int stage_row, int stage_col){
    input >> stage_row >> stage_col;
    Stage_row.push_back(stage_row-1);
    Stage_col.push_back(stage_col-1);
}

int toilet(int t_row, int t_col){
    for(int i=0;i<4;i++){
        int row, col;
        input >> row >> col;
        Toilet_row.push_back(row-1);
        Toilet_col.push_back(col-1);
    }
}

int seat(int s_row, int s_col){
    for(int i=0;i<3;i++){
        int row, col;
        input >> row >> col;
        Seat_row.push_back(row-1);
        Seat_col.push_back(col-1);
    }
}

int dist(int N, int M){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            double dist_s, dist_t1, dist_t2, dist_t3, dist_t4;
            double stage, t1, t2, t3, t4;
            dist_s = sqrt(pow(Stage_row[0]-i, 2)+(pow(Stage_col[0]-j,2)));
            dist_t1 = sqrt(pow(Toilet_row[0]-i, 2)+(pow(Toilet_col[0]-j,2)));
            dist_t2 = sqrt(pow(Toilet_row[1]-i, 2)+(pow(Toilet_col[1]-j,2)));
            dist_t3 = sqrt(pow(Toilet_row[2]-i, 2)+(pow(Toilet_col[2]-j,2)));
            dist_t4 = sqrt(pow(Toilet_row[3]-i, 2)+(pow(Toilet_col[3]-j,2)));
            if (dist_s == 0 || dist_t1 == 0 || dist_t2 == 0 || dist_t3 == 0 || dist_t4 == 0){
                dist_s = 100;
                dist_t1 = 100;
                dist_t2 = 100;
                dist_t3 = 100;
                dist_t4 = 100;
            }
            Concert.push_back(make_tuple(dist_s, dist_t1, dist_t2, dist_t3, dist_t4));
            Concert_copy.push_back(make_tuple(dist_s, dist_t1, dist_t2, dist_t3, dist_t4));
        }
    }
}

int priority(int counter){
    for(int i=0;i<3;i++){
        counter = 0;
        int index = (Seat_row[i]*M)+Seat_col[i];
        for (int j=0;j<Concert_copy.size();j++){
            counter++;
            if(Concert[index]==Concert_copy[j]){
                output << counter << " ";
            }
        }
    }
}

int main(){
    input >> N >> M;
    stage(stage_row, stage_col);
    toilet(t_row, t_col);
    seat(s_row, s_col);
    dist (N, M);
    sort(Concert_copy.begin(),Concert_copy.end());
    priority(counter);
    cout << endl;
    input.close();
    output.close();
}


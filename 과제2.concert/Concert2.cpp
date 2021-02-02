#include <bits/stdc++.h>

using namespace std;

int main(){
    int M, N;
    cin >> N >> M;
    vector <vector <double>> Concert;
    int Stage_row, Stage_col;
    cin >> Stage_row >> Stage_col;
    vector <int> Toilet_row, Toilet_col;
    for (int i=0;i<4;i++){
        int t_row, t_col;
        cin >> t_row >> t_col;
        Toilet_row.push_back(t_row);
        Toilet_col.push_back(t_col);
        //cout << Toilet_row.at(i) << " ";
        //cout << Toilet_col.at(i) << " ";
    }
    vector <int> Seat_row, Seat_col;
    for (int i=0;i<3;i++){
        int s_row, s_col;
        cin >> s_row >> s_col;
        Seat_row.push_back(s_row);
        Seat_col.push_back(s_col);
        //cout << Seat_row.at(i) << " ";
        //cout << Seat_col.at(i) << " ";
    }
    for(int i=0;i<M;i++){

        for(int j=0;j<N;j++){
            vector<double> dist_all_seat;
            double dist_seat, dist_t1, dist_t2, dist_t3, dist_t4;
            dist_seat = sqrt(pow(Stage_row-(j+1),2)+pow(Stage_col-(M-1),2));
            dist_t1 = sqrt(pow((Toilet_row[0]-(j+1)),2)+pow((Toilet_col[0]-(M-1)),2));
            dist_t2 = sqrt(pow((Toilet_row[1]-(j+1)),2)+pow((Toilet_col[1]-(M-1)),2));
            dist_t3 = sqrt(pow((Toilet_row[2]-(j+1)),2)+pow((Toilet_col[2]-(M-1)),2));
            dist_t4 = sqrt(pow((Toilet_row[3]-(j+1)),2)+pow((Toilet_col[3]-(M-1)),2));
            if(dist_seat==(double)0 || dist_t1==(double)0 || dist_t2==(double)0 || dist_t3==(double)0 || dist_t4==(double)0) {
                dist_seat = pow(M,2)+pow(N,2);
                dist_t1 = pow(M,2)+pow(N,2);
                dist_t2 = pow(M,2)+pow(N,2);
                dist_t3 = pow(M,2)+pow(N,2);
                dist_t4= pow(M,2)+pow(N,2);
            }
            dist_all_seat.push_back(dist_seat);
            dist_all_seat.push_back(dist_t1);
            dist_all_seat.push_back(dist_t2);
            dist_all_seat.push_back(dist_t3);
            dist_all_seat.push_back(dist_t4);
            Concert.push_back(dist_all_seat);
        }
    }
    vector <vector <double>> Concert_copy(Concert);
    sort(Concert_copy.begin(), Concert_copy.end());
    for(int i=0; i<5; ++i)
    {
        Concert_copy.pop_back();
    }
    for (int i = 0;i<3;++i){
        int x = M-Seat_col[i];
        int y = Seat_row[i]-1;
        int a = N*x+y;
        int b = 0;
        for (int j=0;j<Concert_copy.size();j++){
            b++;
            if(Concert[a]==Concert_copy[j])
                cout << b << endl;
        }

    }
}

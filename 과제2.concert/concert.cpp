#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void)
{
    int i;
    int concert_row, concert_col;
    int stage_row, stage_col;
    int toilet_row, toilet_col;
    int seat_row, seat_col;
    float stage, toilet_1, toilet_2, toilet_3, toilet_4;
    cin >> concert_row >> concert_col;
    vector<int> Concert_row, Concert_col;
    Concert_row.push_back(concert_row);
    Concert_col.push_back(concert_col);
    cin >> stage_row >> stage_col;
    vector<int> Toilet_row, Toilet_col;
    vector<int> Seat_row, Seat_col;
    vector<float> distance_from_stage;
    vector<float> distance_from_toilet_1;
    vector<float> distance_from_toilet_2;
    vector<float> distance_from_toilet_3;
    vector<float> distance_from_toilet_4;
    vector<float> the_best_seat;
    vector<float> second_best_seat;
    vector<float> third_best_seat;

    for (i = 0; i < 4; ++i)
    {
        cin >> toilet_row >> toilet_col;
        Toilet_row.push_back(toilet_row);
        Toilet_col.push_back(toilet_col);
    }
    for (i = 0; i < 3; ++i)
    {
        cin >> seat_row >> seat_col;
        Seat_row.push_back(seat_row);
        Seat_col.push_back(seat_col);
    }
    if (Seat_row[0] <= 0 || Seat_col[0] <= 0 || Seat_row[0] > Concert_row[0] || Seat_col[0] > Concert_col[0])
    {
        cout << "선택하신 첫번째 좌석은 없는 좌석입니다." << endl;
    }
    else if (Seat_row[1] <= 0 || Seat_col[1] <= 0 || Seat_row[1] > Concert_row[0] || Seat_col[1] > Concert_col[0])
    {
        cout << "선택하신 두번째 좌석은 없는 좌석입니다." << endl;
    }
    else if (Seat_row[2] <= 0 || Seat_col[2] <= 0 || Seat_row[2] > Concert_row[0] || Seat_col[2] > Concert_col[0])
    {
        cout << "선택하신 세번째 좌석은 없는 좌석입니다." << endl;
    }
    else
    {

        if ( (Seat_row[0] == Seat_row[1] && Seat_col[0] == Seat_col[1]) || (Seat_row[1] == Seat_row[2] && Seat_col[1] == Seat_col[2]) || (Seat_row[0] == Seat_row[2] && Seat_col[0] == Seat_col[2]) )
        {
            cout << "중복된 좌석을 선택하셨습니다." << endl;
        }
        else
        {
            for (i = 0; i < 3; i++)
            {
                float stage = sqrt ( pow (stage_row - Seat_row[i], 2) + pow (stage_col - Seat_col[i], 2) );
                distance_from_stage.push_back(stage);
                float toilet_1 = sqrt ( pow (Toilet_row[0] - Seat_row[i], 2) + pow (Toilet_col[0] - Seat_col[i], 2) );
                distance_from_toilet_1.push_back(toilet_1);
                float toilet_2 = sqrt ( pow (Toilet_row[1] - Seat_row[i], 2) + pow (Toilet_col[1] - Seat_col[i], 2) );
                distance_from_toilet_2.push_back(toilet_2);
                float toilet_3 = sqrt ( pow (Toilet_row[2] - Seat_row[i], 2) + pow (Toilet_col[2] - Seat_col[i], 2) );
                distance_from_toilet_3.push_back(toilet_3);
                float toilet_4 = sqrt ( pow (Toilet_row[3] - Seat_row[i], 2) + pow (Toilet_col[3] - Seat_col[i], 2) );
                distance_from_toilet_4.push_back(toilet_4);
                if (i == 0)
                {
                    the_best_seat.push_back(distance_from_stage[0]);
                    the_best_seat.push_back(distance_from_toilet_1[0]);
                    the_best_seat.push_back(distance_from_toilet_2[0]);
                    the_best_seat.push_back(distance_from_toilet_3[0]);
                    the_best_seat.push_back(distance_from_toilet_4[0]);
                }
                else if (i == 1)
                {
                    second_best_seat.push_back(distance_from_stage[1]);
                    second_best_seat.push_back(distance_from_toilet_1[1]);
                    second_best_seat.push_back(distance_from_toilet_2[1]);
                    second_best_seat.push_back(distance_from_toilet_3[1]);
                    second_best_seat.push_back(distance_from_toilet_4[1]);
                }
                else
                {
                    third_best_seat.push_back(distance_from_stage[2]);
                    third_best_seat.push_back(distance_from_toilet_1[2]);
                    third_best_seat.push_back(distance_from_toilet_2[2]);
                    third_best_seat.push_back(distance_from_toilet_3[2]);
                    third_best_seat.push_back(distance_from_toilet_4[2]);
                }
            }

            if (the_best_seat < second_best_seat && second_best_seat < third_best_seat)
            {
                cout << "The best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
                cout << "Second best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                cout << "Third best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
            }
            else if (the_best_seat < second_best_seat && second_best_seat > third_best_seat)
            {
                if (the_best_seat < third_best_seat)
                {
                    cout << "The best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
                    cout << "Second best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
                    cout << "Third best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                }
                else
                {
                    cout << "The best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
                    cout << "Second best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
                    cout << "Third best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                }
            }
            else if (the_best_seat > second_best_seat && second_best_seat < third_best_seat)
            {
                if (the_best_seat < third_best_seat)
                {
                    cout << "The best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                    cout << "Second best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
                    cout << "Third best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
                }
                else
                {
                    cout << "The best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                    cout << "Second best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
                    cout << "Third best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
                }
            }
            else if (the_best_seat > second_best_seat && second_best_seat > third_best_seat)
            {
                cout << "The best seat is " << Seat_row[2] << "," << Seat_col[2] << endl;
                cout << "Second best seat is " << Seat_row[1] << "," << Seat_col[1] << endl;
                cout << "Third best seat is " << Seat_row[0] << "," << Seat_col[0] << endl;
            }
        }
    }
}

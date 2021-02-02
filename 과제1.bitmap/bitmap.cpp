#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input ("bitmap.inp");
    ofstream output ("bitmap.out");
    long long bmap[64];
    long long tmap[64];
    int i, j;
    bitset<64> bit_bmap[64];
    bitset<64> bit_tmap[64];
    bitset<64> temp[64];
    bit_tmap[64].reset();
    for (i = 0; i < 64; i++)
    {

        input >> bmap[i];
        bit_bmap[i] = bmap[i];
        for (j = 0; j < 64; j++)
        {
            temp[i] = (bit_bmap[i] >> (63 - j) ) &= 1;
            bit_tmap[j] = bit_tmap[j] | (temp[i] << (63 - i));
        }
    }

    for (i = 0; i < 64; i++)
    {
        tmap[i] = bit_tmap[i].to_ullong();
        cout << tmap[i] << endl;
        output << tmap[i] << endl;
    }
    input.close();
    output.close();
}

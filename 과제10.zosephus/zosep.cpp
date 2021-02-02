#include<iostream>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;
vector<int> arr;

int main() {
	clock_t start, end;
	start = clock();
	ifstream in("1.inp");
	int a, b, index;
	in >> a >> b;
	/*
	int counter_1 = 0;
	if (index % 3 + 2 == 3) {
		while (index + 3 < b) {
			arr[index] = 1;
			index += 3;
			counter_1++;
		}
	}
	else if (index % 3 + 2 == 2) {
		while (index + 2 < b && index + 4 < b) {
			if (counter_1 & 1) {
				arr[index] = 1;
				index += 4;
				counter_1++;
			}
			else {
				arr[index] = 1;
				index += 2;
				counter_1++;
			}
		}
	}
	else if (index % 3 + 2 == 4) {
		while (index + 2 < b && index + 4 < b) {
			if (counter_1 & 1) {
				arr[index] = 1;
				index += 2;
				counter_1++;
			}
			else {
				arr[index] = 1;
				index += 4;
				counter_1++;
			}
		}
	}
	do {
		arr[index] = 1;
        for (i = index % 3 + 2; i != 0; arr[index] == 0 ? i-- : i) {
            index++;
            if (index == b + 1) {
                index = a;
            }
        }
		counter_1++;
	} while (counter_1 != b - a);
	ofstream out("zosep.out");
	cout << index << endl;
	end = clock();
	float time = (float)(end - start) / CLOCKS_PER_SEC;
	cout << time << endl;
	*/
}

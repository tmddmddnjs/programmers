#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int map[4][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{11,0,12}
};

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int leftHand = 11, rightHand = 12;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L";
			leftHand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R";
			rightHand = numbers[i];
		}
		else {
			int lj = 0, lk = 0, rj = 0, rk = 0;
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					if (leftHand == map[j][k]) {
						lj = j; lk = k;
					}
					if (rightHand == map[j][k]) {
						rj = j; rk = k;
					}
				}
			}
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					if (numbers[i] == map[j][k]) {
						int e = 0, f = 0;
						e = j; f = k;
						int l = abs(lj - e) + abs(lk - f);
						int r = abs(rj - e) + abs(rk - f);
						if (l > r) {
							answer += "R";
							rightHand = numbers[i];
						}
						else if (l < r) {
							answer += "L";
							leftHand = numbers[i];
						}
						else {
							if (hand == "right") {
								answer += "R";
								rightHand = numbers[i];
							}
							else {
								answer += "L";
								leftHand = numbers[i];
							}
						}
					}
				}
			}
		}
	}
	cout << answer << endl;
	return answer;
}

int main() {
	solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right"); //LRLLLRLLRRL
	solution({ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 }, "left"); //LRLLRRLLLRR
	solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right"); //LLRLLRLLRL
}
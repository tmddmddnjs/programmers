#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int correct = 0, zero = 0;
	sort(lottos.begin(), lottos.end());
	sort(win_nums.begin(), win_nums.end());
	for (int i = 0; i < win_nums.size(); i++) {
		zero = 0;
		for (int j = 0; j < lottos.size(); j++) {
			//같은거 있으면 걸러냄
			if (win_nums[i] == lottos[j]) {
				correct++;
				break;
			}
			else if (lottos[j] == 0) {
				zero++;
			}
		}
	}
	int sum = correct + zero;
	if (sum < 2) {
		answer.push_back(6);
	}
	else {
		answer.push_back(6 - sum + 1);
	}
	if (correct < 2) {
		answer.push_back(6);
	}
	else {
		answer.push_back(6 - (correct)+1);
	}
	return answer;
}

int main() {
	solution({ 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 }); //3, 5
	solution({ 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 }); //1, 6
	solution({ 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 }); //1, 1
	solution({ 0,0,0,0,0,1 }, { 3,3,3,3,3,1 }); //1 6
}
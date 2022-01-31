#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int solution(vector<int> nums) {
	int answer = 0; //count;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				int sum = nums[i] + nums[j] + nums[k];
				//�Ҽ� �Ǻ�
				if (sosu(sum)) {
					answer++;
				}
			}
		}
	}
	cout << answer << endl;
	return answer;
}

int main() {
	solution({ 1,2,3,4 });
	solution({ 1,2,7,6,4 });
}
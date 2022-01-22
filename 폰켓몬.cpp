#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	set<int> set;
	//set으로 중복제거
	for (int i = 0; i < nums.size(); i++) {
		set.insert(nums[i]);
	}
	for (auto a : set) {
		cout << a;
	}
	if (set.size() >= nums.size() / 2) {
		answer = nums.size() / 2;
	}
	else if (set.size() < nums.size() / 2) {
		answer = set.size();
	}
	cout << ' ' << answer << endl;
	return answer;
}

int main() {
	solution({ 3,1,2,3 });//2
	solution({ 3,3,3,2,2,4 });//3
	solution({ 3,3,3,2,2,2 });//2
	solution({ 1,1,1,1,1,1,1,1 });//1
}
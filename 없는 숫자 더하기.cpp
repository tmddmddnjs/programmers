#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;
	for (int i = 0; i < numbers.size(); i++) {
		answer += numbers[i];
	}
	answer = 45 - answer;
	return answer;
}

int main() {
	solution({ 1,2,3,4,6,7,8,0 });//5+9 = 14
	solution({ 5,8,4,0,6,7,9 });//1+2+3=6
}
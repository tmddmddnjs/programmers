#include <stdlib.h>
#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	for (int i = 1; i <= count; i++) {
		answer += (price * i);
	}
	if (money < answer) {
		answer = answer - money;
	}
	else {
		answer = 0;
	}
	cout << answer;
	return answer;
}

int main() {
	solution(3, 20, 4); //10
}
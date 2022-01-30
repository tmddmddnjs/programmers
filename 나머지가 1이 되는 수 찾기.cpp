#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	int x = 2;
	while (true) {
		if ((n % x) == 1) {
			answer = x;
			break;
		}
		x++;
	}
	cout << answer << endl;
	return answer;
}

int main() {
	solution(10);
	solution(12);
}
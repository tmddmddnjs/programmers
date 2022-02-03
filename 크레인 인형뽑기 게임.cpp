#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> temp;
	int tempCount = 0, top = 0;
	for (int k = 0; k < moves.size(); k++) {
		int i = moves[k] - 1;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] == 0) {
				continue;
			}
			else {
				temp.push(board[j][i]);
				board[j][i] = 0;
				top = temp.top();
				temp.pop();
			}
			if (temp.empty()) {
				temp.push(top);
				break;
			}
			else if (top == temp.top()) {
				temp.pop();			
				answer++;
				break;
			}
			else if(top != temp.top()){
				temp.push(top);
				break;
			}
		}
	}
	answer *=2;
	cout << answer;
	return answer;
}

int main() {
	solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} },
		{ 1,5,3,5,1,2,1,4 }); //4
}
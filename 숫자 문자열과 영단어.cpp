#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;
	string tempString = "";
	vector<char> temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp.push_back(s[i]);
		}
		else {
			if (s[i] == 'z') {
				temp.push_back('0');
				i += 3;
			}
			else if (s[i] == 'o') {
				temp.push_back('1');
				i += 2;
			}
			else if (s[i] == 't') {
				if (s[i + 1] == 'w') {
					temp.push_back('2');
					i += 2;
				}
				else if(s[i+1] == 'h'){
					temp.push_back('3');
					i += 4;
				}
			}
			else if (s[i] == 'f') {
				if (s[i + 1] == 'o') {
					temp.push_back('4');
					i += 3;
				}
				else if (s[i + 1] == 'i') {
					temp.push_back('5');
					i += 3;
				}
			}
			else if (s[i] == 's') {
				if (s[i + 1] == 'i') {
					temp.push_back('6');
					i += 2;
				}
				else if (s[i + 1] == 'e') {
					temp.push_back('7');
					i += 4;
				}
			}
			else if (s[i] == 'e') {
				temp.push_back('8');
				i += 4;
			}
			else if (s[i] == 'n') {
				temp.push_back('9');
				i += 3;
			}
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		tempString += temp[i];
	}
	answer = stoi(tempString);
	cout << answer << endl;
	return answer;
}

int main() {
	solution("one4seveneight"); //1478
	solution("23four5six7"); //234567
	solution("2three45sixseven"); //234567
	solution("123"); //123
}
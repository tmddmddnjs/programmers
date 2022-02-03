#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int count = 0;
	string temp = "";
	vector<int> v;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			temp += dartResult[i];
		}
		else if (dartResult[i] == 'S') {
			int n = stoi(temp);
			v.push_back(n);
			count++;
			temp = "";
		}
		else if (dartResult[i] == 'D') {
			int n = stoi(temp);
			v.push_back(pow(n,2));
			count++;
			temp = "";
		}
		else if (dartResult[i] == 'T') {
			int n = stoi(temp);
			v.push_back(pow(n,3));
			count++;
			temp = "";
		}
		else if (dartResult[i] == '*') {
			if (count == 1) {
				v[count - 1] *= 2;
			}
			else {
				v[count - 1] *= 2;
				v[count - 2] *= 2;
			}
			
		}
		else if (dartResult[i] == '#') {
			v[count - 1] = -v[count - 1];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
		answer += v[i];
	}
	cout << answer << endl;
	return answer;
}

int main() {
	solution("1S2D*3T"); //37
	solution("1D2S#10S"); //9
	solution("1D2S0T"); //3 
	solution("1S*2T*3S"); //23
	solution("1D#2S*3S"); //5
	solution("1T2D3D#"); //-4
	solution("1D2S3T*"); //59
}
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

//내림차순 정렬
bool cmp(const pair<int, double>& a, const pair<int, double>& b) {
	if (a.second == b.second) 
		return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
	//스테이지값과 나눈 결과값 저장할 mapㅋ
	map<int, double> map;
	vector<int> answer;
	double count = stages.size();
	for (int i = 1; i <= N; i++) {
		double fail = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (i == stages[j]) {
				fail++;
			}
		}
		//스테이지 도달 유저 없을 때는 실패율 0
		if (fail == 0) {
			map[i] = 0;
		}
		else {
			map[i] = fail / count;
		}
		count -= fail;
	}
	//값이 제대로 들어가 있는지 확인용
	/*for (auto it = map.begin(); it != map.end(); it++) {
		cout << it->first << " " << it->second << " ";
	}*/
	vector<pair<int, double>> vec(map.begin(), map.end());
	sort(vec.begin(), vec.end(), cmp);
	for (auto num : vec) {
		cout << num.first << " | value : " << num.second << "\n";
		answer.push_back(num.first);
	}
	cout << endl;
	return answer;
}

int main() {
	solution(5, { 2,1,2,6,2,4,3,3 });
	solution(4, { 4,4,4,4,4 });
}
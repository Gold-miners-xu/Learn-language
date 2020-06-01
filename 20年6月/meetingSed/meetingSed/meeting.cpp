#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//会议模型
class activity {
public:
	int start;
	int end;
	bool processed;
	activity(int start, int end, bool processed = false) {
		this->start = start;
		this->end = end;
		this->processed = processed;
	}
};
//排序方式
bool cmp(const activity& a, const activity& b) {
	return b.start > a.start;
}
//题解算法
int greedy(vector<activity> activities) {
	int len = activities.size();
	int ret = 0;
	while (1) {
		bool get = false;
		for (int i = 0; i < len; i++) {
			int time;
			if (!activities[i].processed) {
				ret++;
				time = activities[i].end;
				activities[i].processed = true;
			}
			else
				continue;
			for (int j = i + 1; j < len; j++) {
				if (!activities[j].processed && activities[j].start >= time) {
					activities[j].processed = true;
					time = activities[j].end;
				}
			}
		}
		if (!get)
			break;
	}
	return ret;
}
int main(int argc, char** argv) {
	int n;
	cout << "请输入需要安排的会议个数" << endl;
	cin >> n;
	vector<activity> activities;
	for (int i = 0; i < n; i++) {
		int start;
		int end;
		//检查是否输入合理
		do {
			cout << " 请正确输入第" << i + 1 << "组开始和结束时间 " << endl;
			cin >> start >> end;
		} while (start >= end);
		cout << " 第 " << i + 1 << " 组数据输入成功 " << endl;
		activity temp(start, end);
		activities.push_back(temp);
	}
	sort(activities.begin(), activities.end(), cmp);
	cout << "最少使用" << greedy(activities) << "个会场" << endl;
}
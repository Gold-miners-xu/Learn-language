#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//����ģ��
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
//����ʽ
bool cmp(const activity& a, const activity& b) {
	return b.start > a.start;
}
//����㷨
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
	cout << "��������Ҫ���ŵĻ������" << endl;
	cin >> n;
	vector<activity> activities;
	for (int i = 0; i < n; i++) {
		int start;
		int end;
		//����Ƿ��������
		do {
			cout << " ����ȷ�����" << i + 1 << "�鿪ʼ�ͽ���ʱ�� " << endl;
			cin >> start >> end;
		} while (start >= end);
		cout << " �� " << i + 1 << " ����������ɹ� " << endl;
		activity temp(start, end);
		activities.push_back(temp);
	}
	sort(activities.begin(), activities.end(), cmp);
	cout << "����ʹ��" << greedy(activities) << "���᳡" << endl;
}
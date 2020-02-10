#include<stdio.h>
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
	int time = 0;
	if (timeSeriesSize > 0) {
		time = duration;
	}
	else
		return 0;
	for (int i = 1; i < timeSeriesSize; i++) {
		time += duration;
		if (timeSeries[i] - timeSeries[i - 1] < duration) {
			time -= (duration - timeSeries[i] + timeSeries[i - 1]);
		}
	}
	return time;
}
int main() {
	return 0;
}
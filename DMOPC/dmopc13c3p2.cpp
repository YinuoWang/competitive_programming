#include <iostream>
#include <string>
#include <cmath>
 
using namespace std;

int daysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

string addZero(int inputNum) {
	if (to_string(inputNum).length() == 1) {
		return "0" + to_string(inputNum);
	}
	return to_string(inputNum);
}

int main() {
	int s;
	string day, times;
	cin >> s >> day >> times;
	int year, month, currentDay, hour;
	year = stoi(day.substr(0, 4));
	month = stoi(day.substr(5, 2));
	currentDay = stoi(day.substr(8, 2));
	hour = stoi(times.substr(0, 2));

	int daysPast = s / 24;
	hour -= s % 24;
	if (hour < 0) {
		hour = 24 - abs(hour);
		daysPast++;
	}
	int yearsPast = 0;
	while (daysPast != 0) {
		while (currentDay > 0 && daysPast != 0) {
			currentDay--;
			daysPast--;
		}
		if (currentDay <= 0) {
			month--;
			if (month <= 0) {
				month = 12;
				yearsPast++;
				currentDay = 31;
			}
			else {
				currentDay = daysOfMonth[month - 1];
			}
			
		}
		if (daysPast == 0) {
			break;
		}
	}
	year -= yearsPast;
	string sMonth = addZero(month), sDay = addZero(currentDay), sHour = addZero(hour);
	cout << year << '/' << sMonth << '/' << sDay << ' ' << sHour << times.substr(2,6) << endl;
	return 0;
}
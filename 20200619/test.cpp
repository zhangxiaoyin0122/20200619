#include <iostream>
using namespace std;

//#include <stdio.h>
//#include <stdlib.h>

//int add(int a, int b) {
//	return a + b;
//}
//int sub(int a, int b) {
//	return a - b;
//}
//int mul(int a, int b) {
//	return a * b;
//}
//int div(int a, int b) {
//	return a / b;
//}
//通过函数指针使用回调函数达到
typedef int(*Compare)(int a, int b);

void BubbleSort(int* array, int size,Compare com) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > 0; cur--) {
			if (com(array[cur-1] , array[cur])==0) {
				int tmp = array[cur];
				array[cur] = array[cur - 1];
				array[cur - 1] = tmp;
			}
		}
	}
}

int Less(int a, int b) {
	return a < b ? 1 : 0;
}
int Greater(int a, int b) {
	return a > b ? 1 : 0;
}


#include <iostream>
using namespace std;

class Date {
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	Date& operator+=(int day) {
		_day += day;
		while (_day > getdays(_year, _month)) {
			_day -= getdays(_year, _month);
			_month++;
			if (_month == 13) {
				_month = 1;
				_year++;
			}
		}
		return *this;
	}
	//获取月份天数
	int getdays(int year, int month) {
		int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if ((((year % 100 == 0) && (year % 4 == 0)) || (year % 400 == 0)) && (month == 2)) {
			++day;
		}
		return day;
	}
	void Display() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	//转移表
	//int(*p[5])(int a,int b) = { NULL,add,sub,mul,div };

	/*char str1[] = "hello";
	char str2[] = "hello";
	const char* str3 = "hello";
	const char* str4 = "hello";
	if (str1 == str2) {
		printf("相等\n");
	}
	else
		printf("不相等\n");
	if (str3 == str4) {
		printf("相等\n");
	}
	else
		printf("不相等\n");
	return 0;*/

	int array[10] = { 9,8,7,6,5,4,3,2,1,0 };
	BubbleSort(array, 10,Less);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");


	return 0;
}
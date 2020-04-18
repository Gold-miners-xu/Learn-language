#include<iostream>
using namespace std;
class Point {
public:
	//设置x
	void setX(int x) {
		m_X = x;
	}
	//获取x
	int getX() {
		return m_X;
	}
	//设置y
	void setY(int y) {
		m_Y = y;
	}
	//获取y
	int getY() {
		return m_Y;
	}
private:
	int m_X;
	int m_Y;
};
//创建圆类
class Round {
public:
	//设置m_R
	void setR(int r) {
		m_R = r;
	}
	//获取m_R
	int getR() {
		return m_R;
	}
	//设置圆心
	void setCenter(Point p) {
		center = p;
	}
	//获取圆心
	Point getCenter() {
		return center;
	}
private:
	int m_R;
	Point center;
};

//判断点和圆的关系
void isInCircle(Round &c,Point &p) {
	//获取点到圆心距离平方
	int rit = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//获取R的平方
	int res = c.getR() * c.getR();
	//判断关系
	if (res == rit) {
		cout << "点在圆上" << endl;
	}
	else if (res > rit) {
		cout << "点在圆内" << endl;

	}
	else {
		cout << "点在圆外" << endl;
	}
}
int main() {
	Point cent;
	cent.setX(10);
	cent.setY(0);
	Round c;
	c.setCenter(cent);
	c.setR(10);
	Point rit;
	rit.setX(10);
	rit.setY(11);
	isInCircle(c, rit);
	return 0;
}
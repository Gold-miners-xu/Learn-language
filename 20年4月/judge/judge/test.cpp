#include<iostream>
using namespace std;
class Point {
public:
	//����x
	void setX(int x) {
		m_X = x;
	}
	//��ȡx
	int getX() {
		return m_X;
	}
	//����y
	void setY(int y) {
		m_Y = y;
	}
	//��ȡy
	int getY() {
		return m_Y;
	}
private:
	int m_X;
	int m_Y;
};
//����Բ��
class Round {
public:
	//����m_R
	void setR(int r) {
		m_R = r;
	}
	//��ȡm_R
	int getR() {
		return m_R;
	}
	//����Բ��
	void setCenter(Point p) {
		center = p;
	}
	//��ȡԲ��
	Point getCenter() {
		return center;
	}
private:
	int m_R;
	Point center;
};

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Round &c,Point &p) {
	//��ȡ�㵽Բ�ľ���ƽ��
	int rit = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//��ȡR��ƽ��
	int res = c.getR() * c.getR();
	//�жϹ�ϵ
	if (res == rit) {
		cout << "����Բ��" << endl;
	}
	else if (res > rit) {
		cout << "����Բ��" << endl;

	}
	else {
		cout << "����Բ��" << endl;
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
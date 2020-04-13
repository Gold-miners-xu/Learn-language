#include<iostream>
using namespace std;

//立方体
class Cube {
public:
	//设置长
	void setL(int l) {
		m_L = l;
	}
	//获取长
	int getL() {
		return m_L;
	}
	//设置宽
	void setW(int w) {
		m_W = w;
	}
	//获取宽
	int getW() {
		return m_W;
	}
	//设置高
	void setH(int h) {
		m_H = h;
	}
	//获取高
	int getH() {
		return m_H;
	}
	//获取立方体面积
	int calS() {
		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
	}
	//获取立方体体积
	int calV() {
		return m_L * m_H * m_W;
	}
	bool isEq(Cube &c) {
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
			return true;
		return false;
	}
private:
	int m_L;		//立方体长
	int m_W;		//宽
	int m_H;		//高
};
//判断两个立方体是否相等
bool isEq(Cube c1, Cube c2) {
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
		return true;
	return false;
}
int main() {
	Cube c1;
	c1.setH(5);
	c1.setL(6);
	c1.setW(7);
	cout << "c1的面积为:" << c1.calS() << "c1的体积为" << c1.calV() << endl;
	Cube c2;
	c2.setH(5);
	c2.setL(6);
	c2.setW(7);
	bool ret = isEq(c1, c2);
	//bool ret = c1.isEq(c2);
	if (ret) {
		cout << "c1 == c2" << endl;
	}
	else {
		cout << " c1 != c2" << endl;
	}
	return 0;
}
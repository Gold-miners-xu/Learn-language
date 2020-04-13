#include<iostream>
using namespace std;

//������
class Cube {
public:
	//���ó�
	void setL(int l) {
		m_L = l;
	}
	//��ȡ��
	int getL() {
		return m_L;
	}
	//���ÿ�
	void setW(int w) {
		m_W = w;
	}
	//��ȡ��
	int getW() {
		return m_W;
	}
	//���ø�
	void setH(int h) {
		m_H = h;
	}
	//��ȡ��
	int getH() {
		return m_H;
	}
	//��ȡ���������
	int calS() {
		return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
	}
	//��ȡ���������
	int calV() {
		return m_L * m_H * m_W;
	}
	bool isEq(Cube &c) {
		if (m_H == c.getH() && m_L == c.getL() && m_W == c.getW())
			return true;
		return false;
	}
private:
	int m_L;		//�����峤
	int m_W;		//��
	int m_H;		//��
};
//�ж������������Ƿ����
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
	cout << "c1�����Ϊ:" << c1.calS() << "c1�����Ϊ" << c1.calV() << endl;
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
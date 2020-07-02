#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
#define LEN sizeof(Poly)

typedef struct term {
	int coef;		//系数
	int expn;		//指数
	struct term* next;
}Link;
class poly {
public:
	//默认构造
	poly()
		:_head(new Link)
	{
		_head->next = nullptr;
	}
	//拷贝构造
	poly(const poly& p)
		:_head(new Link)

	{
		_head->next = nullptr;
		if (p._head == nullptr)
			return;
		Link* cur = p._head->next;
		Link* prev = _head;
		while (cur) {
			Link* newNode = new Link;
			newNode->expn = cur->expn;
			newNode->coef = cur->coef;
			newNode->next = nullptr;
			cur = cur->next;
			prev->next = newNode;
			prev = prev->next;
		}
	}
	//删除节点
	void earse(Link* lik) {
		Link* cur = lik;
		Link* next = lik->next;
		while (next) {
			cur->coef = next->coef;
			cur->expn = cur->expn;
			cur = cur->next;
			next = next->next;
		}
		delete next;
		cur->next = nullptr;
	}
	//整理数据
	void adjust() {
		Link* cur = _head->next;
		Link* next;
		while (cur) {
			next = cur->next;
			while (next) {
				if (cur->expn == next->expn) {
					cur->coef += next->coef;
					earse(next);
				}
				next = next->next;
			}
			cur = cur->next;
		}
	}
	//+=运算符重载
	poly& operator+=(const Link& lik) {
		if (_head) {
			Link* newNode = new Link;
			newNode->coef = lik.coef;
			newNode->expn = lik.expn;
			newNode->next = _head->next;
			_head->next = newNode;
		}
		return *this;
	}
	//*运算
	poly operator*(const poly& pol) {
		poly newP;
		Link* cur;
		Link* add;
		cur = _head->next;
		while (cur) {
			add = pol._head->next;
			while (add) {
				Link* newNode = new Link;
				newNode->coef = add->coef * cur->coef;
				newNode->expn = add->expn + cur->expn;
				newP += *newNode;
				add = add->next;
			}
			cur = cur->next;
		}
		return newP;
	}
	//+运算
	poly operator+(const poly& pol) {
		poly newP(pol);
		Link* cur;
		Link* add;	
		cur = _head->next;
		while (cur) {
			add = newP._head->next;
			while (add) {
				if (add->expn == cur->expn)
				{
					add->coef += cur->coef;
					break;
				}
				add = add->next;
			}
			if (add == nullptr) {
				newP += *cur;
			}
			cur = cur->next;
		}
		return newP;
	}
	//=运算符重载
	poly& operator=(poly pol) {
		Link* tmp = pol._head;
		pol._head = _head;
		_head = tmp;
		return *this;
	}
	//打印函数
	void print() {
		adjust();
		Link* cur = _head->next;
		cout << "p(x)" << " " << "=" << " ";
		while (cur) {
			if (cur == _head->next) {
				if (cur->coef == 1 && cur->expn == 1) {
					cout << "X^";
				}
				else if (cur->coef == 1) {
					cout << "X^" << cur->expn;
				}
				else if (cur->expn == 1) {
					cout << cur->coef << "X^";
				}
				else
					cout << cur->coef << "X^" << cur->expn;
			}
				
			else {
				if (cur->coef == 1 && cur->expn == 1) {
					cout << " + " << "X^";
				}
				else if (cur->coef == 1) {
					cout << " + " << "X^" << cur->expn;
				}
				else if (cur->expn == 1) {
					cout << " + " << cur->coef << "X^";
				}else
					cout << " + " << cur->coef << "X^" << cur->expn;
			}
				
			cur = cur->next;
		}
		cout << endl;
	}
	//析构函数
	~poly() {
		Link* cur = _head;
		Link* next;
		if (cur) {
			next = cur->next;
			delete cur;
			cur = next;
		}
		_head = nullptr;
	}
private:
	Link* _head;	//多项式头结点
};
//创建节点
Link* newLink(int x, int y) {
	if (x <= 0 || y <= 0)
	{
		cout << "数据无效,创建节点失败" << endl;
		return nullptr;
	}
	Link* newNode = new Link;
	newNode->coef = x;
	newNode->expn = y;
	newNode->next = nullptr;
	return newNode;
}
//创建多项式
poly newpoly() {
	poly newpoly;
	int choice;
	while (1) {
		cout << "是否继续输入" << endl;
		cout << "0.输入结束" << endl;
		cout << "1.继续输入" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		cout << "请输入系数:";
		int x, y;
		cin >> x;
		cout << endl << "请输入指数:";
		cin >> y;
		cout << endl;
		Link* newNode = newLink(x, y);
		if(newNode)
			newpoly += *newNode;
	}
	return newpoly;
}
int main() {
	int x;
	while (1) {
		cout << "-----------------------------------" << endl;
		cout << "     " << "请选择需要选择的内容" << endl;
		cout << "     " << "1.多项式相加" << endl;
		cout << "     " << "2.多项式相乘" << endl;
		cout << "     " << "0.退出程序" << endl;
		cout << "-----------------------------------" << endl;
		cin >> x;
		if (x == 0)
			break;
		cout << "构建第一个多项式" << endl;
		poly p1 = newpoly();
		cout << "构建第二个多项式" << endl;
		poly p2 = newpoly();
		if (x == 1) {
			p1 = p1 + p2;
			p1.print();
		}
		else if (x == 2) {
			p1 = p1 * p2;
			p1.print();
		}
	}
	return 0;
}
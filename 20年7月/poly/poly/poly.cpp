#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
#define LEN sizeof(Poly)

typedef struct term {
	int coef;		//ϵ��
	int expn;		//ָ��
	struct term* next;
}Link;
class poly {
public:
	//Ĭ�Ϲ���
	poly()
		:_head(new Link)
	{
		_head->next = nullptr;
	}
	//��������
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
	//ɾ���ڵ�
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
	//��������
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
	//+=���������
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
	//*����
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
	//+����
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
	//=���������
	poly& operator=(poly pol) {
		Link* tmp = pol._head;
		pol._head = _head;
		_head = tmp;
		return *this;
	}
	//��ӡ����
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
	//��������
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
	Link* _head;	//����ʽͷ���
};
//�����ڵ�
Link* newLink(int x, int y) {
	if (x <= 0 || y <= 0)
	{
		cout << "������Ч,�����ڵ�ʧ��" << endl;
		return nullptr;
	}
	Link* newNode = new Link;
	newNode->coef = x;
	newNode->expn = y;
	newNode->next = nullptr;
	return newNode;
}
//��������ʽ
poly newpoly() {
	poly newpoly;
	int choice;
	while (1) {
		cout << "�Ƿ��������" << endl;
		cout << "0.�������" << endl;
		cout << "1.��������" << endl;
		cin >> choice;
		if (choice == 0)
			break;
		cout << "������ϵ��:";
		int x, y;
		cin >> x;
		cout << endl << "������ָ��:";
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
		cout << "     " << "��ѡ����Ҫѡ�������" << endl;
		cout << "     " << "1.����ʽ���" << endl;
		cout << "     " << "2.����ʽ���" << endl;
		cout << "     " << "0.�˳�����" << endl;
		cout << "-----------------------------------" << endl;
		cin >> x;
		if (x == 0)
			break;
		cout << "������һ������ʽ" << endl;
		poly p1 = newpoly();
		cout << "�����ڶ�������ʽ" << endl;
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
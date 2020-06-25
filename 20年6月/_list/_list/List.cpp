#include<iostream>
using namespace std;
template <class T>
struct ListNode {
	T _val;
	ListNode* _next;
	ListNode* _prev;
	ListNode(const T& val = T()) 
		:_val(val)
		,_next(nullptr)
		,_prev(nullptr)
	{
	}
};
template <class T, class Ref, class Ptr>
struct ListIterator {
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> self;
	ListIterator(Node* node)
		:_node(node)
	{
	}
	Ref operator*() {
		return _node->_val;
	}
	Ptr operator->() {
		return &_node->_val;
	}
	self operator++() {
		_node = _node->_next;
		return *this;
	}
	self operator--() {
		_node = _node->_prev;
		return *this;
	}
	bool operator!=(const self& it) {
		return it._node != _node;
	}
	bool operator==(const self& it) {
		return it._node == _node;
	}
	Node* _node;
};
template <class T>
class List {
	
public:
	typedef ListNode<T> Node;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
	List()
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
	}
	iterator begin() {
		return iterator(_header->_next);
	}
	iterator end() {
		return iterator(_header);
	}
	const iterator begin() const {
		return iterator(_header->_next);
	}
	const iterator end() const {
		return iterator(_header);
	}
	
	void insert(iterator pos,const T& val) {
		Node* cur = new Node(val);
		Node* node = pos._node;
		Node* prev = node->_prev;
		cur->_prev = prev;
		prev->_next = cur;
		cur->_next = node;
		node->_prev = cur;
	}
	iterator erase(iterator pos) {
		if (pos != end()) {
			Node* node = pos->_node;
			Node* prev = node->_prev;
			Node* next = node->_next;
			delete node;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}
	void pushBack(const T& val)
	{
		insert(end(), val);
	}

	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}
	size_t size() {
		size_t rit = 0;
		for (const auto& it : *this) {
			++rit;
		}
		return rit;
	}
	List(const List<T>& lst) 
		:_header(new Node)
	{
		_header->_next = _header->_prev = _header;
		for (const auto& e : lst) {
			pushBack(e);
		}
	}
	void clear() {
		Node* cur = _header->_next;
		while (cur != _header) {
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_header->_next = _header->_prev = _header;
	}
	~List() {
		if (_header) {
			clear();
			delete _header;
			_header = nullptr;
		}
	}
	List<T>& operator=(List<T> lst) {
		swap(lst._header, _header);
		return *this;
	}
private:
	Node* _header;
};
int main() {
	List<int> lst;
	lst.pushBack(1);
	lst.pushFront(0);
	cout << lst.size() << endl;
	return 0;
}
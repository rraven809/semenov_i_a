#include <queuer/queuer.h>
#include <iostream>

QueueR::QueueR()
	: first(nullptr)
{
}

QueueR::QueueR(const QueueR& copy)
{
	_size = copy._size;
	Node* this_temp = first;
	Node* temp = copy.first;
	this_temp->val = temp->val;
	temp = temp->next;
	for (int i = 1; i < _size; i++) {
		Node* nd = new Node(temp->val, nullptr);
		this_temp->next = nd;
		this_temp = this_temp->next;
		temp = temp->next;
	}
	this_temp = nullptr;
	temp = nullptr;
}

QueueR::~QueueR()
{
	while (!this->isEmpty())
		this->pop();
}

QueueR& QueueR::operator=(const QueueR& rhs)
{
	if (this != &rhs) {
		QueueR temp = rhs;
		first = temp.first;
		_size = temp._size;
	}
	return *this;
}

bool QueueR::isEmpty() const
{
	return _size == 0;
}

int QueueR::top()
{
	return first->get_value();
}

void QueueR::push(const int& val)
{
	_size += 1;
	if (_size == 1) {
		Node* nd = new Node(val, nullptr);
		first = nd;
		return;
	}

	Node* temp = first;
	Node* last = nullptr;
	while ((temp != nullptr) && (temp->get_value() < val)) {
		last = temp;
		temp = temp->next;
	}

	Node* nd = new Node(val, temp);
	if (last != nullptr)
		last->next = nd;
	else
		first = nd;
	nd->next = temp;
}

void QueueR::pop()
{
	if (_size == 0) {
		return;
	}
	Node* temp = first->next;
	delete first;
	first = temp;
	_size -= 1;
}

int QueueR::Node::get_value()
{
	return val;
}

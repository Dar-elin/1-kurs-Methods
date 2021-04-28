#pragma once
#include <iostream>
#include <fstream>

class Complex
{
public:
	Complex() {};
	Complex(const Complex&);
	Complex(double, double);
	~Complex() {};

	void SetRealPart(double);
	void SetImaginaryPart(double);
	void SetComplex(double, double);
	double GetRealPart();
	double GetImaginaryPart();
	void Display();
	void EnterComplex();
	void EnterComplex(std::istream& in);

	const Complex operator+ (const Complex&);
	const Complex operator- (const Complex&);
	const Complex operator* (const Complex&);
	const Complex operator/ (const Complex&);
	const Complex& operator= (const Complex&);
	//friend std::istream& operator>>(istream&, Complex&);

private:
	double real = 0, imaginary = 0;
};


template <typename T>
class Stack
{
public:
	Stack() :top(nullptr) { }
	Stack(const Stack& stack)	{*this = stack;	}

	bool isEmpty() const {	return !top; }

	void push(T item)
	{
		Node* node = new Node(item);
		node->next = top;
		top = node;
	}

	T pop()
	{
		Node* node = top;
		T buffer = top->item;
		top = top->next;
		delete node;
		return buffer;
	}

	int size() const
	{
		int size = 0;
		Node* current = top;
		while (current)
		{
			current = current->next;
			size++;
		}
		return size;
	}

	void clear()
	{
		while (top)
		{
			Node* node = top;
			top = top->next;
			delete node;
		}
	}

	double operator-()
	{
		return pop();
	}

	Stack operator+(double item)
	{
		push(item);
		return *this;
	}

	Stack& operator=(const Stack& stack)
	{
		if (!stack.top)
		{
			top = nullptr;
			return *this;
		}
		top = new Node(stack.top->item);
		Node* buffer1, * buffer2;
		buffer1 = top;
		buffer2 = stack.top->next;
		while (buffer2)
		{
			buffer1->next = new Node(buffer2->item);
			buffer1 = buffer1->next;
			buffer2 = buffer2->next;
		}
		return *this;
	}

	~Stack()
	{
		clear();
		delete top;
	}
private:
	struct Node
	{
		Node() :item(0), next(nullptr) { }
		Node(double value) :item(value), next(nullptr) { }
		friend std::ostream& operator<<(std::ostream& stream, const Node& node)
		{
			stream << node.item;
			return stream;
		}
		double item;
		Node* next;
	};
	Node* top;
};




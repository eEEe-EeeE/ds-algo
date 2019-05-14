#include "Calculator.h"
using namespace std;

inline double stringToDouble(const string &str) {
	istringstream stream(str);  //×Ö·û´®ÊäÈëÁ÷
	double result;
	stream >> result;
	return result;
}

void Calculator::enter(const double & num) {
	if (!stack.isFull()) {
		stack.push(num);
	}
	else {
		error("Stack is full.");
	}
}

bool Calculator::getTwoOperands(double & opnd1, double & opnd2) {
	if (!stack.isEmpty()) {
		opnd2 = stack.pop();
	}
	else {
		error("opnd2: Stack is empty.");
		return false;
	}
	if (!stack.isEmpty()) {
		opnd1 = stack.pop();
	}
	else {
		error("opnd1: Stack is empty");
		return false;
	}
	return true;
}

void Calculator::compute(const char & op) {
	double opnd1, opnd2;
	bool res = getTwoOperands(opnd1, opnd2);
	if (res) {
		switch (op) {
		case '+':
			stack.push(opnd1 + opnd2);
			break;
		case '-':
			stack.push(opnd1 - opnd2);
			break;
		case '*':
			stack.push(opnd1 * opnd2);
			break;
		case '/':
			if (opnd2 == 0) {
				error("Divided by zero.");
				stack.clear();
			}
			else {
				stack.push(opnd1 / opnd2);
			}
			break;
		case '^':
			if (opnd1 == 0 && opnd2 == 0) {
				error("Zero power of zero.");
				stack.clear();
			}
			else {
				stack.push(pow(opnd1, opnd2));
			}
			break;
		default:
			error("Unrecognized operator.");
			stack.clear();
			break;
		}
		if (!stack.isEmpty()) 
			cout << "= " << stack.peek() << endl;
		else {
			error("The expression is incorrect.Please re-enter: ");
		}
	}
	else {
		error("Not enough operands.");
		stack.clear();
	}
}

void Calculator::run() {
	string exp;
	cout << "q to quit." << endl;
	while (cin >> exp, exp != "q") {
		switch (exp[0]) {
		case 'c':
			stack.clear();
			break;
		case '-':
			if (exp.size() > 1)
				enter(stringToDouble(exp));
			else
				compute(exp[0]);
			break;
		case '+':
		case '*':
		case '/':
		case '^':
			compute(exp[0]);
			break;
		default:
			enter(stringToDouble(exp));
			break;
		}
	}
}

void Calculator::clear() {
	stack.clear();
}
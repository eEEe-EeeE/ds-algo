#include "Calculator.h"
using namespace std;

inline double stringToDouble(const string &str) {
	istringstream stream(str);  //×Ö·û´®ÊäÈëÁ÷
	double result;
	stream >> result;
	return result;
}

void Calculator::enter(const double & num) {
	stack.push(num);
}

bool Calculator::getTwoOperands(double & opnd1, double & opnd2) {
	if (!stack.isEmpty()) {
		opnd2 = stack.pop();
	}
	else {
		return false;
	}
	if (!stack.isEmpty()) {
		opnd1 = stack.pop();
	}
	else {
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
				error("Dividing by zero.");
				stack.clear();
			}
			else {
				stack.push(opnd1 / opnd2);
			}
			break;
		case '^':
			if (opnd1 == 0 && opnd2 == 0) {
				error("Meaningless.");
				stack.clear();
			}
			else {
				stack.push(pow(opnd1, opnd2));
			}
			break;
		default:
			error("Unrecognized operator!");
			break;
		}
		if (!stack.isEmpty()) 
			cout << "= " << stack.peek() << endl;
	}
	else {
		stack.clear();
	}
}

void Calculator::run() {
	string exp;
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
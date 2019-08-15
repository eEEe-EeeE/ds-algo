#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <Windows.h>
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Complex.h"
#include "Clock.h"
#include "Array.h"
#include "LinkedList.h"
#include "Calculator.h"
#include "SortAlgo.h"
void printPrime(const int& n);
int startUp(Date& date, Account* account[], const int& n);
bool isPalindromic(std::string s, int left, int right);
std::string solution() {
	std::string s("abacdfgdcaba");
	int sub_begin = 0;
	int max_len = 0;
	int max_len2 = 0;
	char ch = '#';
	std::string s2("#");
	for (auto& e : s) {
		s2 = s2 + e + ch;
	}
	std::vector<int> radius(s2.size(), 0);

	int center = 0;
	int right_bound = 0;
	for (int index = 0; index < int(s2.size()); ++index) {
		radius[index] = (index < right_bound ? min(radius[2 * center - index], right_bound - index) : 1);
		// À©Õ¹index×Ö·ûµÄ°ë¾¶
		if (index - radius[index] >= 0 && index + radius[index] < int(s2.size())) {
			while (s2[index + radius[index]] == s2[index - radius[index]]) {
				radius[index] += 1;
				if (index - radius[index] < 0 || index + radius[index] >= int(s2.size()))
					break;
			}
		}
		if (index + radius[index] > right_bound) {
			right_bound = index + radius[index];
			center = index;
		}
	}

	for (int index = 0; index < int(s2.size()); ++index) {
		if (radius[index] > max_len2) {
			if (s2[index] == ch) {
				sub_begin = (index - radius[index] + 2) / 2;
				max_len = radius[index] - 1;
			}
			else {
				sub_begin = (index - radius[index] + 2) / 2;
				max_len = radius[index] - 1;
			}
			max_len2 = radius[index];
		}
	}
	
	return std::string(s, sub_begin, max_len);
}
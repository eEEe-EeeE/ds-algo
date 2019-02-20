#ifndef MYUTILITY_H
#define MYUTILITY_H

#include <random>
#include <vector>

int myrandom(int b, int e);
void insertsort(std::vector<int> & v, bool mode = true);
void selectsort(std::vector<int> & v);
void mergesort(std::vector<int> & v, int p, int r);

#endif
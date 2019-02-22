#ifndef MYUTILITY_H
#define MYUTILITY_H

#include <random>
#include <vector>

int myrandom(int b, int e);
void insertsort1(std::vector<int> & v, bool mode = true);
void insertsort2(std::vector<int> & v);
void selectsort(std::vector<int> & v);
void mergesort(std::vector<int> & v, int p, int r);
int binarysearch1(std::vector<int> & v, int p, int r, int num);
std::vector<int> maxsubarray1(const std::vector<int> & v);

#endif
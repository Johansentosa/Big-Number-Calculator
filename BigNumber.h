#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

bool isGreater(string a, string b);

string plus2(string nums1, string nums2);

string substract2(string nums1, string nums2);

string multiply2(string nums1, string nums2);

void sammy(string *nums1, string *nums2);

bool isGreater(string nums1, string nums2);

bool isGreaterNum(string nums1, string nums2);

void takeHalf(string nums, string *num1, string *num2);

string IntToString(int x);

void minusLose(string *num);

string zeroks(string num, int n);

string mod2(string nums1, string nums2);

string divide2(string nums1, string nums2);
#endif // BIGNUMBER_H

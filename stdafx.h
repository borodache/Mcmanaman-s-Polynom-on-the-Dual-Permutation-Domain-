// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef _stdafx_H
#define _stdafx_H

#pragma once

#include <stdio.h>
#ifdef WIN32
#include <tchar.h>
#endif
#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
// TODO: reference additional headers your program requires here
#include <iostream>
using namespace std;


// math functions
long factorial(const int n);
int min(const int a, const int b);
int max(const int a, const int b);
long N_NofelHal_K(const int n, const int k);
long N_Mahal_K(const int n, const int k);
long Catlan(const int n);
//long f(int n,int a,int b,int c);
// function for finding the "rules"
//void SearchAfterCoefficient();
void SearchAfterCoefficient3(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3);
void SearchAfterCoefficient3(const int n1, const long Value1, const int n2, const long Value2);
void SearchAfterCoefficient4(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3, const int n4, const long Value4);
//void SearchAfterCoefficient4(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3, const int n4, const long Value4, const int n5, const long Value5);
//void SearchAfterCoefficient4(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3);

#endif // _stdafx_H
// TODO: reference additional headers your program requires here

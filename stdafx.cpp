// stdafx.cpp : source file that includes just the standard includes
// Permutation.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

long factorial(const int n)
{
	int Ret = 1;
	if (n <= 1)
		return 1;
	for(int i = 1; i <= n; i++)
		Ret *= i;
	return Ret;
}

int min(const int a, const int b)
{
	if (a < b)
		return a;
	return b;
}

int max(const int a, const int b)
{
	if (a > b)
		return a;
	return b;
}


long N_NofelHal_K(const int n, const int k)
{
	long ans = 1;
	for(int i = (n - k + 1); i <= n; i++)
		ans *= (long)i;
	return ans;
}

long N_Mahal_K(const int n, const int k)
{
	if ((k == 0) || (k == n))
		return 1;
	// error
	if ((k < 0) || (k > n))
		return -1;
	const int Min = min(n-k, k);
	//const int Max = max(n-k, n);
	long ans = N_NofelHal_K(n, Min);
	ans /= factorial(Min);
	return ans;
}

long Catlan(const int n)
{
//	return N_Mahal_K(2*n, n) / (n + 1);
	double ans = 1;
	for(int i = 2*n; i >= (n + 1); i--)
	{
		ans *= i;
		ans /= (i - n);
	}
	ans /= (n+1);
	return (long)(ans + 0.5);
}

/*
long f(int n,int a,int b,int c)
{
	return (long)a*N_Mahal_K(n-1,3)+b*N_Mahal_K(n-2, 2)+c*(n - 3);
}

void SearchAfterCoefficient()
{
	for(int a = 1; a<= 20; a++)
	{
		for(int b = 1; b <= 20; b++)
		{
			for(int c = 1; c <= 20; c++)
			{
				if (f(4,a,b,c) == 38 && f(5,a,b,c) == 102 && f(6,a,b,c) == 213)
				{
//					cout << a*x << "+" << b*y << "+" << c*z<<endl;
					cout << a << "," << b << "," << c << endl;
				}
			}
		}
	}
	return;
}
*/

void SearchAfterCoefficient3(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3)
{
	long x1 = N_Mahal_K(n1 - 1, 3);
	long y1 = N_Mahal_K(n1 - 2, 2);
	long z1 = N_Mahal_K(n1 - 3, 1);
	long w1 = N_Mahal_K(n1 - 4, 0);
	long x2 = N_Mahal_K(n2 - 1, 3);
	long y2 = N_Mahal_K(n2 - 2, 2);
	long z2 = N_Mahal_K(n2 - 3, 1);
	long w2 = N_Mahal_K(n2 - 4, 0);
	long x3 = N_Mahal_K(n3 - 1, 3);
	long y3 = N_Mahal_K(n3 - 2, 2);
	long z3 = N_Mahal_K(n3 - 3, 1);
	long w3 = N_Mahal_K(n3 - 4, 0);

	for(int a = 0; a <= 50; a++)
	{
		for(int b = 0; b <= 50; b++)
		{
			for(int c = 0; c <= 50; c++)
			{
				for(int d = 0; d <= 50; d++)
				{
					if (((a*x1 + b*y1 + c*z1 + d*w1) == Value1) && ((a*x2 + b*y2 + c*z2 + d*w2) == Value2) && ((a*x3 + b*y3 + c*z3 + d*w3) == Value3))
						cout << a << "," << b << "," << c << "," << d << endl;
				}
			}
		}
	}
	return;
}



void SearchAfterCoefficient3(const int n1, const long Value1, const int n2, const long Value2)
{
	long x1 = N_Mahal_K(n1-1, 3);
	long y1 = N_Mahal_K(n1-1, 2);
	long z1 = N_Mahal_K(n1 - 3, 1);
//	long w1 = N_Mahal_K(n1 - 2, 1);
	long x2 = N_Mahal_K(n2-1, 3);
	long y2 = N_Mahal_K(n2-1, 2);
	long z2 = N_Mahal_K(n2 - 3, 1);
//	long w2 = N_Mahal_K(n2 - 3, 1);

	for(int a = 10; a <= 13; a++)
	{
		for(int b = 0; b <= 50; b++)
		{
			for(int c = 0; c <= 50; c++)
			{
				if (((a*x1 + b*y1 + c*z1) == Value1) && ((a*x2 + b*y2 + c*z2) == Value2))
				{
//					cout << a*x1 << "+" << b*y1 << "+" << c*z1 << endl;
//					cout << a*x2 << "+" << b*y2 << "+" << c*z2 << endl;
					cout << a << "," << b << "," << c << endl;
				}
			}
		}
	}
	return;
}

/*
void SearchAfterCoefficient4(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3, const int n4, const long Value4)
{
	long x1 = N_Mahal_K(n1-1, 4);
	long y1 = N_Mahal_K(n1-1, 3);
	long z1 = N_Mahal_K(n1-1, 2);
	long w1 = N_Mahal_K(n1-4, 1);
	long x2 = N_Mahal_K(n2-1, 4);
	long y2 = N_Mahal_K(n2-1, 3);
	long z2 = N_Mahal_K(n2-1, 2);
	long w2 = N_Mahal_K(n2-4, 1);
	long x3 = N_Mahal_K(n3-1, 4);
	long y3 = N_Mahal_K(n3-1, 3);
	long z3 = N_Mahal_K(n3-1, 2);
	long w3 = N_Mahal_K(n3-4, 1);
	long x4 = N_Mahal_K(n4-1, 4);
	long y4 = N_Mahal_K(n4-1, 3);
	long z4 = N_Mahal_K(n4-1, 2);
	long w4 = N_Mahal_K(n4-4, 1);

	for(int a = 0; a <= 120; a++)
	{
		for(int b = 0; b <= 120; b++)
		{
			for(int c = 0; c <= 120; c++)
			{
				for(int d = 0; d <= 120; d++)
				{
					if (((a*x1 + b*y1 + c*z1 + d*w1) == Value1) && ((a*x2 + b*y2 + c*z2 +d*w2) == Value2) && ((a*x3 + b*y3 + c*z3 +d*w3) == Value3) && ((a*x4 + b*y4 + c*z4 +d*w4) == Value4))
					{
	//					cout << a*x1 << "+" << b*y1 << "+" << c*z1 << endl;
	//					cout << a*x2 << "+" << b*y2 << "+" << c*z2 << endl;
						cout << a << "," << b << "," << c << "," << d << endl;
					}
				}
			}
		}
	}
	return;
}
*/

void SearchAfterCoefficient4(const int n1, const long Value1, const int n2, const long Value2, const int n3, const long Value3, const int n4, const long Value4)
{
	long x1 = N_Mahal_K(n1-1, 4);
	long y1 = N_Mahal_K(n1-2, 3);
	long z1 = N_Mahal_K(n1-3, 2);
	long w1 = N_Mahal_K(n1-4, 1);
	long s1 = N_Mahal_K(n1-5, 0);
//	long t1 = N_Mahal_K(n1-2, 1);

	long x2 = N_Mahal_K(n2-1, 4);
	long y2 = N_Mahal_K(n2-2, 3);
	long z2 = N_Mahal_K(n2-3, 2);
	long w2 = N_Mahal_K(n2-4, 1);
	long s2 = N_Mahal_K(n2-5, 0);
//	long t2 = N_Mahal_K(n2-2, 1);

	long x3 = N_Mahal_K(n3-1, 4);
	long y3 = N_Mahal_K(n3-2, 3);
	long z3 = N_Mahal_K(n3-3, 2);
	long w3 = N_Mahal_K(n3-4, 1);
	long s3 = N_Mahal_K(n3-5, 0);
//	long t3 = N_Mahal_K(n3-2, 1);

	long x4 = N_Mahal_K(n4-1, 4);
	long y4 = N_Mahal_K(n4-2, 3);
	long z4 = N_Mahal_K(n4-3, 2);
	long w4 = N_Mahal_K(n4-4, 1);
	long s4 = N_Mahal_K(n4-5, 0);
//	long t4 = N_Mahal_K(n4-2, 1);

/*	long x5 = N_Mahal_K(n5-1, 4);
	long y5 = N_Mahal_K(n5-2, 3);
	long z5 = N_Mahal_K(n5-3, 2);
	long w5 = N_Mahal_K(n5-4, 1);
	long s5 = N_Mahal_K(n5-5, 0);
//	long t5 = N_Mahal_K(n5-2, 1);
*/
	for(int a = 0; a <= 80; a++)
	{
		for(int b = 0; b <= 80; b++)
		{
			for(int c = 0; c <= 80; c++)
			{
				for(int d = 0; d <= 80; d++)
				{
					for(int e = 0; e <= 80; e++)
					{
						if (((a*x1 + b*y1 + c*z1 + d*w1 + e*s1) == Value1) && ((a*x2 + b*y2 + c*z2 +d*w2 + e*s2) == Value2) && ((a*x3 + b*y3 + c*z3 +d*w3 + e*s3) == Value3) && ((a*x4 + b*y4 + c*z4 +d*w4 + e*s4) == Value4)/* && ((a*x5 + b*y5 + c*z5 +d*w5 + e*s5) == Value5)*/)
						{
		//					cout << a*x1 << "+" << b*y1 << "+" << c*z1 << endl;
		//					cout << a*x2 << "+" << b*y2 << "+" << c*z2 << endl;
							cout << a << "," << b << "," << c << "," << d << "," << e << endl;
						}
					}
				}
			}
		}
	}
	return;
}


// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

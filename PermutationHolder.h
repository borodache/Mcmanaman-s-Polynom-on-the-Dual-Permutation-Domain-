#ifndef _PermutationHolder_H
#define _PermutationHolder_H

#include "stdafx.h"

class PermutationHolder
{
private:
	int nSize;
	Permutation Permutation1;
	Permutation Permutation2;
	int nInv;
public:
	PermutationHolder(int nSize);
	PermutationHolder(const PermutationHolder& Other);
//	PermutationHolder& operator=(const PermutationHolder& Other);
	bool CheckIfInv(int i, int j) const;
	int inv(bool bReset);
//	bool CheckIfInvAfterChangeInSecondPermutation(int i, int j1, int j2) const;
	void getNextPermutation1();
	void getNextPermutation2(bool bCalculateInv);
	void swap(int i, int j, bool bCalculateInv);
	static void print(int nSize);
//	Permutation* getPermutation(bool WhichFirst) const; // which == 1 || 2
	static int MaxInv(int nSize);
	static int* CoefficientOfThePolinom(int nSize);
	static void printPol(int nSize);
	static int* CoefficientOfThePolinomWithoutDesendingContinuous(int nSize);
	static int* CoefficientOfThePolinomWithoutAsendingContinuous(int nSize);
	static void printPolinomWithoutDesending(int nSize);
	static void printPolinomWithoutAsending(int nSize);
	static long* CoefficientOfTheCatlanPolinomWithoutDesendingSerie(int nSize);
	static long* CoefficientOfTheCatlanPolinomWithoutAsendingSerie(int nSize);
	static int* CoefficientOfTheCatlanThirdPolinom(int nSize);
	static void printCatlanPolinomWithoutDesending(int nSize);
	static void printCatlanPolinomWithoutAsending(int nSize);
	static void printCatlanThirdPolinom(int nSize);
};

#endif // _PermutationHolder_H
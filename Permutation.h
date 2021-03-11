#ifndef _Permutation_H
#define _Permutation_H

#include "stdafx.h"

class Permutation
{
private:
	int nSize; // "const"
	int* pPermutation;
	int nInv;
public:
	Permutation(int nSize);
	Permutation(const Permutation& Other);
	~Permutation();
	const int* const get_pPermutation() const;
	void operator=(const Permutation& Other);
	bool operator==(const Permutation& Other) const;
	bool CheckIfInv(int i, int j) const;
	int inv(bool bReset);
	bool CheckIf_I() const;
	bool CheckIf_W_0() const;
	void getNext(bool bCalculateInv);
	void swap(int i, int j, bool bCalculateInv);
	void print();
	static int MaxInv(int nSize);
	static int* CoefficientOfThePolinom(int nSize);
	static void printPol(int nSize);
//	bool CheckIfRightTerrace(int i) const;
//	bool CheckIfLeftTerrace(int i) const;
//	bool CheckIfTerrace(int i) const;
	bool CheckIfAssending(int i) const;
	bool CheckIfThereIsNoContinuousDesendingSeries() const;
	bool CheckIfThereIsNoContinuousAsendingSeries() const;
	bool CheckIfThereIsDesendingSerie() const;
	bool CheckIfThereIsAsendingSerie() const;
	bool checkIfCatlan() const;
};

#endif // _Permutation_H
// Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Permutation.h"

Permutation::Permutation(int nSize)
{
	this->nSize = nSize;
	pPermutation = new int [nSize];
	for(int i = 0; i < nSize; i++)
		pPermutation[i] = i + 1;
	this->nInv = 0;
}

Permutation::Permutation(const Permutation& Other)
{
	this->nSize = Other.nSize;
	this->pPermutation = new int [nSize];
	for(int i = 0; i < nSize; i++)
		this->pPermutation[i] = Other.pPermutation[i];
	this->nInv = Other.nInv;
}

Permutation::~Permutation()
{
	delete pPermutation;
}

const int* const Permutation::get_pPermutation() const
{
	return pPermutation;
}

void Permutation::operator=(const Permutation& Other)
{
	delete (this->pPermutation);
	this->nSize = Other.nSize;
	this->pPermutation = new int [nSize];
	for(int i = 0; i < nSize; i++)
		this->pPermutation[i] = Other.pPermutation[i];
}

bool Permutation::operator==(const Permutation& Other) const
{
	if (this->nSize != Other.nSize)
		return false;
	for(int i = 0; i < nSize; i++)
	{
		if (this->pPermutation[i] != Other.pPermutation[i])
			return false;
	}
	return true;
}

bool Permutation::CheckIfInv(int i, int j) const
{
	if (i == j)
		return false;
	return (pPermutation[min(i, j)] > pPermutation[max(i, j)]);
}

int Permutation::inv(bool bReset)
{
	if (bReset)
	// Calculate By definition
	{
		int counter = 0;
		for(int i = 0; i < (nSize - 1); i++)
		{
			for(int j = (i + 1); j < nSize; j++)
			{
				if (CheckIfInv(i,j))
					counter++;
			}
		}
		this->nInv = counter;
	}
	return nInv;
}

bool Permutation::CheckIf_I() const
{
	for(int i = 0; i < nSize; i++)
	{
		if (this->pPermutation[i] != (i + 1))
			return false;
	}
	return true;
}	

bool Permutation::CheckIf_W_0() const
{
	for(int i = 0; i < nSize; i++)
	{
		if (this->pPermutation[i] != (nSize - i))
			return false;
	}
	return true;
}

void Permutation::getNext(bool bCalculateInv)
{
	if (CheckIf_W_0())
	{
		*this = Permutation(nSize);
		return;
	}
	int i = nSize - 1;
	while (pPermutation[i-1] >= pPermutation[i]) 
	  i = i-1;

	int j = nSize;
	while (pPermutation[j-1] <= pPermutation[i-1]) 
		j = j-1;
	
	// swap values at positions (i-1) and (j-1)
	swap(i-1, j-1, bCalculateInv);
	i++;
	j = nSize;

	while (i < j)
	{
		swap(i-1, j-1, bCalculateInv);
		i++;
		j--;
	}
}

void Permutation::swap(int i, int j, bool bCalculateInv)
{
	if (bCalculateInv)
	{
		// change num of inv by swap
		if (CheckIfInv(i, j))
			this->nInv--;
		else
			this->nInv++;

		for(int k = i + 1; k <= (j - 1); k++)
		{
			if (CheckIfInv(i, k))
				this->nInv--;
			else
				this->nInv++;
			
			if (CheckIfInv(k, j))
				this->nInv--;
			else
				this->nInv++;
		//		this->nInv -= (this->pPermutation[i] > this->pPermutation[k]);
		//		this->nInv += (this->pPermutation[i] < this->pPermutation[k]);
		//		this->nInv -= (this->pPermutation[j] < this->pPermutation[k]);
		//		this->nInv += (this->pPermutation[j] > this->pPermutation[k]);
		}
	}
	int Temp = pPermutation[i];
	pPermutation[i] = pPermutation[j];
	pPermutation[j] = Temp;
}

void Permutation::print()
{
	for(int i = 0; i < nSize; i++)
	{
		cout << pPermutation[i];
	}
}

int Permutation::MaxInv(int nSize)
{
	return nSize*(nSize-1)/2;
}

int* Permutation::CoefficientOfThePolinom(int nSize)
{
	int* pRet = new int [Permutation::MaxInv(nSize) + 1];
	for(int i = 0; i < (Permutation::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	Permutation Perm(nSize); // Perm - I - "Adish"
	for(int i = 0; i < factorial(nSize); i++)
	{
		pRet[Perm.inv(false)]++;
		if (i == (factorial(nSize) - 1))
				break;
		Perm.getNext(true);
	}
	return pRet;
}

void Permutation::printPol(int nSize)
{
	int* pPol = Permutation::CoefficientOfThePolinom(nSize);
	//Print
	cout << pPol[0]; // Print const
	for(int i = 1; i < (Permutation::MaxInv(nSize) + 1); i++)
		cout << " + " << pPol[i] << "x^" << i;
	delete pPol;
}
/*
bool Permutation::CheckIfRightTerrace(int i) const
{
	if ((this->pPermutation[i+1] - this->pPermutation[i]) == 1)
		return true;
	return false;
}

bool Permutation::CheckIfLeftTerrace(int i) const
{
	if ((this->pPermutation[i] - this->pPermutation[i+1]) == 1)
		return true;
	return false;
}
bool Permutation::CheckIfTerrace(int i) const
{
	if ((this->CheckIfLeftTerrace(i)) || (this->CheckIfRightTerrace(i)))
		return true;
	return false;
}
*/

bool Permutation::CheckIfAssending(int i) const
{
	if (this->pPermutation[i+1] > this->pPermutation[i])
		return true;
	return false;
}

bool Permutation::CheckIfThereIsNoContinuousDesendingSeries() const
{
	int ContinuislyDesending = 0;
	for(int i = 0; i < (this->nSize - 1); i++)
	{
		if (this->CheckIfAssending(i))
			ContinuislyDesending = 0;
		else
			ContinuislyDesending++;
		if (ContinuislyDesending == 2)
			return false;
	}
	return true;
}

bool Permutation::CheckIfThereIsNoContinuousAsendingSeries() const
{
	int ContinuislyDesending = 0;
	for(int i = 0; i < (this->nSize - 1); i++)
	{
		if (this->CheckIfAssending(i))
			ContinuislyDesending++;
		else
			ContinuislyDesending = 0;
		if (ContinuislyDesending == 2)
			return false;
	}
	return true;
}

bool Permutation::CheckIfThereIsDesendingSerie() const
{
	for(int i = 0; i < this->nSize; i++)
	{
		for(int j = i + 1; j < this->nSize; j++)
		{
			if (this->CheckIfInv(i, j))
			{
				for(int k = j + 1; k < this->nSize; k++)
					if (this->CheckIfInv(j, k))
						return true;
			}
		}
	}
	return false;
}

bool Permutation::CheckIfThereIsAsendingSerie() const
{
	for(int i = 0; i < this->nSize; i++)
	{
		for(int j = i + 1; j < this->nSize; j++)
		{
			if (!this->CheckIfInv(i, j))
			{
				for(int k = j + 1; k < this->nSize; k++)
					if (!this->CheckIfInv(j, k))
						return true;
			}
		}
	}
	return false;
}

bool Permutation::checkIfCatlan() const
{
	return (!this->CheckIfThereIsAsendingSerie()) || (!this->CheckIfThereIsDesendingSerie());
}

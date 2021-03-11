#include "stdafx.h"
#include "Permutation.h"
#include "PermutationHolder.h"

PermutationHolder::PermutationHolder(int nSize)
:Permutation1(nSize),Permutation2(nSize)
{
	this->nSize = nSize;
	this->nInv = 0;
}

PermutationHolder::PermutationHolder(const PermutationHolder& Other):
Permutation1(Other.Permutation1),Permutation2(Other.Permutation2)
{
	this->nSize = Other.nSize;
	this->nInv = Other.nInv;
}

/*
PermutationHolder& PermutationHolder::operator=(const PermutationHolder& Other)
{
	this->nSize = Other.nSize;
	this->Permutation1 = Other.Permutation1;
	this->Permutation2 = Other.Permutation2;
}
*/

bool PermutationHolder::CheckIfInv(int i, int j) const
{
	if (i == j)
		return false;
	return Permutation1.CheckIfInv(min(i,j), max(i,j)) && Permutation2.CheckIfInv(min(i,j), max(i,j));
}

int PermutationHolder::inv(bool bReset)
{
	if (bReset)
	// calculate by definition
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

/*
int PermutationHolder::SumInvAfterChangeInSecondPermutation(int i, int j1, int j2) const
// Check if there will be a join inversion after a swap in the second permutation(j1, j2) 
//- the first permutation is unchanged!
// Assumption :: j1 < j2
{
	int ans = 0;
	if ((this->Permutation1.CheckIfInv(i, j1)) && (this->Permutation2.CheckIfInv(i, j2)))
		ans++;
	if ((this->Permutation1.CheckIfInv(i, j2)) && (this->Permutation2.CheckIfInv(i, j1)))
		return true;
	return ans;
}
*/

int PermutationHolder::MaxInv(int nSize)
{
	return Permutation::MaxInv(nSize);
}

void PermutationHolder::getNextPermutation1()
{
	this->Permutation1.getNext(true);
	this->Permutation2 = this->Permutation1;
	this->nInv = this->Permutation1.inv(false);
}
/*
void PermutationHolder::getNextPermutation2()
{
	this->Permutation2.getNext();
}
*/

void PermutationHolder::getNextPermutation2(bool bCalculateInv)
{
//	this->Permutation2.getNext();
	if (this->Permutation2.CheckIf_W_0())
	{
		this->Permutation2 = Permutation(nSize);
		return;
	}
	int i = nSize - 1;
	const int* const pPermutation = this->Permutation2.get_pPermutation();
	while (pPermutation[i-1] >= pPermutation[i]) 
	  i = i-1;

	int j = nSize;
	while (pPermutation[j-1] <= pPermutation[i-1]) 
		j = j-1;
	
	// swap values at positions (i-1) and (j-1)
	this->swap(i-1, j-1, bCalculateInv);
	i++;
	j = nSize;

	while (i < j)
	{
		this->swap(i-1, j-1, bCalculateInv);
		i++;
		j--;
	}
}

// swaps only in the second permutation

void PermutationHolder::swap(int i, int j, bool bCalculateInv)
{

	if (bCalculateInv)
	{
		if (this->CheckIfInv(i, j))
			this->nInv--;
		else if (this->Permutation1.CheckIfInv(i, j) && !this->Permutation2.CheckIfInv(i, j))
			this->nInv++;

//	else if (this->Permutation1.CheckIfInv(i, j) && !this->Permutation2.CheckIfInv(i, j))
//		this->nInv++;
	
		for(int k = 0; k < this->MaxInv(this->nSize); k++)
		{
			if ((k != i) && (k != j))
				this->nInv -= (this->CheckIfInv(i, k) + this->CheckIfInv(k, j));
		//			this->nInv += (this->CheckIfInvAfterChangeInSecondPermutation(k, i, j));
		}
	}
	this->Permutation2.swap(i, j, false);
	if (bCalculateInv)
	{
		for(int k = 0; k < this->MaxInv(this->nSize); k++)
		{
			if ((k != i) && (k != j))
				this->nInv += (this->CheckIfInv(i, k) + this->CheckIfInv(k, j));
		}
	}
	return;
}

// Prints all options of permutations
void PermutationHolder::print(int nSize)
{
	PermutationHolder PH(nSize);
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		for(int j = i; j < factorial(nSize); j++, PH.getNextPermutation2(true))
		{
			PH.Permutation1.print();
			cout << ";"; 
			PH.Permutation2.print(); 
			cout << ";inv:" << PH.inv(false) << endl;
		}
	}
}

/*
Permutation* PermutationHolder::getPermutation(bool WhichFirst) const // which == 0 || 1
{
	Permutation* RetPermutation = new Permutation(this->nSize);
	if (WhichFirst)
	{
		*RetPermutation = this->Permutation1;
		return RetPermutation;
	}
	*RetPermutation = this->Permutation2;
	return RetPermutation;
}
*/

int* PermutationHolder::CoefficientOfThePolinom(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
//		PH.Permutation2 = PH.Permutation1;
		pRet[PH.inv(true)]++;
		PH.getNextPermutation2(true);
		for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2(true))
		{
			// with Agbalt Haklaliut
			pRet[PH.inv(false)] += 2;
		}
	}
	return pRet;
}

void PermutationHolder::printPol(int nSize)
{
	int* pPol = PermutationHolder::CoefficientOfThePolinom(nSize);
	//Print
	cout << pPol[0]; // Print const
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		cout << " + " << pPol[i] << "x^" << i;
	delete pPol;
}

int* PermutationHolder::CoefficientOfThePolinomWithoutDesendingContinuous(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		if (PH.Permutation1.CheckIfThereIsNoContinuousDesendingSeries())
		{
			pRet[PH.inv(false)]++;
			PH.getNextPermutation2(true);
			for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2(true))
			{
				// with Agbalt Haklaliut
				pRet[PH.inv(false)] += 2;
			}
		}
	}
	return pRet;
}

int* PermutationHolder::CoefficientOfThePolinomWithoutAsendingContinuous(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		if (PH.Permutation1.CheckIfThereIsNoContinuousAsendingSeries())
		{
			pRet[PH.inv(false)]++;
			PH.getNextPermutation2(true);
			for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2(true))
			{
				// with Agbalt Haklaliut
				pRet[PH.inv(false)] += 2;
			}
		}
	}
	return pRet;
}

void PermutationHolder::printPolinomWithoutDesending(int nSize)
{
	int* pPol = PermutationHolder::CoefficientOfThePolinomWithoutDesendingContinuous(nSize);
	//Print
	cout << pPol[0]; // Print const
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		cout << " + " << pPol[i] << "x^" << i;
	delete pPol;
}

void PermutationHolder::printPolinomWithoutAsending(int nSize)
{
	int* pPol = PermutationHolder::CoefficientOfThePolinomWithoutAsendingContinuous(nSize);
	//Print
	cout << pPol[0]; // Print const
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		cout << " + " << pPol[i] << "x^" << i;
	delete pPol;
}

/*
int* PermutationHolder::CoefficientOfTheCatlanPolinomWithoutDesendingSerie(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		if (!PH.Permutation1.CheckIfThereIsDesendingSerie())
		{
			pRet[PH.Permutation1.inv(false)]++;
			PH.getNextPermutation2();
			for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2())
			{
				// with Agbalt Haklaliut
				if (!PH.Permutation2.CheckIfThereIsDesendingSerie())
					pRet[PH.inv(false)] += 2;
			}
		}
	}
	return pRet;
}
*/

long* PermutationHolder::CoefficientOfTheCatlanPolinomWithoutDesendingSerie(int nSize)
{
	long* pRet = new long [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
//	PH.getNextPermutation2();
//	pRet[0]++;
//	Permutation PermNext(PH.Permutation2);
	Permutation PermNext(nSize);
	bool flag = false;
	for(int i = 1; i <= Catlan(nSize); i++, PH.Permutation1 = PermNext, PH.Permutation2 = PermNext, flag = false)
	{
		pRet[PH.inv(true)]++;
		for(PH.getNextPermutation2(false); ((!PH.Permutation2.CheckIf_I()) && (i < Catlan(nSize))); PH.getNextPermutation2(false))
		{
			// with Agbalt Haklaliut
			if (!PH.Permutation2.CheckIfThereIsDesendingSerie())
			{
				if (!flag)
				{
					PermNext = PH.Permutation2;
					flag = true;
				}
				pRet[PH.inv(true)] += 2;
			}
		}
		if (!flag)
			break;
	}
	return pRet;
}

long* PermutationHolder::CoefficientOfTheCatlanPolinomWithoutAsendingSerie(int nSize)
{
	long* pRet = new long [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(;PH.Permutation1.CheckIfThereIsAsendingSerie();PH.getNextPermutation1())
	{
		// do nothing
	}
	Permutation PermNext(PH.Permutation1);
	PH.Permutation2 = PH.Permutation1;
	bool flag = false;
	for(int i = 1; i <= Catlan(nSize); i++, PH.Permutation1 = PermNext, PH.Permutation2 = PermNext, flag = false)
	{
		pRet[PH.inv(true)]++;
		for(PH.getNextPermutation2(false); ((!PH.Permutation2.CheckIf_I()) && (i < Catlan(nSize))) ; PH.getNextPermutation2(false))
		{
			// with Agbalt Haklaliut
			if (!PH.Permutation2.CheckIfThereIsAsendingSerie())
			{
				if (!flag)
				{
					PermNext = PH.Permutation2;
					flag = true;
				}
				pRet[PH.inv(true)] += 2;
			}
		}
		if (!flag)
			break;
	}
	return pRet;
}

/*
int* PermutationHolder::CoefficientOfTheCatlanPolinomWithoutAsendingSerie(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		if (!PH.Permutation1.CheckIfThereIsAsendingSerie())
		{
			pRet[PH.Permutation1.inv(false)]++;
			PH.getNextPermutation2(false);
			for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2(false))
			{
				// with Agbalt Haklaliut
				if (!PH.Permutation2.CheckIfThereIsAsendingSerie())
					pRet[PH.inv(true)] += 2;
			}
		}
	}
	return pRet;
}
*/

int* PermutationHolder::CoefficientOfTheCatlanThirdPolinom(int nSize)
{
	int* pRet = new int [PermutationHolder::MaxInv(nSize) + 1];
	for(int i = 0; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		pRet[i] = 0;
	PermutationHolder PH(nSize); // Permutation Holder - Holds I & I Permutation
	for(int i = 0; i < factorial(nSize); i++, PH.getNextPermutation1())
	{
		if (PH.Permutation1.checkIfCatlan())
		{
			pRet[PH.inv(true)]++;
			PH.getNextPermutation2(false);
			for(int j = i + 1; j < factorial(nSize); j++, PH.getNextPermutation2(false))
			{
				// with Agbalt Haklaliut
				if (!PH.Permutation2.checkIfCatlan())
					pRet[PH.inv(true)] += 2;
			}
		}
	}
	return pRet;
}

void PermutationHolder::printCatlanPolinomWithoutDesending(int nSize)
{
	long* pPol = PermutationHolder::CoefficientOfTheCatlanPolinomWithoutDesendingSerie(nSize);
	//Print
	cout << pPol[0]; // Print const
	long lSumOfCoefficients = pPol[0];
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
	{
		cout << " + " << pPol[i] << "x^" << i;
		lSumOfCoefficients += pPol[i];
	}
	cout << endl << "sum of Coefficients is: " << lSumOfCoefficients;
	cout << endl << "And the Catlan(" << nSize << ")^2 function is: " << Catlan(nSize)*Catlan(nSize);
	delete pPol;
}

void PermutationHolder::printCatlanPolinomWithoutAsending(int nSize)
{
	long* pPol = PermutationHolder::CoefficientOfTheCatlanPolinomWithoutAsendingSerie(nSize);
	//Print
	cout << pPol[0]; // Print const
	long lSumOfCoefficients = pPol[0];
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
	{
		cout << " + " << pPol[i] << "x^" << i;
		lSumOfCoefficients += pPol[i];
	}
	cout << endl << "sum of Coefficients is: " << lSumOfCoefficients;
	cout << endl << "And the Catlan(" << nSize << ")^2 function is: " << Catlan(nSize)*Catlan(nSize);
	delete pPol;
}

void PermutationHolder::printCatlanThirdPolinom(int nSize)
{
	int* pPol = PermutationHolder::CoefficientOfTheCatlanThirdPolinom(nSize);
	//Print
	cout << pPol[0]; // Print const
	for(int i = 1; i < (PermutationHolder::MaxInv(nSize) + 1); i++)
		cout << " + " << pPol[i] << "x^" << i;
	delete pPol;
}

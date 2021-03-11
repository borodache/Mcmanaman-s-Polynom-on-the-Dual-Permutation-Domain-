#include "stdafx.h"
#include "Utils.h"
#include "Permutation.h"
#include "PermutationHolder.h"

int main()
{
/*	PermutationHolder PH(3);
	PH.Permutation1.getNext();
	PH.Permutation2.getNext();
	PH.Permutation2.getNext();
	PH.Permutation1.print();
	PH.Permutation2.print();
	cout << PH.inv() << endl;
	Permutation P(4);
	P.print();
	cout << P.inv() << endl << endl;
*/
/*	Permutation P(3);
	P.getNext();P.getNext();P.getNext();P.getNext();P.getNext();P.getNext();
	P.print();
*/

/*	cout << "The known ploynoms (MacMa..): " << endl;
	for (int i = 1; i <= 6; i++)
	{
		Permutation::printPol(i);
		cout << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "The regular ploynoms: " << endl;
	for (int i = 1; i <= 6; i++)
	{
		PermutationHolder::printPol(i);
		cout << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Without Desending Series ploynoms: " << endl;
	for (int i = 1; i <= 6; i++)
	{
		PermutationHolder::printCatlan_Without_Desending_Pol(i);
		cout << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Without Asending Series ploynoms: " << endl;
	for (int i = 1; i <= 6; i++)
	{
		PermutationHolder::printCatlan_Without_Asending_Pol(i);
		cout << endl;
	}
*/
//	cout << factorial(4) << endl;
//	cout << N_Mahal_K(7, 3) << endl;
//	SearchAfterCoefficient(4, 14, 5, 27);
//	cout << "----------------------------" << endl;
//	SearchAfterCoefficient(6, 213, 5, 102);

/*
	27 18 17 3
	P_N(X) - MaxInv() - 3
	SearchAfterCoefficient(4, 82, 5, 219);
	cout << "----------------------------" << endl;
	SearchAfterCoefficient(6, 455, 7, 817);
*/

/*
//  13 8 9 8
	SearchAfterCoefficient3(4, 38, 5, 102, 7, 384);
	cout << "----------------------------" << endl;
	SearchAfterCoefficient3(6, 213, 7, 384, 8, 628);
*/

/*	There isn't any answer
	SearchAfterCoefficient4(4, 65, 7, 1625, 5, 272, 6, 739);
*/
/*	Gives an answer!
	SearchAfterCoefficient4(4, 65, 5, 272, 7, 1625);
	cout << "----------------------------" << endl;
	SearchAfterCoefficient4(5, 272, 6, 739, 7, 1625);
*/

//	SearchAfterCoefficient4(4, 65, 5, 272, 6, 739, 8, 3129);
//	cout << "----------------------------" << endl;
//	SearchAfterCoefficient4(5, 272, 6, 739, 7, 1625, 8, 3129);
/*	Catlan Checks
	Permutation p(4);
	p.getNext();p.getNext();
	p.print();
	cout << endl << p.CheckIfThereIsAsendingSeries() << endl;
*/
/*
	for (int i = 1; i <= 9; i++)
	{
		PermutationHolder::printCatlanPolinomWithoutDesending(i);
		cout << endl << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 1; i <= 9; i++)
	{
		PermutationHolder::printCatlanPolinomWithoutAsending(i);
		cout << endl << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 1; i <= 9; i++)
	{
		PermutationHolder::printCatlanThirdPolinom(i);
		cout << endl << endl;
	}
*/
//	p.getNext();p.getNext();p.getNext();
//	PermutationHolder::printCatlanPolinomWithoutDesending(10);
//	cout << Catlan(4);

//	check if new inv works!
/*	Permutation p(4);
	for(int i = 1; i <= factorial(4); i++)
	{
		p.print();
		cout << ";inv:" << p.inv(false) << endl;
		p.getNext(true);
	}
	cout << endl;
	cout << "----------------------" << endl;
	PermutationHolder::print(3);
*/

	PermutationHolder::printPol(3);
/*	for(int i = 1; i <= 9; i++)
	{
		cout << "*i - " << i << '*' << endl;
		CTracer trace;
		PermutationHolder::printCatlanPolinomWithoutDesending(i);
		cout << endl;
		cout << "------------------------------" << endl;
	}
*/
/*	CTracer trace;
	PermutationHolder::printCatlanPolinomWithoutAsending(10);
	cout << endl; */
/*
	cout << "Catlan 9: " << Catlan(9);
	cout << endl;
	cout << "N_Mahal_K(18,9): " << N_Mahal_K(18,9);
	cout << endl;
	cout << "N_NofelHal_K(18, 9): " << N_NofelHal_K(18, 9);
	cout << endl;
	cout << "factorial(9): " << factorial(9);
	cout << endl;
*/
	return 0;
}
#include <time.h>
CTracer::CTracer()
{
	time(&m_startTime);
}
CTracer::~CTracer()
{
	time_t endTime;
	time(&endTime);
	double dif = difftime(endTime, m_startTime);
	cout << "passed time (sec) " << dif << endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weijian <weijian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:00:40 by weijian           #+#    #+#             */
/*   Updated: 2025/09/20 20:02:50 by weijian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define TRY(fn) try {fn;} catch (std::exception &err) {std::cout<<err.what()<<std::endl;}
#define PRINT(os) std::cout << os << std::endl;

void constructors()
{
	Span A;
	Span B(2);
	Span C(A);
	C = B;
	
	PRINT("----CONSTRUCTORS----");
	TRY(A.addNumber(5)); // max number being 0, can't add any number
	B.addNumber(10);
	B.addNumber(15);
	TRY(B.addNumber(25)); // tried adding past 2
	C.addNumber(15);
	TRY(std::cout << A[0] << std::endl) // bad indexing
	PRINT("B[0]:" << B[0]);
	PRINT("C[0]:" << C[0]); // deep copy
	PRINT("");
}

void functionTest()
{
	PRINT("----FUNCTION TESTS----");

	/* start and end */
	Span A(2);

	PRINT("A vec size:" << A.getVec().size());
	A.addNumber(1);
	A.addNumber(2);
	A.getVec()[0] = 2; // can see that it doesn't change, this is for read only
	A[1] = 3; // this changes to allow it for better access
	// A[2] = 5; // segfault expected
	TRY(A.addNumber(3));
	PRINT(*A.getStart());
	PRINT(*(A.getEnd() - 1));
	PRINT(A);
	
	Span B(10);

	PRINT(B);
	TRY(B.fillSpan(B.getStart(), 5, 1000));
	PRINT(B);
	TRY(B.fillSpan(B.getStart(), 5, 42));
	PRINT(B);
	TRY(B.fillSpan(B.getStart(), 1, 3));

	Span C(10000000);

	PRINT(C);
	TRY(C.fillSpan(C.getStart(), 10000000, 42));
	// PRINT(C); // don't 
	TRY(C.fillSpan(C.getStart(), 1, 3));
}


int subject()
{
	PRINT("----SUBJECT----");
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	PRINT(sp.shortestSpan()); // 2
	PRINT(sp.longestSpan()); // 14
	PRINT("");
	return 0;
}

int main ()
{
	subject();
	constructors();
	functionTest();
}
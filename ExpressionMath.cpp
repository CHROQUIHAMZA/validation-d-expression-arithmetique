#include<iostream>
#include"Stack.h"
#include<vector>
using namespace std;
static bool isDigit(char c) {
	return 'a' <= c && c <= 'z';
}
static bool isOp(char c) {
	return c=='+' || c == '-' || c == '*' || c == '/';
}
static bool isOuvr(char c) {
	return c == '(' || c == '[';
}
static bool isFerm(char c) {
	return c == ')' || c == ']';
}
static char equivOfDelimiteur(char c) {
	if (c == '(') return ')';
	return ']';
}
static int natureOfCarac(char c) {
	if (isDigit(c)) return 0;
	if (isOp(c)) return 1;
	if (isOuvr(c)) return 2;
	if (isFerm(c)) return 3;
	return -1;
}
static bool isValidExpression(string expression)
{
	int sizeOfExpression = expression.length();
	Stack<char> P(sizeOfExpression);
	int a;
	for (int i = 0; i < sizeOfExpression; i++) {
		a = natureOfCarac(expression[i]);
		if (a == -1) return 0;
		
			switch (a)
			{
			case 0:
				if (i + 1 < sizeOfExpression &&  !isOp(expression[i + 1]) && !isFerm(expression[i+1]))return false;
				break;
			case 1:
				if (i == 0 || i == sizeOfExpression - 1) return false;
				if (!isDigit(expression[i + 1]) && !isOuvr(expression[i+1])) return false;

				break;
			case 2:{
				char c = equivOfDelimiteur(expression[i]);
				P.Emplier(c);
				if (i + 1 < sizeOfExpression &&  !isDigit(expression[i + 1]) && !isOuvr(expression[i + 1])) return false;
				break;
			}
			case 3 :
				if (P.isEmpty() || expression[i] != P.getHead()) return false;
				P.Depiler();
				if (i + 1 == sizeOfExpression) break;
				if (!isOp(expression[i + 1]) && !isFerm(expression[i+1])) return false;
				break;
			}
		
	}
	return P.isEmpty();
	}


// StackCalculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>

#include <cassert>
#include <process.h>
const int TABLELEN = 8;
// + - * / ( ) # ^
unsigned char PriorTable[TABLELEN][TABLELEN]={
		// '+' '-' '*' '/' '(' ')' '#' '^' 
	/*'+'*/'>','>','<','<','<','>','>','<', 
	/*'-'*/'>','>','<','<','<','>','>','<', 
	/*'*'*/'>','>','>','>','<','>','>','<', 
	/*'/'*/'>','>','>','>','<','>','>','<', 
	/*'('*/'<','<','<','<','<','=',' ','<', 
	/*')'*/'>','>','>','>',' ','>','>','>', 
	/*'#'*/'<','<','<','<','<',' ','=','<', 
	/*'^'*/'>','>','>','>','<','>','>','>'
};

float getValue(float left, unsigned char op, float right){
	switch(op){
	case '+': return left+right; 
	case '-': return left-right; 
	case '*': return left*right; 
	case '/': return left/right; 
	case '^': return pow(left,right);
	default : return 0; 
	}
}
const int OPSELEN = TABLELEN;
char OPSET[OPSELEN] = {'+','-','*','/','(',')','#','^'};
std::vector<char> V_OPSET(OPSET,OPSET+OPSELEN-1);

bool isOperator(char ch){
	for(int i=0; i<V_OPSET.size(); i++){
		if(ch == V_OPSET[i])
			return true;
	}
	return false;
}

int at(const char ch){
	for(int i=0; i<V_OPSET.size(); i++){
		if(ch == V_OPSET[i])
			return i;
	}
	return -1;
}

char precede(char pre,char next){
	assert(isOperator(pre) && isOperator(next));
	return PriorTable[at(pre)][at(next)];
}

template<typename T>
T tp(std::stack<T>* tstack){
	T result = tstack->top();
	tstack->pop();
	return result;
}

float evalueExpression(std::string evalueString){
	std::stack<char> cstack;
	cstack.push('#');
	std::stack<float> fstack;

	std::string myEvalueString = evalueString;
	myEvalueString.push_back('#');
	std::string convert;
	const char * cEvalueString = myEvalueString.c_str();
	char * looper = const_cast<char *>(cEvalueString);

	while(*looper != '#' || cstack.top() != '#'){
		if(! isOperator(*looper)){
			convert.push_back(*looper);
			looper++;
			if(isOperator(*(looper))){
				fstack.push(atof(convert.c_str()));
				convert.clear();
			}
		}else{
			switch(precede(cstack.top(),*looper))
			{
			case '<':
				cstack.push(*looper);
				looper ++;
				break;
			case '=':
				cstack.pop();
				looper ++;
				break;
			case '>':
				fstack.push(getValue(
					tp(&fstack),
					tp(&cstack),
					tp(&fstack)
					));
				break;
			default:
				break;
			}
		}
	}
	return fstack.top();
}
int _tmain(int argc, _TCHAR* argv[])
{
	std::string expression = "2^2";
	std::cout<< evalueExpression(expression) << std::endl;
	system("pause");
	return 0;
}


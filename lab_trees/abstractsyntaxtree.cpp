#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...

	std::stack<std::string> order;
    preOrdered(root,order);
    std::stack<double> calc;
    std::string temp = "";
    double a, b, result;
  
    while(!order.empty()){
    	temp = order.top();
    	order.pop();
    	if(temp=="+"){
    		a = calc.top();
    		calc.pop();
    		b = calc.top();
    		calc.pop();
    		result = a+b;
    		calc.push(result);
    	}
    	else if(temp=="-"){
    		a = calc.top();
    		calc.pop();
    		b = calc.top();
    		calc.pop();
    		result = a-b;
    		calc.push(result);
    	}
    	else if(temp=="*"){
    		a = calc.top();
    		calc.pop();
    		b = calc.top();
    		calc.pop();
    		result = a*b;
    		calc.push(result);
    	}
    	else if(temp=="/"){
    		a = calc.top();
    		calc.pop();
    		b = calc.top();
    		calc.pop();
    		result = a/b;
    		calc.push(result);
    	}
    	else calc.push(std::stod(temp));
    }
    result = calc.top();
    
    return result;
}

void AbstractSyntaxTree::preOrdered(Node * subRoot,std::stack<std::string>& order)const{
	if(subRoot==NULL){
		return;
	}
	order.push(subRoot->elem);
	preOrdered(subRoot->left,order);
	preOrdered(subRoot->right,order);
}

#pragma once
#include "Expression.h"

namespace core {

	//Interface: UnaryExpression
	template <class T>
	class BinaryExpression
	{
	public:
		BinaryExpression() {};
		virtual ~BinaryExpression() {};

		virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
	};
}
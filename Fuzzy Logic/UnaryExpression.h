#pragma once
#include "Expression.h"

namespace core 
{
	template <class T>
	class UnaryExpression
	{
	public:
		UnaryExpression() {};
		virtual ~UnaryExpression() {};

		virtual T Evaluate(Expression<T>*) const = 0;
	};
}
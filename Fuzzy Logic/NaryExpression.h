#pragma once

#include <vector>
#include "Expression.h"

namespace core
{
	template <class T>
	class NaryExpression
	{
	public:

		NaryExpression(){};

		~NaryExpression(){};

		virtual T Evaluate(std::vector<const Expression<T>*>*) const = 0;
	};
}

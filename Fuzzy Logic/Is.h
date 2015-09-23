#pragma once

#include "UnaryExpression.h"

namespace fuzzy 
{
	template <class T>
	class Is : public core::UnaryExpression<T>
	{
	public:
		virtual ~Is() {};
	};
}

#pragma once

#include "UnaryExpression.h"

namespace fuzzy {
	template <class T>
	class Not : public core::UnaryExpression<T>
	{
	public:
		virtual ~Not() {};
	};
}
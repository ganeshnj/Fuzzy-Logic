#pragma once

#include "BinaryExpression.h"

namespace fuzzy
{
	template <class T>
	class Then : public core::BinaryExpression<T>
	{
	public:
		virtual ~Then() {};
	};
}
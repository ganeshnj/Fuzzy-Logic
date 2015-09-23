#pragma once

#include "And.h"

namespace fuzzy
{
	template <class T>
	class AndMult : public And<T>
	{
	public:
		AndMult() {};
		virtual ~AndMult() {};

		virtual T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AndMult<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const
	{
		T lv = left->Evaluate();
		T rv = right->Evaluate();

		return lv*rv;
	}
}
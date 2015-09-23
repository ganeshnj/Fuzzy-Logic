#pragma once

#include "Or.h"

namespace fuzzy {
	template <class T>
	class OrPlus
	{
	public:

		OrPlus() {};
		virtual ~OrPlus() {};

		virtual T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T OrPlus<T>::Evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T lv = l->Evaluate();
		T rv = r->Evaluate();
		return lv + rv;
	}
}


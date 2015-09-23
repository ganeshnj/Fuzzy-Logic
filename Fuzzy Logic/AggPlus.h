#pragma once

#include "Agg.h"
namespace fuzzy
{
	template<class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus()
		{
		};

		~AggPlus()
		{
		};

		virtual T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	};

	template <class T>
	T AggPlus<T>::Evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		T lv = l->Evaluate();
		T rv = r->Evaluate();
		return lv+rv;
	}

}
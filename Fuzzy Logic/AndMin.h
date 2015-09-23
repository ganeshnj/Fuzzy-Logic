#pragma once
#include "And.h"

namespace fuzzy {

	template <class T>
	class AndMin : public And < T >
	{
	public:
		AndMin() {};
		virtual ~AndMin() {};
		
		virtual T Evaluate(core::Expression<T>*, core::Expression<T>*) const;
	private:

	};

	template <class T>
	T AndMin<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const 
	{
		T l = left->Evaluate();
		T r = right->Evaluate();

		return (l < r) ? l : r;
	}
}

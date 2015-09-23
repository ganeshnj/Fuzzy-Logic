#pragma once

#include "NaryExpression.h"

namespace fuzzy {
	template <class T>
	class SugenoConclusion : public core::NaryExpression<T>
	{
	public:

		SugenoConclusion(){};

		SugenoConclusion(std::vector<T>* coeff) :coeff(coeff) {};

		~SugenoConclusion(){};

		virtual T Evaluate(std::vector<const core::Expression<T>*>* operands) const;
	private:
		const std::vector<T> *coeff;
	};

	template <class T>
	T SugenoConclusion<T>::Evaluate(std::vector<const core::Expression<T>*>* operands) const
	{
		std::vector<T>::const_iterator itcoef = coeff->begin();
		std::vector<const core::Expression<T>*>::const_iterator itexpr = operands->begin();
		T z = 0;

		for (; itexpr != operands->end() && itcoef != coeff->end(); itexpr++, itcoef++)
		{
			T eval = (*itexpr)->Evaluate();
			z += (*itcoef) * eval;
		}

		return z;
	}

}


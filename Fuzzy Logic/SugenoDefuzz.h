#pragma once

#include "NaryExpression.h"
#include "BinaryExpressionModel.h"
#include "BinaryShadowExpression.h"
#include "SugenoThen.h"

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
	public:

		SugenoDefuzz(){};

		virtual T Evaluate(std::vector<const core::Expression<T>*>* operands) const;

		~SugenoDefuzz(){};
	};

	template <class T>
	T SugenoDefuzz<T>::Evaluate(std::vector<const core::Expression<T>*>* operands) const
	{
		std::vector<const core::Expression<T>*>::const_iterator it;

		T num = 0;
		T denum = 0;

		for (it = operands->begin(); it != operands->end(); it++)
		{
			num += (*it)->Evaluate();

			core::BinaryExpressionModel<T>* bem = (core::BinaryExpressionModel<T>*)  (*it);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->GetOperator();
			SugenoThen<T>* sth = (SugenoThen<T>*) bse->GetTarget();

			denum += sth->getPremiseValue();
		}

		if (denum != 0)
			return num / denum;

		return 0;
	}
}



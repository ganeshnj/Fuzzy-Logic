#pragma once

#include "NaryExpression.h"

namespace core {
	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T>
	{
	public:

		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression<T>* _operator, std::vector<const Expression<T>*>* operands) :_operator(_operator), operands(operands) {};
		virtual ~NaryExpressionModel() {};

		virtual T Evaluate() const;
		virtual T Evaluate(std::vector<const Expression<T>*>*) const;
	private:
		NaryExpression<T>* _operator;
		std::vector<const Expression<T>*>* operands;

	};

	template <class T>
	T NaryExpressionModel<T>::Evaluate() const
	{
		if (operands->empty())
			throw new std::exception("Operandes vector is empty");

		return Evaluate(operands);
	}

	template <class T>
	T NaryExpressionModel<T>::Evaluate(std::vector<const Expression<T>*>* os) const
	{
		if (_operator == NULL)
			throw new std::exception("Operaor is null");

		return _operator->Evaluate(os);
	}

}


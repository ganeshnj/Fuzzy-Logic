#pragma once
#include "Expression.h"
#include "UnaryExpression.h"

namespace core 
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel() {};
		UnaryExpressionModel(UnaryExpression<T>* _operator, Expression<T>* operand) : _operator(_operator), operand(operand) {};
		virtual ~UnaryExpressionModel() {};

		virtual T Evaluate() const;
		virtual T Evaluate(Expression*) const;

	private:
		UnaryExpression<T>* _operator;
		Expression<T>* operand;
	};

	template <class T>
	T UnaryExpressionModel<T>::Evaluate() const
	{
		if (operand == NULL)
			throw new std::exception("null operand");

		return Evaluate(operand);
	}

	template <class T>
	T UnaryExpressionModel<T>::Evaluate(Expression<T>* o) const
	{
		if (_operator == NULL)
			throw new std::exception("null operator");

		return _operator->Evaluate(o);
	}
}
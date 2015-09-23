#pragma once

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
		
	template <class T>
	class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T>
	{
	public:
		BinaryExpressionModel() {};
		BinaryExpressionModel(BinaryExpression<T>* _operator, Expression<T>* left, Expression<T>* right) : _operator(_operator), left(left), right(right) {};
		virtual ~BinaryExpressionModel() {};

		virtual T Evaluate() const;
		virtual	T Evaluate(Expression<T>*, Expression<T>*) const;

		BinaryExpression<T>* GetOperator();
		void SetOperator(BinaryExpression<T>*);

	private:
		Expression<T> *left;
		Expression<T> *right;
		BinaryExpression<T>* _operator;

	};

	template <class T>
	T BinaryExpressionModel<T>::Evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (_operator == NULL)
			throw new std::exception("null operator");

		return _operator->Evaluate(l, r);
	}

	template <class T>
	T BinaryExpressionModel<T>::Evaluate() const
	{
		if (left == NULL)
			throw new std::exception("null left operand");

		if (right == NULL)
			throw new std::exception("null right operand");

		return Evaluate(left, right);
	}

	template <class T>
	BinaryExpression<T>* BinaryExpressionModel<T>::GetOperator()
	{
		return _operator;
	}

	template <class T>
	void BinaryExpressionModel<T>::SetOperator(BinaryExpression<T>* o)
	{
		_operator = o;
	}
}
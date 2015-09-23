#pragma once

#include "BinaryExpression.h"

namespace core 
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression() {};
		BinaryShadowExpression(BinaryExpression<T>* target) :target(target) {};
		virtual ~BinaryShadowExpression() {};

		void SetTarget(BinaryExpression<T>*);
		BinaryExpression<T>* GetTarget();
		virtual T Evaluate(Expression<T>*, Expression<T>*) const;

	private:
		BinaryExpression<T>* target;
	};

	template <class T>
	void BinaryShadowExpression<T>::SetTarget(BinaryExpression<T>* _target) {
		target = _target;
	}

	template <class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::GetTarget() {
		return target;
	}

	template <class T>
	T BinaryShadowExpression<T>::Evaluate(Expression<T>* l, Expression<T>* r) const
	{
		if (target == NULL)
			throw new std::exception("null target");

		return target->Evaluate(l, r);
	}
}
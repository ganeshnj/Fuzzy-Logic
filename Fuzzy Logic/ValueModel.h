#pragma once

#include "Expression.h"

namespace core {
	template <class T>
	class ValueModel : public Expression<T> {
	public:
		ValueModel() {};
		ValueModel(const T& v) : value(v) {};
		virtual ~ValueModel() {};

		void SetValue(const T&);
		virtual T Evaluate() const;

	private:
		T value;
	};

	template <class T>
	void ValueModel<T>::SetValue(const T& v) {
		value = v;
	}

	template <class T>
	T ValueModel<T>::Evaluate() const {
		return value;
	}
}
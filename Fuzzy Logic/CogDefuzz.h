#pragma once

#include "MamdaniDefuzz.h"
#include <numeric>

namespace fuzzy 
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>
	{
	public:
		CogDefuzz() {};
		~CogDefuzz() {};

	protected:
		virtual T Defuzz(const Shape&) const;
	};

	template <class T>
	T CogDefuzz<T>::Defuzz(const Shape& s) const
	{

		T x, y, num = 0, den = 0;
		for (unsigned int i = 0; i < (s.first.size() - 1); i++){
			x = s.first.at(i);
			y = s.second.at(i);
			num += x*y;
			den += y;
		}

		return num / den;
	}
}
#pragma once

namespace core 
{
	template <class T>
	class Expression 
	{
	public:
		virtual ~Expression() {};

		virtual T Evaluate() const = 0;
	};
}
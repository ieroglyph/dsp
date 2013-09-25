#pragma once

#include "operation.h"

namespace dsp
{
	class OpMultiply
	{
		Signal _mult;
	public:
		OpMultiply(Signal& mult):
			_mult(mult)
		{

		}
		virtual const Signal operator()(Signal& s)
		{
			if (s.get_size() != _mult.get_size())
				throw("oups");
			Signal ret = Signal(s);
			for (int i = 0; i < s.get_size(); i++)
			{
				(ret)[i] *= _mult[i];
			}
			return ret;
		}
	};
	class OpAdd
	{
		Signal _add;
	public:
		OpAdd(Signal& add):
			_add(add)
		{

		}
		virtual const Signal operator()(Signal& s)
		{
			if (s.get_size() != _add.get_size())
				throw("oups");
			Signal ret = Signal(s);
			for (int i = 0; i < s.get_size(); i++)
			{
				(ret)[i] += _add[i];
			}
			return ret;
		}
	};
}
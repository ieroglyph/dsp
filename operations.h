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
		virtual void operator()(Signal& in, Signal& out)
		{
			if (in.get_size() != _mult.get_size())
				throw("oups");
			for (int i = 0; i < in.get_size(); i++)
			{
				out[i] = in[i] * _mult[i];
			}
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
		virtual void operator()(Signal& in, Signal& out)
		{
			if (in.get_size() != _add.get_size())
				throw("oups");
			for (int i = 0; i < in.get_size(); i++)
			{
				out[i] = in[i] + _add[i];
			}
		}
	};
}
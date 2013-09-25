#pragma once

#include "operation.h"

namespace dsp
{
	class OpMultiply: public Operation
	{
		Signal _mult;
	public:
		OpMultiply(Signal& mult):
			_mult(mult)
		{

		}
		virtual void operator()(Signal& s)
		{
			if (s.get_size() != _mult.get_size())
				throw("oups");
			for (int i = 0; i < s.get_size(); i++)
			{
				s[i] *= _mult[i];
			}
		}
	};
	class OpAdd: public Operation
	{
		Signal _add;
	public:
		OpAdd(Signal& add):
			_add(add)
		{

		}
		virtual void operator()(Signal& s)
		{
			if (s.get_size() != _add.get_size())
				throw("oups");
			for (int i = 0; i < s.get_size(); i++)
			{
				s[i] += _add[i];
			}
		}
	};
	class OpExtend: public Operation
	{
		int N;
	public:
		OpExtend(int N)
		{
			this->N = N;
		}
		virtual void operator()(Signal& s)
		{
			s.set_size(this->N);
		}
	};
	class OpFFT
	{

	};
}
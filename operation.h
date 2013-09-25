#pragma once

#include "signal.h"

namespace dsp
{
	class Operation
	{
	public:
		virtual void operator()(Signal& in,Signal& out) = 0;
	};
}
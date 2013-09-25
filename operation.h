#pragma once

#include "signal.h"

namespace dsp
{
	class Operation
	{
	public:
		virtual void operator()(Signal&) = 0;
	};
}
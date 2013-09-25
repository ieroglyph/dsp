#pragma once

#include "signal.h"

namespace dsp
{
	class Operation
	{
	public:
		virtual const Signal operator()(Signal&) = 0;
	};
}
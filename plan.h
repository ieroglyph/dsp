#pragma once

#include "signal.h"
#include "operation.h"
#include <vector>
#include <algorithm>

using namespace std;

namespace dsp
{
	class Plan
	{
		vector<Operation*> ops;
	public:
		void add_operation(Operation* op)
		{
			ops.push_back(op);
		};
		Signal execute(Signal& sig)
		{
			Signal ret = Signal(sig);
			for ( auto op = ops.begin(); op != ops.end(); op++ )
			{
				(*(*op))(ret,ret);
			}
			return ret;
		};
		Signal operator()(Signal& sig)
		{
			return execute(sig);
		};
		~Plan()
		{
		}
	};
}
// dsp.cpp : Defines the entry point for the console application.
//

#include "dsp.h"
#include <iostream>


int main(int argc, wchar_t* argv[])
{
	dsp::Signal s0;
	s0.set_size(1<<16);

	std::cout << s0[1<<15];
	std::cout << std::endl;

	s0[67] = Complex(15,0);

	std::cout << (s0[67] - s0[66]).real();
	std::cout << std::endl;

	dsp::Plan p;
	
	dsp::OpMultiply multic = dsp::OpMultiply(s0);
	p.add_operation((dsp::Operation*)&multic);

	dsp::OpAdd plusic = dsp::OpAdd(s0);
	p.add_operation((dsp::Operation*)&plusic);

	dsp::Signal s1 = p.execute(s0);

	dsp::OpAdd plusic2(s1);
	p.add_operation((dsp::Operation*)&plusic2);

	s1 = p.execute(s1);

	std::cout << s1[67];
	std::cout << std::endl;
	std::cout << ( 15 * 15 + 15 ) * 15 + 15 + ( 15 * 15 + 15 ) ;
	std::cout << std::endl;

	std::cout << (s0[67] - s0[66]).real();
	std::cout << std::endl;

	system("pause");
	return 0;
}


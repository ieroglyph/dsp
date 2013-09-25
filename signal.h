#pragma once

#include <complex>

#include "filelog.h"

typedef std::complex<double> Complex;

namespace dsp
{
	char signalstring[] = "Signal"; 
	class Signal: public fl::Loggale<signalstring>
	{
		Complex* data;
		unsigned int datasize;
	public:
		double sampling_rate;
		Signal(): Loggale("default",0)
		{
			this->datasize = 0;
			this->data = 0;
			sampling_rate = 0;
		}
		Signal(unsigned int datasize, double sampling_rate = 0): Loggale("params",datasize)
		{
			this->sampling_rate = sampling_rate;
			this->datasize = datasize;
			this->data = new Complex[datasize];
			memset(data,0,sizeof(Complex)*datasize);
		}
		Signal(Signal& sig2): Loggale("copy",sig2.local_i)
		{
			this->sampling_rate = sig2.sampling_rate;
			this->datasize = sig2.datasize;
			this->data = new Complex[this->datasize];
			memcpy(this->data,sig2.data,sizeof(Complex)*this->datasize);
		}
		~Signal()
		{
			delete this->data;
			this->datasize = 0;
			this->data = 0;
		}
		unsigned int get_size()
		{
			return this->datasize;
		}
		Signal& set_size(unsigned int size)
		{
			Complex* newdata = new Complex[size];
			memset(newdata,0,sizeof(Complex)*size);
			if (data != 0)
			{
				unsigned int minsize = datasize<size?datasize:size;
				memcpy(newdata,data,sizeof(Complex)*minsize);
				delete[] data;
			}
			this->data = newdata;
			this->datasize = size;
			return *this;
		}
		Signal& set_data(Complex* newdata, unsigned int newsize)
		{
			if (data != 0)
			{
				delete[] data;
			}
			this->datasize = newsize;
			data = new Complex[newsize];
			memcpy(data,newdata,sizeof(Complex)*newsize);
			return *this;
		}
		Complex& operator[](unsigned int index)
		{
			if (index < datasize)
				return data[index];
			throw("!");
		}
		Signal& operator=(const Signal& s2)
		{
			if (&s2!=this)
			{
				if (this->data!=0)
				{
					delete this->data;
					this->data = 0;
				}
				this->datasize = s2.datasize;
				if (this->datasize!=0)
				{
					this->data = new Complex[this->datasize];
				}
				if (s2.data==0)
				{
					memset(this->data,0,sizeof(Complex)*this->datasize);
				}
				else
				{
					memcpy(this->data,s2.data,sizeof(Complex)*this->datasize);
				}
			}
			return *this;
		}
	};
}
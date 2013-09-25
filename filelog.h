#pragma once

#include <fstream>
#include <string>
#include <strstream>

using namespace std;

namespace fl
{

	ofstream log = ofstream("c:\\log.txt",ios::binary);

	template<char const *cn>
	class Loggale
	{
	public:

		static int global_i;
		int local_i;
		template <typename T>
		Loggale( string method, T comment )
		{
			global_i ++;
			local_i = global_i;
			log << cn;
			log << "[" << local_i << "] ";
			log << "(" << method << " | " << comment << ")";
			log << " constructed";
			log << endl;
		}
		~Loggale()
		{
			log << cn;
			log << "[" << local_i << "] ";
			log << " destructed";
			log << endl;
		}
		template<typename T>
		void llo( T l )
		{
			log << cn;
			log << "[" << local_i << "] ";
			log << " " << l;
			log << endl;
		}
	};

	template<char const *cn> int Loggale<cn>::global_i = 0;
};


#pragma once
#include <iostream>
#include <vector>

class Inputs 
{
	private:
		struct Aux;
		Aux* aux;
	public:
		enum KeyName {
			space,
			up,
			down,
			left,
			right,
			w,
			a,
			s,
			d
		} ;

		Inputs();
		bool GetKeyState(KeyName keyName);
};


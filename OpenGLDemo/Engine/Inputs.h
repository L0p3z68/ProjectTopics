#pragma once
#include <iostream>
#include <vector>
#include "Vector2.h"

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
		enum ButtonName {
			FaceDown,
			FaceRight,
			FaceUp,
			FaceLeft
		};

		Inputs();
		bool GetKeyState(KeyName keyName);
		bool GetButtonState(ButtonName buttonName);
		Vector2 GetControllerLeftAxis();
		Vector2 GetControllerRightAxis();
		~Inputs();
};


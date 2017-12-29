/*
 * main.cpp
 *
 *  Created on: 29 Dec. 2017
 *      Author: Karl
 */

#include "Pack.h"
#include <iostream>

int main(int argc, char * argv[])
{
	Pack pack;
	pack.Shuffle();

	std::cout << "Shuffled pack is: " << std::endl;
	std::cout << pack.ToString() << std::endl;
}



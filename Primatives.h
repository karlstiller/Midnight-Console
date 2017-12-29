/*
 * Primatives.h
 *
 *  Created on: 22Dec.,2017
 *      Author: Karl
 */

#ifndef PRIMATIVES_H_
#define PRIMATIVES_H_

#include <string>

class Suit
{
	friend class Pack;

	enum Value
	{
		Spades,
		Clubs,
		Diamonds,
		Hearts,
		INVALID
	};

public:
	Suit(Value _value);
	~Suit(){};
	std::string ToString()
	{
		switch (value)
		{
		case Spades:
		{
			return std::string("Spades");
		}
		case Clubs:
		{
			return std::string("Clubs");
		}
		case Diamonds:
		{
			return std::string("Diamonds");
		}
		case Hearts:
		{
			return std::string("Hearts");
		}
		default:
			return std::string("INVALID");
		}
	}

	Suit& operator++()
    {
		switch (value)
		{
		case Spades:
		{
			value = Clubs;
			break;
		}
		case Clubs:
		{
			value = Diamonds;
			break;
		}
		case Diamonds:
		{
			value = Hearts;
			break;
		}
		case Hearts:
		{
			value = INVALID;
			break;
		}
        return *this;
    }
    }

	Suit& operator++(int)
    {
		Suit& tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

	// member variables
	Value value;
};

class Sequence
{
	friend class Pack;

	enum Value
	{
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		J,
		Q,
		K,
		A,
		INVALID
	};

public:
	Sequence(Value _value);
	~Sequence(){};
	std::string ToString()
	{
		switch (value)
		{
		case Two:
		{
			return std::string("2");
		}
		case Three:
		{
			return std::string("3");
		}
		case Four:
		{
			return std::string("4");
		}
		case Five:
		{
			return std::string("5");
		}
		case Six:
		{
			return std::string("6");
		}
		case Seven:
		{
			return std::string("7");
		}
		case Eight:
		{
			return std::string("8");
		}
		case Nine:
		{
			return std::string("9");
		}
		case Ten:
		{
			return std::string("10");
		}
		case J:
		{
			return std::string("Jack");
		}
		case Q:
		{
			return std::string("Queen");
		}
		case K:
		{
			return std::string("King");
		}
		case A:
		{
			return std::string("Ace");
		}
		default:
			return std::string("INVALID");
		}
	}

	Sequence& operator++()
    {
		switch (value)
		{
		case Two:
		{
			value = Three;
			break;
		}
		case Three:
		{
			value = Four;
			break;
		}
		case Four:
		{
			value = Five;
			break;
		}
		case Five:
		{
			value = Six;
			break;
		}
		case Six:
		{
			value = Seven;
			break;
		}
		case Seven:
		{
			value = Eight;
			break;
		}
		case Eight:
		{
			value = Nine;
			break;
		}
		case Nine:
		{
			value = Ten;
			break;
		}
		case Ten:
		{
			value = J;
			break;
		}
		case J:
		{
			value = Q;
			break;
		}
		case Q:
		{
			value = K;
			break;
		}
		case K:
		{
			value = A;
			break;
		}
		case A:
		{
			value = INVALID;
			break;
		}
        return *this;
    }
    }

	Sequence& operator++(int)
    {
		Sequence& tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }

	Value value;
};

#endif /* PRIMATIVES_H_ */

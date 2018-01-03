/*
 * Primatives.h
 *
 *  Created on: 22Dec.,2017
 *      Author: Karl
 */

#ifndef PRIMATIVES_H_
#define PRIMATIVES_H_

#include <string>
#include <cstdint>

class Suit
{
public:
	
	typedef uint8_t int_type;
	
	enum e_value
	{
		INVALID,
		Spades,
		Clubs,
		Diamonds,
		Hearts,
		Joker,
		LIMIT
	};

	Suit() : m_value(INVALID) {}
	
	Suit(e_value init) : m_value(init)	{};
	
	e_value GetValue() const { return m_value; }
	
	static bool FromInt(int_type int_val, Suit &value)
	{
	    bool result(false);

	    switch(int_val) 
	    {
	    case INVALID:
	    case Spades:
	    case Clubs:
	    case Diamonds:
	    case Hearts:
	        value.m_value = static_cast<e_value>(int_val);
	        result = true;
	        break;
	    default:
	        break;
	    }

	    return result;	
	}

	~Suit(){};
	std::string ToString() const
	{
		switch (m_value)
		{
		case Spades:
			return std::string("Spades");
		case Clubs:
			return std::string("Clubs");
		case Diamonds:
			return std::string("Diamonds");
		case Hearts:
			return std::string("Hearts");
		case Joker:
			return std::string("Joker");
		default:
			return std::string("INVALID");
		}
	}

	Suit& operator++()
    {
		switch (m_value)
		{
		case Spades:
			m_value = Clubs;
			break;
		case Clubs:
			m_value = Diamonds;
			break;
		case Diamonds:
			m_value = Hearts;
			break;
		case Hearts:
			m_value = Joker;
			break;
		case Joker:
			m_value = LIMIT;
			break;
		default:
			break;
		}
        return *this;
    }

	/*Suit& operator++(int)
    {
		Suit& tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }*/

private:
	// member variables
	e_value m_value;
};

inline bool operator ==(const Suit &a, const Suit &b)          { return a.GetValue() == b.GetValue(); }
inline bool operator ==(const Suit &a, const Suit::e_value &b) { return a.GetValue() == b; }
inline bool operator ==(const Suit::e_value &a, const Suit &b) { return a == b.GetValue(); }
inline bool operator !=(const Suit &a, const Suit &b)          { return a.GetValue() != b.GetValue(); }
inline bool operator !=(const Suit &a, const Suit::e_value &b) { return a.GetValue() != b; }
inline bool operator !=(const Suit::e_value &a, const Suit &b) { return a != b.GetValue(); }

template <typename Elem, typename Traits>
std::basic_ostream<Elem, Traits> &operator <<(
        std::basic_ostream<Elem, Traits> &os,
        const Suit &obj)
{
    return os << obj.ToString();
}

class Sequence
{
public:
	
	typedef uint8_t int_type;
	
	enum e_value
	{
		INVALID,
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
		LIMIT,
	};
	
	Sequence() : m_value(INVALID) {}

	Sequence(e_value init) : m_value(init)	{}
	
	e_value GetValue() const { return m_value; }

	~Sequence(){};
	std::string ToString() const
	{
		switch (m_value)
		{
		case Two:
			return std::string("2");
		case Three:
			return std::string("3");
		case Four:
			return std::string("4");
		case Five:
			return std::string("5");
		case Six:
			return std::string("6");
		case Seven:
			return std::string("7");
		case Eight:
			return std::string("8");
		case Nine:
			return std::string("9");
		case Ten:
			return std::string("10");
		case J:
			return std::string("Jack");
		case Q:
			return std::string("Queen");
		case K:
			return std::string("King");
		case A:
			return std::string("Ace");
		default:
			return std::string("INVALID");
		}
	}
	
	static bool FromInt(int_type int_val, Sequence &value);

	Sequence& operator++()
    {
		switch (m_value)
		{
		case Two:
			m_value = Three;
			break;
		case Three:
			m_value = Four;
			break;
		case Four:
			m_value = Five;
			break;
		case Five:
			m_value = Six;
			break;
		case Six:
			m_value = Seven;
			break;
		case Seven:
			m_value = Eight;
			break;
		case Eight:
			m_value = Nine;
			break;
		case Nine:
			m_value = Ten;
			break;
		case Ten:
			m_value = J;
			break;
		case J:
			m_value = Q;
			break;
		case Q:
			m_value = K;
			break;
		case K:
			m_value = A;
			break;
		case A:
			m_value = LIMIT;
			break;
		default:
			break;
		}

        return *this;
    }

	/*Sequence& operator++(int)
    {
		Sequence& tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }*/
private:
	e_value m_value;
};

inline bool operator ==(const Sequence &a, const Sequence &b)          { return a.GetValue() == b.GetValue(); }
inline bool operator ==(const Sequence &a, const Sequence::e_value &b) { return a.GetValue() == b; }
inline bool operator ==(const Sequence::e_value &a, const Sequence &b) { return a == b.GetValue(); }
inline bool operator !=(const Sequence &a, const Sequence &b)          { return a.GetValue() != b.GetValue(); }
inline bool operator !=(const Sequence &a, const Sequence::e_value &b) { return a.GetValue() != b; }
inline bool operator !=(const Sequence::e_value &a, const Sequence &b) { return a != b.GetValue(); }

template <typename Elem, typename Traits>
std::basic_ostream<Elem, Traits> &operator <<(
        std::basic_ostream<Elem, Traits> &os,      
        const Sequence &obj)
{
    return os << obj.ToString();
}

#endif /* PRIMATIVES_H_ */

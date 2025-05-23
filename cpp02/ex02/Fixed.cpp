#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Orthodox Canonical Form

Fixed::Fixed() : value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Fixed class - constructor functions

Fixed::Fixed(const int value)
{
	//std::cout << "int constructor called" << std::endl;
	this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	//std::cout << "float constructor called" << std::endl;
	this->value = roundf(value * (1 << fractionalBits));
}

// Fixed class - member functions

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

int Fixed::toInt(void) const
{
	return value >> fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << fractionalBits);
}

// Fixed class - comparison operator overloads

bool Fixed::operator>(const Fixed src)
{
	return this->toFloat() > src.toFloat();
}

bool Fixed::operator<(const Fixed src)
{
	return this->toFloat() < src.toFloat();
}

bool Fixed::operator>=(const Fixed src)
{
	return this->toFloat() >= src.toFloat();
}

bool Fixed::operator<=(const Fixed src)
{
	return this->toFloat() <= src.toFloat();
}

bool Fixed::operator==(const Fixed src)
{
	return this->toFloat() == src.toFloat();
}

bool Fixed::operator!=(const Fixed src)
{
	return this->toFloat() != src.toFloat();
}

// Fixed class - arithmetic operator overloads

Fixed Fixed::operator+(const Fixed src)
{
	return (this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed src)
{
	return (this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed src)
{
	return (this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed src)
{
	return (this->toFloat() / src.toFloat());
}

// Fixed class - increment & decrement operator overloads

Fixed &Fixed::operator++(void)
{
	value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void)
{
	value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Fixed class - min & max function overloads

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a.toFloat() < b.toFloat() ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a.toFloat() > b.toFloat() ? a : b;
}

// ostream insertion operator overload

std::ostream &operator<<(std::ostream &out, const Fixed &src)
{
	out << src.toFloat();
	return out;
}

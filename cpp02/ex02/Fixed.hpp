#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	value;
	static const int fractionalBits = 8;

public:
	// OCF base funcs
	Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed();
	// type constructors
	Fixed(const int value);
	Fixed(const float value);
	// member funcs
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
	// comparison operator overloads
	bool operator>(const Fixed src);
	bool operator<(const Fixed src);
	bool operator>=(const Fixed src);
	bool operator<=(const Fixed src);
	bool operator==(const Fixed src);
	bool operator!=(const Fixed src);
	// arithmetic operator overloads
	Fixed operator+(const Fixed src);
	Fixed operator-(const Fixed src);
	Fixed operator*(const Fixed src);
	Fixed operator/(const Fixed src);
	// increment & decrement operator overloads
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	// min & max function overloads
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	const static Fixed &max(const Fixed &a, const Fixed &b);
};

// std::ostream operator overload for printing Fixed objects
std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif

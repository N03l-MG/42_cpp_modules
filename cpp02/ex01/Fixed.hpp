#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	value;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &src);
	~Fixed();

	Fixed(const int value);
	Fixed(const float value);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif

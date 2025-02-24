#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact 
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	void SetFirstName(const std::string &name);
	void SetLastName(const std::string &name);
	void SetNickname(const std::string &nick);
	void SetPhoneNumber(const std::string &number);
	void SetDarkestSecret(const std::string &secret);

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
};

#endif

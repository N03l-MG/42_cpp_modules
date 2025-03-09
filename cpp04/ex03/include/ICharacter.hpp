#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria; // Forward Declaration

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;

		virtual void printInventory() = 0; // My own for extra debugging!
		// Had to add it here because of the way the official main is written.
};

#endif

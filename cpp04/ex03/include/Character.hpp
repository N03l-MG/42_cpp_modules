#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <vector> // NOTE: Due to us needing to keep track of dropped
				   // materias to delete them later (to avoid leaks),
				   // a vector is used as a dynamic storage of materia
				   // references. This is not allowed and will be commented
				   // out. I know I don't pass this but I wanted to do it
				   // anyway because it is a good learning experience!
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
		// std::vector<AMateria*> floor;
	public:
		Character(std::string const &name);
		Character(const Character &src);
		Character &operator=(const Character &src);
		~Character();

		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		void printInventory();
};

#endif

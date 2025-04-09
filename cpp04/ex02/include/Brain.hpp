/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:22 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 15:33:24 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
	// Orthodox Canon
		Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain();
	// Getter/Setter
	std::string getIdea(size_t index) const;
	void setIdea(size_t index, std::string ideaString);
};

#endif

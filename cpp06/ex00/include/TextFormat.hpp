/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TextFormat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:09:56 by kixik             #+#    #+#             */
/*   Updated: 2025/04/09 17:36:54 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTFORMAT_HPP
# define TEXTFORMAT_HPP

// Colors
# define RED       "\x1b[31m ✗ " // Error or exception
# define GREEN     "\x1b[32m 🛠 " // Construction
# define YELLOW    "\x1b[33m ⚠ " // Warning
# define BLUE      "\x1b[34m 🛈 " // Info or log
# define MAGENTA   "\x1b[35m 🗑 " // Destruction
# define CYAN      "\x1b[36m" // Title or important info
// Styles
# define BOLD      "\x1b[1m" // Construction, destruction, names and errors
# define UNDERLINE "\x1b[4m\t\t" // Titles
// Format reset
# define RESET     "\x1b[0m" // Reset back to plain white text

#endif

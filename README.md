<div align="center">
	<h1> 42 - C++ Modules (00-09) </h1>
	<p>
		<b><i> All C++ Modules from the 42 core (Almost all bonuses). </i></b>
	</p>
</div>

This is just an archive of all the mandatory C++ modules in the 42 Core Curriculum. Each one focuses on a specific feature or functionality of the language through multiple exercises. All of the present exercises are compliant with the rules except for cpp04-ex03 (which is a bit special).

## cpp00

This module aims to be an introduction to the basic syntax of C++. No fancy keywords or features unique to it are used yet except a very basic class. It is designed to be a bridge between C programming to a more object-oriented approach.

## cpp01

This is where classes are properly introduced and used. Basic construction and destruction as well as methods and attributes are used, as well as stack and head allocation mechanics in C++. At the end are a few extra exercises that delve into file manipulation and function references/pointers.

## cpp02

This module introduces the idea of classes being used as custom data types. I had to write a `Fixed` class which serves as a fixed-point number data type. Then this class overrides all the arithmetic and logical operators and ultimately gets used in a practical example. This final exercises is a puzzle about Binary Space Partitioning.

## cpp03

The main focus of this module is class inheritance. A parent class is created and then two child classes inherit methods and attributes from it as well as overriding existing methods and adding their own. Then, the last exercise is a challenge to make a diamond inheritance which requires understanding how classes are stored in memory and attributes are inherited. I solved it by way of a temporary class to avoid attribute overwrites.

## cpp04

This module is about abstraction and polymorphism. An abstract class `Animal` is created and then concrete classes `Dog` and `Cat` have to inherit and implement their own features. The last exercise is another challenge that introduces interfaces. I completed this extra exercise for the fun of it but sadly broke the rules by using a container class to store dropped `AMateria`. The reason for this is the subject specifically demands that anything dropped out of a player's inventory must not be deleted in the moment but rather at the end of execution. The only way I could come up with to do this is to use a Vector called `Floor` to store dropped items to be then deallocated at the end of the main function. The only way to do this while sticking to the rules is to implement one's own dynamic array system, which in my opinion, as absolute overkill for a simple training exercise. The point was learning interfaces and I did that!

## cpp05

Exception classes are introduced here. Try-Catch blocks are used to test from this point on. Some abstract class practice with three concrete classes as well. Overall mostly a review module with exceptions thrown in there.

## cpp06

This module introduces type casting, both static and dynamic. The first exercise is the most complex by far, asking for a scalar converter between multiple data types and a robust error handling system. The second exercise is a very simple struct serializer and the last exercise deal with some random number generation.

## cpp07

The main introduction to templates and generic types. Starting off with some basic macros and finishing with a fully functional generic array template class.

## cpp08



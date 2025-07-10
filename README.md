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

Introduction to the basics of using container structures, in particular vectors, deques and lists. Some simple exercises that involve operating iteratively on containers as well as overriding some functions into other container classes for use in those. The last exercise involves modifying the stack container class to work with an iterator.

## cpp09

The last and by far hardest module. It is mostly focused on container classes and how to find the right use case for each one. Each exercise is different in this one.

### ex00: Bitcoin Exchange
This exercise intends for us to make use of the map data structure. We can assign key-value pairs of dates and exchange rates of bitcoin provided to us in a database. Our program must be able to take an input of dates and currency (I assume dollars), check the map created from the database and return the exschanged values for each of the dates. It has to be able to find the last matching date and account for invalid dates. Yes, this includes leap years! It shoudl also handle any improper input or values. This is where the exceptions taught in [cpp05](cpp05) come in very handy.

### ex01: Reverse Polish Notation Calculator
Next up is making an RPN expression calculator. RPN is just an alternative way of writting math expressions, you can look it up for more info. Quite simply, our program takes an expression and evaluates it. The ideal container for this is a stack, for reasons that will become obvious when the RPN format is understood. Much like every other exercise, errors have to be handled.


### ex02: Ford-Johnson Sorting Algorithm Demonstration
The last and (in my opinion) most challenging exercise. This is all about exploring strengths and weaknesses between vectors and deques. We accept an input of unsorted integers and sort them using a very obscure and rather strage algorithm called the Ford-Johnson Sort, or Merge-Insertion as some people call it. The hardest part of this exercise, quite frankly, is even understanding how this algorithm works. There are no simple tutorials online, only extensive (typically VERY math-intensive) papers explaining it. In short, it is a hybrid between insertion and merge sort. It works recursively like merge-sort but only up to a certain point, after which one sorted half of the numbers is inserted in a very specific order into the other. This order involves a very special sequence of numbers called the _Jacobsthal Series_. The reason this extremely overcomplicated algorithm exists in the first place is because it is mathematically the most comparison-efficient sorting algorithm. Essentially, it uses as least comparisons between numbers as possible. Not that it is particularly fast anyway... :P

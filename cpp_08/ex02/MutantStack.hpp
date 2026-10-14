#pragma once
#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename C = std::deque<T>>
class	Mutantstack: public std::stack<T, C>
{
	public:
		Mutantstack()
		{}
		Mutantstack(const Mutantstack &other) std::stack<T, C>(other)
		{}
		Mutantstack& operator=(const Mutantstack &other)
		{
			if (this != &other)
				std::stack<T, C>::operator=(other);
			return (*this);
		}
		~Mutantstack()
		{}
		typedef typename C::iterator				iterator;
		typedef typename C::const_iterator			const_iterator;
		typedef typename C::reverse_iterator		reverse_iterator;
		typedef typename C::const_reverse_iterator	const_reverse_iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}
		iterator	end()
		{
			return (this->c.end());
		}
		const_iterator	begin() const
		{
			return (this->c.begin());
		}
		const_iterator	end() const
		{
			return (this->c.end());
		}
		reverse_iterator	begin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator	end()
		{
			return (this->c.rend());
		}
		const_reverse_iterator	begin() const
		{
			return (this-c.rbegin());
		}
		const_reverse_iterator	end() const
		{
			return (this->c.rend());
		}
};

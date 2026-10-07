#pragma once
# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		std::vector<int> vec;
		unsigned int vec_size;
	public:
		class VecLimitException: public std::exception
		{
			const char* what() const throw();
		};
		class VecSpanTooSmall: public std::exception
		{
			const char* what() const throw();
		};
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span&	operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
};

#include "Span.hpp"

Span::Span(): vec_size(0)
{}

Span::Span(unsigned int n): vec_size(n)
{}

Span::Span(const Span &other): vec_size(other.vec_size), vec(other.vec)
{}

Span& Span::operator=(const Span &other)
{
	if (this != &other)
	{
		vec = other.vec;
		vec_size = other.vec_size;
	}
	return (*this);
}

Span::~Span()
{}

const char* Span::VecLimitException::what() const throw()
{
	return ("Beyond vector size");
}

const char* Span::VecSpanTooSmall::what() const throw()
{
	return ("Vector to small");
}

void	Span::addNumber(int n)
{
	if (vec.size() != vec_size)
		vec.push_back(n);
	else
		throw VecLimitException(); 
}

int	Span::shortestSpan()
{
	if (vec_size < 2)
		throw VecSpanTooSmall();
	int currentSpan;
	int shortestSpan;

	sort(vec.begin(), vec.end());
	shortestSpan = vec[1] - vec[0];
	for (size_t i = 0; i + 1 < vec.size(); i++)
	{
		currentSpan = vec[i + 1] - vec[i];
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}
	return (shortestSpan);
}

int Span::longestSpan()
{
	if (vec_size < 2)
		throw VecSpanTooSmall();
	
}


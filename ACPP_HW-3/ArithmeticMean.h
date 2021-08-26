#pragma once
#include <numeric>
#include <list>


void AMean(std::list<double>& lst)
{
	double sum = std::accumulate(lst.begin(), lst.end(), 0.0);
	double mean = sum / lst.size();
	lst.push_back(mean);
}
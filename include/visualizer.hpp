#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include "sorting.hpp"

void showArrayState(sf::RenderWindow & window, const ArrayState & arr);

void showSortingSteps(sf::RenderWindow & window, const SortSteps & steps, int delay = 50);

#endif
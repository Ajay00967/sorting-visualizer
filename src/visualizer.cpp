#include "visualizer.hpp"
#include <thread>
#include <chrono>

void showArrayState(sf::RenderWindow & window, const ArrayState & arr) {

    window.clear(sf::Color::Black); // clear window 

    int n = arr.size();
    float barWidth = (window.getSize().x) / (n * 1.00f); // width of each bar 

    int windowHeight = window.getSize().y;
    int maxVal = *max_element(arr.begin(), arr.end());

    float scale = (float)windowHeight / maxVal;

    for (int i = 0; i < n; i++) {

        float height = arr[i] * scale * 0.95f;

        // Make each Bar
        sf::RectangleShape Bar(sf::Vector2f(barWidth - 1, -height));
        Bar.setPosition(i * barWidth, window.getSize().y);
        Bar.setFillColor(sf::Color::Yellow);

        window.draw(Bar);
    }
    
    window.display();
}

void showSortingSteps(sf::RenderWindow & window, const SortSteps & steps) {
    
    for (const auto & state : steps) {

        sf::Event event;

        while (window.pollEvent(event)) { // Handle events
            if (event.type == sf::Event::Closed) { // Closing window
                window.close();
            }
        }

        showArrayState(window, state); // show each state

        int delay = std::max(1, 1000 / (int)steps.front().size());
        // wait of `delay` ms
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));

        if (!window.isOpen()) break; // If window was closed, stop the loop :)
    }
}
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock CLOCK;

// Use color interpolation to get the current color when changing from color a to color b.
// t has to be between 0 and 1
sf::Color lerbRGB(sf::Color a, sf::Color b, float t)
{
	return sf::Color(
		(int) (a.r + (b.r - a.r) * t),
		(int) (a.g + (b.g - a.g) * t),
		(int) (a.b + (b.b - a.b) * t),
		(int) (a.a + (b.a - a.a) * t)
	);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Color");
	window.setFramerateLimit(60);
	
	int r{ 255 };
	int g{ 0 };
	int b{ 0 };
	int a{ 0 };
	
	float currentStepTime{ 0.f };
	// The time from interpoling from one to another color
	const float totalStepTime{ 1.f };
	int currentStage{ 0 };
	// The colos
	std::vector<sf::Color> colors {
		sf::Color(170, 255, 1, 255), // Green
		sf::Color(255, 170, 1, 255), // Orange
		sf::Color(255, 0, 170, 255), // Red
		sf::Color(170, 0, 255, 255), // Violet
		//sf::Color(0, 170, 255, 255)  // Blue
		sf::Color(12, 39, 146, 255)  // Blue
	};
	// The colors from which to which is interpoled
	std::vector<std::array<sf::Color, 2>> colorSteps{
		{ colors[0] , colors[1] }, // Green -> Orange
		{ colors[1] , colors[2] }, // Orange -> Red
		{ colors[2] , colors[3] }, // Red -> Violet
		{ colors[3] , colors[4] }, // Violet -> Blue
		{ colors[4] , colors[0] }, // Blue -> Green
	};

	CLOCK::time_point tp1 = CLOCK::now();
    while (window.isOpen())
    {
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		std::chrono::duration<float> timeSpan{ CLOCK::now() - tp1 };
		tp1 = CLOCK::now();
		float dt{ std::chrono::duration_cast<std::chrono::duration
			<float, std::ratio<1>>>(timeSpan).count() };
		
		currentStepTime += dt;
		float colPos{ currentStepTime / totalStepTime  };
		if (currentStepTime > totalStepTime) 
		{
			colPos = 0.f;
			currentStepTime = 0.f;
			currentStage++;
			if (currentStage > colorSteps.size() - 1)
			{
				currentStage = 0;
			}
		}
		sf::Color curCol = lerbRGB(colorSteps[currentStage][0], colorSteps[currentStage][1], colPos);
		
		window.clear(curCol);
		window.display();
    }


    return 0;
}

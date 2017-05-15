#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock CLOCK;

int increaseColorVal(int colorVal)
{
	colorVal += 1;
	if (colorVal > 255)
	{
		colorVal = 0;
	}
	return colorVal;
}

int decreaseColorVal(int colorVal)
{
	colorVal -= 1;
	if (colorVal < 0)
	{
		colorVal = 255;
	}
	return colorVal;
}

int changeColorVal(int val, bool &isIncreasing)
{
	if (isIncreasing)
	{
		val = increaseColorVal(val);
		if (val == 0)
		{
			val = 254;
			isIncreasing = false;
		}
	}
	else
	{
		val = decreaseColorVal(val);
		if (val == 255)
		{
			val = 1;
			isIncreasing = true;
		}
	}
	return val;
}

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
	
	bool r_isIncreasing{ true };
	bool g_isIncreasing{ true };
	bool b_isIncreasing{ true };
	bool a_isIncreasing{ true };
	//bool a_isIncreasing{ true };
	int r{ 255 };
	int g{ 0 };
	int b{ 0 };
	int a{ 0 };
	
	float colorChangeTimeLast{ 0.f };
	float totalRuntime{ 0.f };
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
		
		colorChangeTimeLast += dt;
		totalRuntime += dt;
		sf::Color curCol = sf::Color::White;
		if (colorChangeTimeLast > 0.01f)
		{
			curCol = lerbRGB(sf::Color::Red, sf::Color::Green, totalRuntime);
			curCol = lerbRGB(sf::Color::Red, sf::Color::Green, 0);
			/*
			r = changeColorVal(r, r_isIncreasing);
			g = changeColorVal(g, g_isIncreasing);
			b = changeColorVal(b, b_isIncreasing);
			//a = changeColorVal(a, a_isIncreasing);
			colorChangeTimeLast = 0.f;
			*/
		}

		//window.clear(sf::Color(r, g, b, a));
		window.clear(curCol);
		window.display();
    }


    return 0;
}

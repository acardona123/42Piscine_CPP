#include <iostream>

int main()
{
		std::string ideas[100];
	int i(-1);
	while (++i < 20)
		ideas[i] = "Where is the ball? #" + std::to_string(i);
	while (++i < 40)
		ideas[i] = "A bone!!! #" + std::to_string(i);
	while (++i < 60)
		ideas[i] = "If only I had a shoe to chew... #" + std::to_string(i);
	while (++i < 80)
		ideas[i] = "I'm a good boy! #" + std::to_string(i);
	while (++i < 100)
		ideas[i] = "Have I heard 'Park'? #" + std::to_string(i);
	return 0;
}
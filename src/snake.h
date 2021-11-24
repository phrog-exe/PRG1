#include <iostream> 

struct Snake {
constexpr static unsigned MAX_LIVES = 3;
unsigned lives_left { MAX_LIVES }; 
Snake() = default;
Snake(unsigned const );
};
Snake::Snake(unsigned const ll)
: lives_left{ ll }
{}

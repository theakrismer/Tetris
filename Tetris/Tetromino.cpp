#include "Tetromino.h"

Tetromino::Tetromino()
{
    setShape(TetShape::L);
}

Tetromino::Tetromino(TetShape shape) {
    setShape(shape);
}

TetColor Tetromino::getColor() const
{
    return color;
}
TetShape Tetromino::getShape() const
{
    return shape;
}

// - set the shape
// - set the blockLocs for the shape
// - set the color for the shape
void Tetromino::setShape(TetShape shape)
{
    blockLocs.clear();

    switch (shape)
    {
    case TetShape::S:
        color = TetColor::RED;
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 1));
        blockLocs.push_back(Point(-1, 0));
        break;
    case TetShape::Z:
        color = TetColor::GREEN;
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(-1, 1));
        break;
    case TetShape::L:
        color = TetColor::ORANGE;
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(0, -1));
        blockLocs.push_back(Point(1, -1));
        break;
    case TetShape::J:
        color = TetColor::BLUE_DARK;
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(-1, -1));
        blockLocs.push_back(Point(0, -1));
        break;
    case TetShape::O:
        color = TetColor::YELLOW;
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(1, 1));
        blockLocs.push_back(Point(1, 0));
        break;
    case TetShape::I:
        color = TetColor::BLUE_LIGHT;
        blockLocs.push_back(Point(0, -1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(0, 1));
        blockLocs.push_back(Point(0, 2));
        break;
    case TetShape::T:
        color = TetColor::PURPLE;
        blockLocs.push_back(Point(0, -1));
        blockLocs.push_back(Point(0, 0));
        blockLocs.push_back(Point(1, 0));
        blockLocs.push_back(Point(-1, 0));
        break;
    }
    this->shape = shape;
}

// gets a random shape for use on the board
// returns a TetShape
TetShape Tetromino::getRandomShape() {
    return static_cast<TetShape>(rand() % 7);
}

// rotate the shape 90 degrees around [0,0] (clockwise)
// to do this:
// - iterate through blockLocs
// - rotate each Point 90 degrees clockwise around [0,0]
// hint: as you rotate the point [1,2] clockwise around [0,0], note
// how the x,y values change. Once you find the pattern you can use
// a couple existing methods in the Point class to accomplish this.
// make it so that the TetShape::O doesn’t rotate
void Tetromino::rotateClockwise()
{
    if (shape == TetShape::O)
        return;

    for (int i = 0; i < blockLocs.size(); i++)
    {
        blockLocs.at(i).multiplyX(-1);
        blockLocs.at(i).swapXY();
    }
}

// print a grid to display the current shape
// to do this: print out a “grid” of text to represent a co-ordinate
// system. Start at top left [-3,3] go to bottom right [3,-3]
// (use nested for loops)
// for each [x,y] point, loop through the blockLocs and if the point exists
// in the list, print an 'x' instead of a '.'. You should end up with something
// like this: (results will vary depending on shape and rotation, eg: this
// one shows a T shape rotated clockwise once)
// .......
// .......
// ...x...
// ..xx...
// ...x...
// .......
void Tetromino::printToConsole() const
{
    for (int y = 3; y >= -3; y--)
    {
        for (int x = -3; x <= 3; x++)
        {
            bool found = false;
            for (Point p : blockLocs)
            {
                if (p.getX() == x && p.getY() == y)
                {
                    found = true;
                    std::cout << 'x';
                }
            }
            if (!found)
                std::cout << '.';
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
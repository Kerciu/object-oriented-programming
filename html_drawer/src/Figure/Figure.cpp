#include "Figure.h"
#include <iostream>

Figure::Figure() : x(150), y(100), fill(""), stroke("") { }

Figure::Figure(const color& colorValue) : x(150), y(100), fill(colorValue), stroke("")
{
    if (!isFillable())
    {
        fill = "";
        stroke = colorValue;
    }
}

Figure::Figure(const color& fill, const color& stroke) : x(150), y(100), fill(fill), stroke(stroke) { }

Figure::Figure(const coordinate& x, const color& colorValue)
 : x(x), y(100), fill(colorValue), stroke("")
{
    if (!isFillable())
    {
        fill = "";
        stroke = colorValue;
    }
}

Figure::Figure(const coordinate& x, const coordinate& y, const color& colorValue)
 : x(x), y(y), fill(colorValue), stroke("")
{
    if (!isFillable())
    {
        fill = "";
        stroke = colorValue;
    }
}

Figure::Figure(const coordinate& x, const color& fill, const color& stroke)
 : x(x), y(100), fill(fill), stroke(stroke) { }

Figure::Figure(const coordinate& x, const coordinate& y, const color& fill, const color& stroke) 
 : x(x), y(y), fill(fill), stroke(stroke) { }

inline Figure::svgFormat Figure::draw() const
{
    return svgFormat("");
}

inline Figure::color Figure::getFill() const {
    return fill;
}

inline Figure::color Figure::getStroke() const {
    return stroke;
}

inline void Figure::setX(const size& newX)
{
    x = newX;
}

inline void Figure::setY(const size& newY)
{
    y = newY;
}

inline Figure::size Figure::getX() const {
    return x;
}

inline Figure::size Figure::getY() const {
    return y;
}

inline void Figure::setFill(const color& f)
{
    fill = f;
}

inline void Figure::setStroke(const color& s)
{
    stroke = s;
}

inline bool Figure::isFillable() const {
    return true;
}

bool Figure::operator==(const Figure& other) const
{
    return (this->fill == other.fill) && (this->stroke == other.stroke) && (this->x == other.x) && (this->y == other.y);
}

std::ostream& operator<<(std::ostream& os, const Figure& figure)
{
    os << figure.draw();
    return os;
}

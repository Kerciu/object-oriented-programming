#include "DerivedFigures.h"

Rectangle::Rectangle(const color& fill, const size& width) : Figure(fill, ""), width(width), height(width) { }

Rectangle::Rectangle(const color& fill, const size& width, const size& height) : Figure(fill, ""), width(width), height(height) { }

Rectangle::Rectangle(const color& fill, const color& stroke, const size& width) : Figure(fill, stroke), width(width), height(width) { }

Rectangle::Rectangle(const color& fill, const color& stroke, const size& width, const size& height) : Figure(fill, stroke), width(width), height(height) { }

Rectangle::Rectangle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& width)
	: Figure(x, y, fill, stroke), width(width), height(width) { }

Rectangle::Rectangle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& width, const size& height)
	: Figure(x, y, fill, stroke), width(width), height(height) { }

Circle::Circle(const color& fill, const size& radius) : Figure(fill, ""), radius(radius) { }

Circle::Circle(const color& fill, const color& stroke, const size& radius) : Figure(fill, stroke), radius(radius) { }

Circle::Circle(const coordinate& x, const coordinate& y, const color& fill, const size& radius)
	: Figure(x, y, fill), radius(radius) { }

Circle::Circle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& radius)
	: Figure(x, y, fill, stroke), radius(radius) { }

Line::Line(const color& stroke) : Figure(stroke), x2(0), y2(0), strokeWidth(1)
{
	this->setStroke(stroke);
	this->setFill("");
}

Line::Line(const coordinate& x, const coordinate& y, const color& stroke)
	: Figure(x, y, stroke), x2(0), y2(0), strokeWidth(1)
{
	this->setStroke(stroke);
	this->setFill("");
}

Line::Line(const coordinate& x, const coordinate& y, const color& stroke, const int& strokeWidth)
	: Figure(x, y, stroke), x2(0), y2(0), strokeWidth(strokeWidth)
{
	this->setStroke(stroke);
	this->setFill("");
}

Line::Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& stroke)
	: Figure(x, y, stroke), x2(x2), y2(y2), strokeWidth(1)
{
	this->setStroke(stroke);
	this->setFill("");
}

Line::Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& stroke, const int& strokeWidth)
	: Figure(x, y, stroke), x2(x2), y2(y2), strokeWidth(strokeWidth)
{
	this->setStroke(stroke);
	this->setFill("");
}

Text::Text(const color& fill, const content& textContent)
	: Figure(fill), fontFamily("Arial"), fontSize(11), textContent(textContent), textAnchor("") { }

Text::Text(const color& fill, const content& textContent, const anchor& textAnchor)
	: Figure(fill, ""), fontFamily("Arial"), fontSize(11), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const color& fill, const size& fontSize, const content& textConten, const anchor& textAnchor)
	: Figure(fill), fontSize(fontSize), fontFamily("Arial"), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const color& fill, const family& fontFamily, const content& textContent, const anchor& textAnchor)
	: Figure(fill), fontSize(11), fontFamily(fontFamily), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor)
	: Figure(fill), fontSize(fontSize), fontFamily(fontFamily), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const content& textContent, const anchor& textAnchor)
	: Figure(x, y, fill), fontSize(11), fontFamily("Arial"), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const size& fontSize, const content& textContent, const anchor& textAnchor)
	: Figure(x, y, fill), fontSize(fontSize), fontFamily("Arial"), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const content& textContent, const anchor& textAnchor)
	: Figure(x, y, fill), fontSize(11), fontFamily(fontFamily), textContent(textContent), textAnchor(textAnchor) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor)
	: Figure(x, y, fill), fontSize(fontSize), fontFamily(fontFamily), textContent(textContent), textAnchor(textAnchor) { }

Text::family Text::getFontFamily() const
{
	return fontFamily;
}

Text::size Text::getFontSize() const
{
	return fontSize;
}

 Text::anchor Text::getTextAnchor() const
{
	return textAnchor;
}

 Text::content Text::getTextContent() const
{
	return textContent;
}

 void Text::setFontFamily(const family& newFontFam)
{
	fontFamily = newFontFam;
}

 void Text::setFontSize(const size& newFontSize)
{
	if(!(newFontSize < 0)) fontSize = newFontSize;
}

 void Text::setTextAnchor(const anchor& newAnchor)
{
	textAnchor = newAnchor;
}

 void Text::setTextContent(const content& newContent)
{
	textContent = newContent;
}

 Figure::svgFormat Rectangle::draw() const
{
	 //TODO add x, y (optional), width, height, 
	 // Figure::svgFormat desired = "<rect width=\"300\" height=\"100\" fill=\"red\" />";
	 Figure::svgFormat resultFormat = "<rect ";
	 if (x != 0) resultFormat += "x=\"" + std::to_string(x) + "\" ";
	 if (y != 0) resultFormat += "y=\"" + std::to_string(y) + "\" ";
	 resultFormat += "width=\"" + std::to_string(width) + "\" ";
	 resultFormat += "height=\"" + std::to_string(height) + "\" ";
	 if (fill != "") resultFormat += "fill=\"" + fill + "\" ";
	 if (stroke != "") resultFormat += "stroke=\"" + stroke + "\" ";
	 resultFormat += "/>";
	 // <rect  x = "10" y = "10" width = "280" height = "180" fill = "none" stroke = "blue" / >
	 return resultFormat;
}

 Rectangle::size Rectangle::getWidth() const
{
	return width;
}

 Rectangle::size Rectangle::getHeight() const
{
	return height;
}

 void Rectangle::setWidth(const size& newWidth)
{
	width = newWidth;
}

 void Rectangle::setHeight(const size& newHeight)
{
	height = newHeight;
}

 Figure::svgFormat Circle::draw() const
{
	//TODO add cx, cy, r parameters for circle, make stroke optional
	// Figure::svgFormat desired = "<circle cx=\"150\" cy=\"100\" r=\"80\" fill=\"green\" />";
	Figure::svgFormat resultFormat = "<circle ";
	if (x != 0) resultFormat += "cx=\"" + std::to_string(x) + "\" ";
	if (y != 0) resultFormat += "cy=\"" + std::to_string(y) + "\" ";
	resultFormat += "r=\"" + std::to_string(radius) + "\" ";
	if (fill != "") resultFormat += "fill=\"" + fill + "\" ";
	if (stroke != "") resultFormat += "stroke=\"" + stroke + "\" ";
	resultFormat += "/>";
	return resultFormat;
}

 Figure::size Circle::getRadius() const
{
	return radius;
}

 void Circle::setRadius(const size& newRadius)
{
	if (!(newRadius < 0)) radius = newRadius;
}

 Line::coordinate Line::getX2() const {
	return x2;
}

 Line::coordinate Line::getY2() const {
	return y2;
}

 void Line::setX2(const Line::coordinate& newX2) {
	x2 = newX2;
}

 void Line::setY2(const Line::coordinate& newY2) {
	y2 = newY2;
}

 int Line::getStrokeWidth() const {
	return strokeWidth;
}

 void Line::setStrokeWidth(const int& newStrokeWidth) {
	if (!(newStrokeWidth < 0)) strokeWidth = newStrokeWidth;
}

 Figure::svgFormat Line::draw() const
{
	//TODO add x1, y1, x2, y2, stroke-width
	// Figure::svgFormat desired = "<line x1=\"50\" y1=\"50\" x2=\"250\" y2=\"150\" stroke=\"black\" stroke-width=\"2\" />";
	Figure::svgFormat resultFormat = "<line ";
	if (x != 0) resultFormat += "x1=\"" + std::to_string(x) + "\" ";
	if (y != 0) resultFormat += "y1=\"" + std::to_string(y) + "\" ";
	if (x2 != 0) resultFormat += "x2=\"" + std::to_string(x2) + "\" ";
	if (y2 != 0) resultFormat += "y2=\"" + std::to_string(y2) + "\" ";
	if (stroke != "") resultFormat += "stroke=\"" + stroke + "\" ";
	if (strokeWidth != 1) resultFormat += "stroke-width=\"" + std::to_string(strokeWidth) + "\" ";
	resultFormat += "/>";
	return resultFormat;
}

 Figure::svgFormat Text::draw() const
{
	Figure::svgFormat resultFormat = "<text ";
	if (x != 0) resultFormat += "x=\"" + std::to_string(x) + "\" ";
	if (y != 0) resultFormat += "y=\"" + std::to_string(y) + "\" ";
	resultFormat += "font-size=\"" + std::to_string(fontSize) + "\" ";
	resultFormat += "font-family=\"" + fontFamily + "\" ";
	if (textAnchor != "") resultFormat += "text-anchor=\"" + textAnchor + "\" ";
	if (fill != "") resultFormat += "fill=\"" + fill + "\" ";
	resultFormat += ">" + textContent + "</text>";
	return resultFormat;
}

Figure::color Line::getFill() const
{
	return Figure::color("");
}

bool Line::isFillable() const
{
	return false;
}



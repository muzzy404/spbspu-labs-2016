#ifndef SHAPES_H
#define SHAPES_H

#include <istream>
#include <memory>  // shared_ptr

class Shape
{
public:
  Shape(int x, int y) :
    x_(x), y_(y) {};
  virtual ~Shape() // to work with dynamic memory
  {};
  int x() const { return x_; };
  int y() const { return y_; };
  bool isMoreLeft(const Shape &) const;
  bool isUpper(const Shape &)    const;
  virtual void draw()            const = 0;
protected:
  int x_, y_;
};

class Circle : public Shape
{
public:
  Circle(int x, int y) :
    Shape(x,y) {};
  virtual void draw() const override;
};

class Triangle : public Shape
{
public:
  Triangle(int x, int y) :
    Shape(x,y) {};
  virtual void draw() const override;
};

class Square : public Shape
{
public:
  Square(int x, int y) :
    Shape(x,y) {};
  virtual void draw() const override;
};

std::istream & operator>>(std::istream &, std::shared_ptr<Shape> &);

#endif // SHAPES_H

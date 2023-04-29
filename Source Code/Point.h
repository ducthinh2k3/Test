#pragma once
class Point
{
public:
    int x, y;
    Point();
    Point getDirection(Point step);
    bool operator==(Point other);
    Point operator+(const Point&p);
};

Point::Point()
{
    x = y = 0;
}

Point Point::getDirection(Point step)
{
    Point direction;
    if (this->x == step.x)
    {
        direction.x = 0;
    }
    else
    {
        if (step.x > this->x)
            direction.x = 1;
        else
            direction.x = -1;
    }

    if (this->y == step.y)
    {
        direction.y = 0;
    }
    else
    {
        if (step.y > this->y)
            direction.y = 1;
        else
            direction.y = -1;
    }
    return direction;
}

bool Point::operator==(Point other)
{
    if (this->x == other.x && this->y == other.y)
        return true;
    return false;
}

Point Point::operator+(const Point &p)
{
    Point result;
    result.x = this->x + p.x;
    result.y = this->y + p.y;
    return result;
}  

#include "turtle.h"
#include <iostream>
#include <cmath>

using namespace std;

Turtle::Turtle(double x0, double y0, double direction0)
{
	x_coord = x0;
	y_coord = y0;
	direction_angle = direction0;
	color = draw::BLACK;
	transp = 0;
}

void Turtle::move(double distance)
{
	double x = x_coord + (distance*cos(direction_angle*(M_PI/180)));
	double y = y_coord + (distance*sin(direction_angle*(M_PI/180)));
	draw::setcolor(color);
	draw::settransparency(transp);
	draw::line(x_coord, y_coord, x, y);

	x_coord = x;
	y_coord = y;
}

void Turtle::turn(double degrees)
{
	direction_angle = direction_angle + degrees;
}

void Turtle::setColor(Color c)
{
	color = c;
}

void Turtle::on()
{
	transp = 0;
}

void Turtle::off()
{
	transp = 1;
}

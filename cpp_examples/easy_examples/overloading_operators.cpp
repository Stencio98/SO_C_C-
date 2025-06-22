#include <iostream>

class Point{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
	
	Point operator+(const Point& p){
		return Point(x + p.x, y + p.y);
	}
};

int main(){
	std::cout << "+ defined as sum between points(x,y)\n";
	Point p1(1,2), p2(3,4);
	Point p3 = p1 + p2;
	std::cout << "p3: (" << p3.x << " , " << p3.y << ")\n";
}

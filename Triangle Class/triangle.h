class Triangle
{
public:
	Triangle(int s, char b = '#', char f = '*'); //constructor

	int GetSize() const;             //accessors
	int Perimeter() const;
	double Area() const;

	void Grow();                     //mutators
	void Shrink();
	void SetBorder(char newBorder);
	void SetFill(char newFill);

	void Draw() const;               //also accessors
	void Summary() const;

private:
	int sideLength;
	char border;
	char fill;

};

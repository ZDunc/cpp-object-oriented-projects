class Temperature
{

public:

//constructors
Temperature();
Temperature(double deg, char s);

void Input();
void Show() const;

bool Set(double deg, char s);

//accessors
double GetDegrees() const;
char GetScale() const;

bool SetFormat(char f);
bool Convert(char sc);

int Compare(const Temperature& d) const;

private:
double temp;
char scale;
char format;

};

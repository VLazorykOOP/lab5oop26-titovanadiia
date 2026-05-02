#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//===========================
//==========TASK1============
//===========================
class Triangle {
protected:
    double a, b, c;

public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void setside(double a, double b, double c) {
        if (a + b > c && a + c > b && b + c > a) {
            this->a = a;
            this->b = b;
            this->c = c;
            cout << "side changed succesful" << endl;
        }
        else {
            cout << "error" << endl;
        }
    }
    double perimetr() {
        return a + b + c;
    }
    void angles() {
        double A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
        double B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
        double C = 180 - A - B;
        cout << "A" << A << "degrees" << endl;
        cout << "B" << B << "degrees" << endl;
        cout << "C" << C << "degrees" << endl;
    }
    virtual void print() {
        cout << "triangle: a = " << a << "b = " << b << "c = " << c << endl;
    }
};
class RightAngled : public Triangle {
private:
    double area;

public:
    RightAngled(double a, double b) : Triangle(a, b, sqrt(a* a + b * b)) {
        area = 0;
    }
    double clasAr() {
        area = (a * b) / 2;
        return area;
    }
    void print() override {
        cout << "Right Angle, a= " << a << ",b= " << b << ",c= " << c << endl;
    }
};

//===========================
//==========TASK2============
//===========================
class Tail {
private:
    double len;
public:
    Tail() {
        len = 0;
        cout << "Tail: default constructor" << endl;
    }
    Tail(double len) {
        this->len = len;
        cout << "Tail: constructor with parametr" << endl;
    }
    double getlen() {
        return len;
    }
    void setlen(double len) {
        this->len = len;
    }
};
class Dog {
private:
    Tail tail;
    char* color;
    int age;
public:
    Dog() {
        color = new char[10];
        strcpy(color, "unknow");
        age = 0;
        cout << "Dog: default constructor" << endl;
    }
    Dog(double taillen, const char* color, int age) : tail(taillen) {
        this->color = new char[strlen(color) + 1];
        strcpy(this->color, color);
        this->age = age;
        cout << "Dog: constructor with parametr" << endl;
    }
    ~Dog() {
        delete[] color;
        cout << "Dog: destructor";
    }
    char* getcolor() {
        return color;
    }
    int getage() {
        return age;
    }
    double gettaillen() {
        return tail.getlen();
    }
};

//===========================
//==========TASK3============
//===========================
class Education {
protected:
    char* school;
    int year;
public:
    Education() {
        school = new char[20];
        strcpy(school, "unknow");
        year = 0;
        cout << "Education: default constructor" << endl;
    }
    Education(const char* school, int year) {
        this->school = new char[strlen(school) + 1];
        strcpy(this->school, school);
        this->year = year;
        cout << "Education: constructor with parametr" << endl;
    }
    Education(const Education& other) {
        school = new char[strlen(other.school) + 1];
        strcpy(school, other.school);
        year = other.year;
        cout << "Education: copy constructor " << endl;
    }
    Education& operator=(const Education& other) {
        if (this != &other) {
            delete[] school;
            school = new char[strlen(other.school) + 1];
            strcpy(school, other.school);
            year = other.year;
            cout << "Education: operator assignment" << endl;
        }
        return *this;
    }
    virtual ~Education() {
        delete[] school;
        cout << "Education: destructor";
    }
    virtual ostream& print(ostream& out) const {
        out << "School: " << school << endl;
        out << "Year of completion: " << year << endl;
        return out;
    }
    virtual istream& input(istream& in) {
        char buf[100];
        cout << "enter school name: ";
        in >> buf;
        delete[] school;
        school = new char[strlen(buf) + 1];
        strcpy(school, buf);
        cout << "enter year of completion: ";
        in >> year;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Education& e) {
        return e.print(out);
    }
    friend istream& operator>>(istream& in, Education& e) {
        return e.input(in);
    }
};
class HighEdu : public Education {
private:
    char* specialty;
    char* degree;
public:
    HighEdu() : Education() {
        specialty = new char[20];
        degree = new char[20];
        strcpy(specialty, "unknown");
        strcpy(degree, "unknown");
        cout << "HighEdu: default constructor" << endl;
    }
    HighEdu(const char* school, int year,
        const char* specialty, const char* degree)
        : Education(school, year)
    {
        this->specialty = new char[strlen(specialty) + 1];
        this->degree = new char[strlen(degree) + 1];
        strcpy(this->specialty, specialty);
        strcpy(this->degree, degree);
        cout << "HighEdu: constructor with parametr" << endl;
    }
    HighEdu(const HighEdu& other) : Education(other) {
        specialty = new char[strlen(other.specialty) + 1];
        degree = new char[strlen(other.degree) + 1];
        strcpy(specialty, other.specialty);
        strcpy(degree, other.degree);
        cout << "HighEdu: copy constructor" << endl;
    }
    HighEdu& operator=(const HighEdu& other) {
        if (this != &other) {
            Education::operator=(other);
            delete[] specialty;
            delete[] degree;
            specialty = new char[strlen(other.specialty) + 1];
            degree = new char[strlen(other.degree) + 1];
            strcpy(specialty, other.specialty);
            strcpy(degree, other.degree);
            cout << "HighEdu: operator assignment" << endl;
        }
        return *this;
    }
    ~HighEdu() {
        delete[] specialty;
        delete[] degree;
        cout << "HighEdu: destructor" << endl;
    }
    ostream& print(ostream& out) const override {
        Education::print(out);
        out << "Specialty: " << specialty << endl;
        out << "Degree:       " << degree << endl;
        return out;
    }
    istream& input(istream& in) override {
        Education::input(in);
        char buf[100];
        cout << "enter specialty: ";
        in >> buf;
        delete[] specialty;
        specialty = new char[strlen(buf) + 1];
        strcpy(specialty, buf);
        cout << "enter degree: ";
        in >> buf;
        delete[] degree;
        degree = new char[strlen(buf) + 1];
        strcpy(degree, buf);
        return in;
    }
};

//===========================
//==========MENU=============
//===========================
void runTask1() {
    cout << "\n--- TASK 1: Triangle ---" << endl;
    double a, b, c;
    cout << "Enter sides a b c: ";
    cin >> a >> b >> c;

    Triangle t(a, b, c);
    t.print();
    cout << "Perimeter: " << t.perimetr() << endl;
    t.angles();

    cout << "\nChange sides? (1-yes / 0-no): ";
    int ch; cin >> ch;
    if (ch) {
        cout << "Enter new sides a b c: ";
        cin >> a >> b >> c;
        t.setside(a, b, c);
        t.print();
    }

    cout << "\n--- Right Angled Triangle ---" << endl;
    cout << "Enter two legs a b: ";
    cin >> a >> b;
    RightAngled rt(a, b);
    rt.print();
    cout << "Perimeter: " << rt.perimetr() << endl;
    rt.angles();
    cout << "Area: " << rt.clasAr() << endl;
}

void runTask2() {
    cout << "\n--- TASK 2: Dog ---" << endl;
    double tailLen;
    char color[50];
    int age;
    cout << "Enter tail length: ";  cin >> tailLen;
    cout << "Enter color: ";        cin >> color;
    cout << "Enter age: ";          cin >> age;

    Dog dog(tailLen, color, age);
    cout << "\n--- Dog info ---" << endl;
    cout << "Color:       " << dog.getcolor() << endl;
    cout << "Age:         " << dog.getage() << endl;
    cout << "Tail length: " << dog.gettaillen() << endl;
}

void runTask3() {
    cout << "\n--- TASK 3: Education ---" << endl;
    HighEdu h1;
    cin >> h1;
    cout << "\n--- Entered data ---" << endl;
    cout << h1;

    cout << "\n--- Copy constructor ---" << endl;
    HighEdu h2(h1);
    cout << h2;

    cout << "\n--- Assignment operator ---" << endl;
    HighEdu h3;
    h3 = h1;
    cout << h3;
}

int main() {
    int choice;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1 - Triangle" << endl;
        cout << "2 - Dog" << endl;
        cout << "3 - Education" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1: runTask1(); break;
        case 2: runTask2(); break;
        case 3: runTask3(); break;
        case 0: cout << "Exit..." << endl; break;
        default: cout << "Wrong choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
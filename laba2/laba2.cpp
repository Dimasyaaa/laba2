#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imag;

public:
    //конструктор
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() const {
        return real;
    }

    double getImag() const {
        return imag;
    }

    //сложение
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    ComplexNumber operator+(double value) const {
        return ComplexNumber(real + value, imag);
    }

    //вычитание
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    ComplexNumber operator-(double value) const {
        return ComplexNumber(real - value, imag);
    }

    //умножение
    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    ComplexNumber operator*(double value) const {
        return ComplexNumber(real * value, imag * value);
    }

    //деление
    ComplexNumber operator/(const ComplexNumber& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return ComplexNumber((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    ComplexNumber operator/(double value) const {
        return ComplexNumber(real / value, imag / value);
    }

    //сопряженное
    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imag);
    }

    //степень
    ComplexNumber pow(int exponent) const {
        ComplexNumber result(1, 0);
        for (int i = 0; i < exponent; ++i) {
            result = result * (*this);
        }
        return result;
    }

    //корень (через триганометрическую форму комплексного числа)
    ComplexNumber sqrt() const {
        double magnitude = std::sqrt(real * real + imag * imag);
        double angle = atan2(imag, real) / 2;
        return ComplexNumber(std::sqrt(magnitude) * cos(angle), std::sqrt(magnitude) * sin(angle));
    }

    //сравнение по модулю
    bool operator==(const ComplexNumber& other) const {
        return abs(real * real + imag * imag - (other.real * other.real + other.imag * other.imag)) < 1e-9;
    }

    bool operator!=(const ComplexNumber& other) const {
        return !(*this == other);
    }

    bool operator<(const ComplexNumber& other) const {
        return real * real + imag * imag < other.real * other.real + other.imag * other.imag;
    }

    bool operator>(const ComplexNumber& other) const {
        return real * real + imag * imag > other.real * other.real + other.imag * other.imag;
    }

    bool operator<=(const ComplexNumber& other) const {
        return !(*this > other);
    }

    bool operator>=(const ComplexNumber& other) const {
        return !(*this < other);
    }

    //сравнение по модулю с числом
    bool operator==(double value) const {
        double modulus = std::sqrt(real * real + imag * imag);
        return abs(modulus - value) < 1e-9;
    }

    bool operator!=(double value) const {
        return !(*this == value);
    }

    bool operator<(double value) const {
        double modulus = std::sqrt(real * real + imag * imag);
        return modulus < value;
    }

    bool operator>(double value) const {
        double modulus = std::sqrt(real * real + imag * imag);
        return modulus > value;
    }

    bool operator<=(double value) const {
        return !(*this > value);
    }

    bool operator>=(double value) const {
        return !(*this < value);
    }

    //вывод в алгебраической форме
    void printAlgebraic() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i";
    }

    //вывод в тригонометрической форме
    void printTrigonometric() const {
        double magnitude = std::sqrt(real * real + imag * imag);
        double angle = atan2(imag, real);
        cout << magnitude << " * (cos(" << angle << ") + i*sin(" << angle << "))";
    }

    //вывод в показательной форме
    void printExponential() const {
        double magnitude = std::sqrt(real * real + imag * imag);
        double angle = atan2(imag, real);
        cout << magnitude << " * e^(i*" << angle << ")";
    }

    // Перегрузка оператора префиксного инкремента (++)
    ComplexNumber& operator++() {
        ++real; 
        return *this; // Возвращаем текущий объект
    }

    // Перегрузка оператора постфиксного инкремента (++)
    ComplexNumber operator++(int) {
        ComplexNumber temp = *this; 
        ++imag; 
        return temp; 
    }

    // Перегрузка оператора префиксного декремента (--)
    ComplexNumber& operator--() {
        --real; 
        return *this; // Возвращаем текущий объект
    }

    // Перегрузка оператора постфиксного декремента (--)
    ComplexNumber operator--(int) {
        ComplexNumber temp = *this; // Сохраняем текущее значение
        --imag; 
        return temp; 
    }

    //перегрузка оператора вывода в стандартный поток
    friend ostream& operator<<(ostream& os, const ComplexNumber& cn) {
        cout << cn.real << (cn.imag >= 0 ? " + " : " - ") << abs(cn.imag) << "i";
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    double r1, i1, r2, i2;

    // Ввод первого комплексного числа
    cout << "Введите действительную часть первого комплексного числа: ";
    cin >> r1;
    cout << "Введите мнимую часть первого комплексного числа: ";
    cin >> i1;
    ComplexNumber a(r1, i1);

    // Ввод второго комплексного числа
    cout << "Введите действительную часть второго комплексного числа: ";
    cin >> r2;
    cout << "Введите мнимую часть второго комплексного числа: ";
    cin >> i2;
    ComplexNumber b(r2, i2);

    ComplexNumber x(a); // Копируем a в x для дальнейшего использования.

    cout << "Первое число(а): " << a << endl;
    cout << "Второе число(b): " << b << endl;
    cout << "Третье число(= первому, для проверки): " << x << endl;
    cout << endl;

    cout << "Операции с числом:  " << endl;
    ComplexNumber c = a + b;
    cout << "a + b = " << c << endl;
    ComplexNumber d = a + 2.43;
    cout << "a + 2.43 = " << d << endl;
    ComplexNumber e = a - b;
    cout << "a - b = " << e << endl;
    ComplexNumber f = a - 5.67;
    cout << "a - 5.67 = " << f << endl;
    ComplexNumber g = a * b;
    cout << "a * b = " << g << endl;
    ComplexNumber h = a * 2.43;
    cout << "a * 2.43 = " << h << endl;
    ComplexNumber i = a / b;
    cout << "a / b = " << i << endl;
    ComplexNumber j = a / 2.43;
    cout << "a / 2.43 = " << j << endl;

    ComplexNumber k = b.conjugate();
    cout << "Сопряженность:  " << endl;
    cout << "b (сопряженное) = " << k << endl;

    ComplexNumber l = a.pow(4);
    cout << "Возведение в степень: : " << endl;
    cout << "a^4 = " << l << endl;

    ComplexNumber m = a.sqrt();
    cout << "Корень: " << endl;
    cout << "sqrt(a) = " << m << endl;

    cout << "Сравнения: " << endl;
    cout << "a == b -> " << (a == b) << endl;
    cout << "a == x -> " << (a == x) << endl;
    cout << "a == 3 -> " << (a == ComplexNumber(3, 0)) << endl;
    cout << "a != b -> " << (a != b) << endl;
    cout << "a != x -> " << (a != x) << endl;
    cout << "a != 3 -> " << (a != ComplexNumber(3, 0)) << endl;
    cout << "a > b -> " << (a > b) << endl;
    cout << "a < b -> " << (a < b) << endl;
    cout << "a < 3 -> " << (a < 3) << endl;
    cout << "a >= b -> " << (a >= b) << endl;
    cout << "a <= b -> " << (a <= b) << endl;
    cout << "a <= 3 -> " << (a <= 3) << endl;

    cout << "Префиксы и постфиксы: " << endl;
    cout << "а после префиксного инкремента: " << ++a << endl;
    cout << "а после постфиксного инкремента: " << a++ << endl; 
    cout << "Теперь а: " << a << endl;
    cout << "b после префиксного декремента: " << --b << endl;
    cout << "b после постфиксного декремента: " << b-- <<endl; 
    cout << "Теперь b: " << b << endl;

    cout << "Вывод в алгебраической форме: " << endl;
    cout << "a = ";
    a.printAlgebraic();
    cout << endl;
    cout << "b = ";
    b.printAlgebraic();
    cout << endl;

    cout << "Вывод в триганометрической форме: " << endl;
    cout << "a = ";
    a.printTrigonometric();
    cout << endl;
    cout << "b = ";
    b.printTrigonometric();
    cout << endl;

    cout << "Вывод в показательной форме: " << endl;
    cout << "a = ";
    a.printExponential();
    cout << endl;
    cout << "b = ";
    b.printExponential();
    cout << endl;

    return 0;
}

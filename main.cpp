#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Order {  
private:
    int m_orderId;
    double m_amount;
    string m_status;

public:

    Order() : m_orderId(0), m_amount(0.0), m_status("New") {
        cout << "Замовлення створено." << endl;
    }


    Order(int number, double amount, string status)
        : m_orderId(number), m_amount(amount), m_status(status) {
        cout << "Замовлення створено з параметрами." << endl;
    }


    ~Order() {
        cout << "Замовлення видалено." << endl;
    }


    Order& setOrderNumber(int number) {
        m_orderId = number;
        return *this;
    }

    Order& setAmount(double amount) {
        m_amount = amount;
        return *this;
    }

    Order& setStatus(string status) {
        m_status = status;
        return *this;
    }


    void completeOrder() {
        m_status = "Completed";
        cout << "Замовлення виконано." << endl;
    }


    void printOrderDetails() const {
        cout << "Order ID: " << m_orderId << endl;
        cout << "Amount: " << m_amount << endl;
        cout << "Status: " << m_status << endl << endl;
    }
};

int main() {

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    Order order1;
    order1.setAmount(150.75)
          .setOrderNumber(101)
          .setStatus("Processing");
    order1.printOrderDetails();

    order1.completeOrder();
    order1.printOrderDetails();


    Order order2(10, 250.50, "Pending");
    order2.printOrderDetails();

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Employee struct to hold employee information
struct Employee {
    string name;
    double hourlyRate;
    double hoursWorked;
    double grossPay;
    double taxes;
    double netPay;
};

int main() {
    // Create a vector to store employee information
    vector<Employee> employees;

    // Get employee information from the user
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        Employee emp;
        cout << "Enter employee " << i+1 << " name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Enter " << emp.name << "'s hourly rate: ";
        cin >> emp.hourlyRate;
        cout << "Enter " << emp.name << "'s hours worked: ";
        cin >> emp.hoursWorked;
        employees.push_back(emp);
    }

    // Calculate payroll for each employee
    for (Employee& emp : employees) {
        emp.grossPay = emp.hourlyRate * emp.hoursWorked;
        emp.taxes = emp.grossPay * 0.25; // Assuming a 25% tax rate
        emp.netPay = emp.grossPay - emp.taxes;
    }

    // Display payroll information
    cout << "\nPayroll Report:\n";
    cout << setw(20) << "Name" << setw(15) << "Hourly Rate" << setw(15) << "Hours Worked" << setw(15) << "Gross Pay" << setw(15) << "Taxes" << setw(15) << "Net Pay" << endl;
    cout << setw(20) << "----" << setw(15) << "----------" << setw(15) << "------------" << setw(15) << "--------" << setw(15) << "-----" << setw(15) << "-------" << endl;

    for (const Employee& emp : employees) {
        cout << setw(20) << emp.name << setw(15) << fixed << setprecision(2) << emp.hourlyRate << setw(15) << emp.hoursWorked << setw(15) << emp.grossPay << setw(15) << emp.taxes << setw(15) << emp.netPay << endl;
    }

    return 0;
}
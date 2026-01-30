// S -> Single Responsibility Principle i.e., a class should have only one responsibility to change
#include<iostream>
using namespace std;

class Employee {
private:
    string name;
    string email;
    double baseSalary;
public:
    Employee(const string& name, const string& email, double salary){
        this->name = name;
        this->email = email;
        this->baseSalary = salary;
    }

    string getName() const {
        return name;
    }
    string getEmail() const {
        return email;
    }
    double getBaseSalary() const {
        return baseSalary;
    }
};

class PayrollCalculator {
public:
    double calculateNetPay(const Employee& employee){
        double base = employee.getBaseSalary();
        double tax = base * 0.2;  // sample tax logic
        double benefit = 1000;
        return base - tax + benefit;
    }
};


class EmployeeRepository {
public:
    void save(const Employee& employee){
        cout << "Saving Employee " << employee.getName() << " to database..";
    }
};


class PayslipGenerator {
public:
    string generatePayslip(const Employee& employee, double netPay){
        string payslip = "Payslip for: " + employee.getName() + "\n";
        payslip += "Email: " + employee.getEmail() + "\n";
        payslip += "Net Pay: " + to_string(netPay) + "\n";
        payslip += "..................................\n";
        return payslip;
    }
};


class EmailService {
public:
    void sendPaySlip(const Employee& employee, const string& payslip){
        cout << "Sending payslip to: " << employee.getEmail() << endl;
        cout << payslip;
    }
};


void demoS(){
    Employee emp{"Alice", "alice@example.com", 60000.0};

    PayrollCalculator payrollCalculator;
    double netPay = payrollCalculator.calculateNetPay(emp);

    EmployeeRepository repository;
    repository.save(emp);
    cout << endl;

    PayslipGenerator payslipGenerator;
    string payslip = payslipGenerator.generatePayslip(emp, netPay);

    EmailService emailService;
    emailService.sendPaySlip(emp, payslip);
}
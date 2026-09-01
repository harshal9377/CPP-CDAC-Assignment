#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee
{
private:

    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;

public:

    // Constructor
    Employee()
    {
        empId = 1001 + employeeCount;
        employeeCount++;

        name = "";
        department = "";
        grade = 'D';
        basicSalary = 10001;
        isActive = true;
    }

    // Setter - Name
    void setName(const string& n)
    {
        if (n.empty())
        {
            cout << "ERROR: Name cannot be empty." << endl;
            return;
        }

        name = n;
    }

    // Setter - Department
    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department."
                 << endl;
        }
    }

    // Setter - Grade
    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' ||
            g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D."
                 << endl;
        }
    }

    // Setter - Salary
    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between "
                 << "Rs.10,000 and Rs.5,00,000. "
                 << "Value rejected." << endl;
        }
    }

    // Deactivate employee
    void deactivate()
    {
        isActive = false;
    }

    // Getters
    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    // Allowances
    double computeAllowances() const
    {
        switch (grade)
        {
        case 'A':
            return basicSalary * 0.40;

        case 'B':
            return basicSalary * 0.30;

        case 'C':
            return basicSalary * 0.20;

        case 'D':
            return basicSalary * 0.10;
        }

        return 0;
    }

    // Gross salary
    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    // Tax
    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
        {
            return 0;
        }
        else if (gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 + (gross - 100000) * 0.20;
        }
    }

    // Net salary
    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    // Payslip
    void printPayslip() const
    {
        cout << "============================================"
             << endl;

        cout << "       EMPLOYEE PAYSLIP — AUG 2026"
             << endl;

        cout << "============================================"
             << endl;

        cout << "Emp ID       : " << empId << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Grade        : " << grade << endl;
        cout << "Status       : "
             << (isActive ? "Active" : "Inactive")
             << endl;

        cout << "--------------------------------------------"
             << endl;

        cout << fixed << setprecision(2);

        cout << "Basic Salary : Rs. "
             << basicSalary << endl;

        cout << "Allowances   : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary : Rs. "
             << computeGrossSalary() << endl;

        cout << "--------------------------------------------"
             << endl;

        cout << "Tax Deduction: Rs. "
             << computeTax() << endl;

        cout << "Net Salary   : Rs. "
             << computeNetSalary() << endl;

        cout << "============================================"
             << endl;
    }

    // Accept details
    void acceptDetails()
    {
        string tempName;
        string tempDepartment;
        char tempGrade;
        double tempSalary;

        cout << "Enter name: ";
        getline(cin >> ws, tempName);
        setName(tempName);

        cout << "Enter department: ";
        getline(cin >> ws, tempDepartment);
        setDepartment(tempDepartment);

        cout << "Enter grade: ";
        cin >> tempGrade;
        setGrade(tempGrade);

        cout << "Enter basic salary: ";
        cin >> tempSalary;
        setBasicSalary(tempSalary);
    }

    // Static getter
    static int getEmployeeCount()
    {
        return employeeCount;
    }
};

// Initialize static member
int Employee::employeeCount = 0;


int main()
{
    // Stack object
    Employee e1;

    // Heap objects
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Accept details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    /*
        empId and basicSalary are private members.
        They cannot be accessed directly from main().
        This protects the internal employee data.
        The public setters/getters provide controlled access.
    */

    // e1.empId = 999;
    // ERROR: empId is private.

    // e1.basicSalary = -1000;
    // ERROR: basicSalary is private.

    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Simulate resignation
    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;

    // Free heap memory
    delete e2;
    delete e3;

    return 0;
}
/* 
Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%
*/

#include <iostream>
using namespace std;

class LoanHelper
{
    const float interestRate;
    float loanTaken;
    int months;

public:
    LoanHelper() : interestRate(0.0), loanTaken(0.0), months(0) {}
    LoanHelper(float rate, float loan, int m) : interestRate(rate), loanTaken(loan), months(m) {}

    void setLoanTaken(float loan) { loanTaken = loan; }

    float calculateRepayment()
    {
        float repayment;
        repayment = (loanTaken / months) * (1 + (interestRate / 100));
        return repayment;
    }

    void displayRepaymentDetails()
    {

        cout << "You have to pay " << calculateRepayment() << " every month for " << months << " months to repay your loan." << endl;
    }
};

int main()
{
    LoanHelper l1(0.5, 12000, 12);
    l1.displayRepaymentDetails();

    LoanHelper l2(0.3, 25000, 24);
    l2.displayRepaymentDetails();

    LoanHelper l3(0.4, 5000, 6);
    l3.displayRepaymentDetails();

    return 0;
}
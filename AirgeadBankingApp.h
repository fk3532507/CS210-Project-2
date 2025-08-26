#ifndef AIRGEAD_BANKING_APP_H_
#define AIRGEAD_BANKING_APP_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>


class AirgeadBankingApp {
public:
    //  constractor
    AirgeadBankingApp();

    
    void RunProgram();

private:
    // variables to store user-provided data.
    double m_initialInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Core application functionality.
    void GetUserInput(double& t_initialInvestment, double& t_monthlyDeposit,
                      double& t_annualInterest, int& t_numberOfYears);
    void DisplayDataInputScreen();
    void DisplayReports();
    void CalculateAndDisplayWithoutDeposits();
    void CalculateAndDisplayWithDeposits();
    void PrintReportHeader(const std::string& t_title);
    void ClearScreen();
};

#endif // AIRGEAD_BANKING_APP_H_
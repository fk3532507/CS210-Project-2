/* MD Mezbah Uddin Farhan
     08/10/2025
*/

#include "AirgeadBankingApp.h"
#include <limits>
#include <ios>

//  constractor.
AirgeadBankingApp::AirgeadBankingApp() :
    m_initialInvestmentAmount(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterest(0.0),
    m_numberOfYears(0) {}


void AirgeadBankingApp::ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Display the input screen.
void AirgeadBankingApp::DisplayDataInputScreen() {
    std::cout << "**********************************" << std::endl;
    std::cout << "********** Data Input ************" << std::endl;
    std::cout << "Initial Investment Amount: " << std::endl;
    std::cout << "Monthly Deposit: " << std::endl;
    std::cout << "Annual Interest: " << std::endl;
    std::cout << "Number of years: " << std::endl;
    std::cout << "**********************************" << std::endl;
}


void AirgeadBankingApp::PrintReportHeader(const std::string& t_title) {
    std::cout << "\n   " << t_title << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << "  Year" << std::setw(20) << "Year End Balance" 
              << std::setw(30) << "Year End Earned Interest" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
}

// Get user input.
void AirgeadBankingApp::GetUserInput(double& t_initialInvestment, double& t_monthlyDeposit,
                                     double& t_annualInterest, int& t_numberOfYears) {
    while (true) {
        ClearScreen();
        DisplayDataInputScreen();

        std::cout << "Initial Investment Amount: ";
        std::cin >> t_initialInvestment;

        std::cout << "Monthly Deposit: ";
        std::cin >> t_monthlyDeposit;

        std::cout << "Annual Interest: ";
        std::cin >> t_annualInterest;

        std::cout << "Number of years: ";
        std::cin >> t_numberOfYears;

        if (std::cin.fail() || t_initialInvestment < 0 || t_monthlyDeposit < 0 || 
            t_annualInterest < 0 || t_numberOfYears <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter positive numbers." << std::endl;
            std::cout << "Press Enter to try again...";
            std::cin.get();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

// Calculate & display without deposits (monthly compounding).
void AirgeadBankingApp::CalculateAndDisplayWithoutDeposits() {
    double currentBalance = m_initialInvestmentAmount;

    PrintReportHeader("Balance and Interest Without Additional Monthly Deposits");

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearEndInterest = 0.0;
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = currentBalance * ((m_annualInterest / 100) / 12);
            currentBalance += monthlyInterest;
            yearEndInterest += monthlyInterest;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(6) << year 
                  << std::setw(20) << "$" << currentBalance
                  << std::setw(20) << "$" << yearEndInterest << std::endl;
    }
}

// Calculate & display with deposits (monthly compounding).
void AirgeadBankingApp::CalculateAndDisplayWithDeposits() {
    double currentBalance = m_initialInvestmentAmount;

    PrintReportHeader("Balance and Interest With Additional Monthly Deposits");

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearEndInterest = 0.0;
        for (int month = 1; month <= 12; ++month) {
            currentBalance += m_monthlyDeposit;
            double monthlyInterest = currentBalance * ((m_annualInterest / 100) / 12);
            currentBalance += monthlyInterest;
            yearEndInterest += monthlyInterest;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::setw(6) << year 
                  << std::setw(20) << "$" << currentBalance
                  << std::setw(20) << "$" << yearEndInterest << std::endl;
    }
}

// Display both reports.
void AirgeadBankingApp::DisplayReports() {
    ClearScreen();
    CalculateAndDisplayWithoutDeposits();
    std::cout << std::endl;
    CalculateAndDisplayWithDeposits();
}

// Main program loop.
void AirgeadBankingApp::RunProgram() {
    char continueChar;
    do {
        GetUserInput(m_initialInvestmentAmount, m_monthlyDeposit, m_annualInterest, m_numberOfYears);
        DisplayReports();
        std::cout << "\nPress 'q' to quit, or any other key to enter new data: ";
        std::cin >> continueChar;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continueChar != 'q' && continueChar != 'Q');
}

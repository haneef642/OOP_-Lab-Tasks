#include <iostream>
using namespace std;

int main() {
    string movieName;
    double adultTicketPrice, childTicketPrice;
    int adultTicketsSold, childTicketsSold;
    double donationPercentage;

    cout << "Enter the movie name: ";
    getline(cin, movieName);

    cout << "Enter the adult ticket price: $";
    cin >> adultTicketPrice;

    cout << "Enter the child ticket price: $";
    cin >> childTicketPrice;

    cout << "Enter the number of adult tickets sold: ";
    cin >> adultTicketsSold;

    cout << "Enter the number of child tickets sold: ";
    cin >> childTicketsSold;

    cout << "Enter the percentage of gross amount to be donated: ";
    cin >> donationPercentage;

    double grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    double amountDonated = (grossAmount * donationPercentage) / 100;
    double netSale = grossAmount - amountDonated;

    long long int grossAmountInt = grossAmount * 100;
    grossAmount = grossAmountInt / 100.0;

    long long int amountDonatedInt = amountDonated * 100;
    amountDonated = amountDonatedInt / 100.0;

    long long int netSaleInt = netSale * 100;
    netSale = netSaleInt / 100.0;

    cout.precision(2);
    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "Movie Name: " << movieName << endl;
    cout << "Number of Tickets Sold: " << adultTicketsSold + childTicketsSold << endl;
    cout << "Gross Amount:                $ " << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated: " << donationPercentage << "%" << endl;
    cout << "Amount Donated:                $ " << amountDonated << endl;
    cout << "Net Sale:                      $ " << netSale << endl;

    return 0;
}


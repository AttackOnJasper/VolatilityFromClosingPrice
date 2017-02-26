#include "Function.h"
#include <cmath>
using namespace std;

int main() {
    const int numOfStocks = 4;
    const int dataSize = 22;
    double data[numOfStocks][dataSize];
    double *series[numOfStocks];
    const string basePath = "histData/";
    ofstream ofs(basePath + "covariance.dat");
    ofstream ofs1(basePath + "volatility.dat");
    ofs1 << "Stock ticker   Annualized return volatility" << endl;
    const string stockNames[] = {"GE", "XOM", "AAPL", "IBM"};
    
    // read data & calculate daily return series
    for (int i = 0; i < numOfStocks; i++) {
        read_data(basePath + stockNames[i] + ".txt", data[i]);
        series[i] = daily_return(data[i], dataSize);
    }
    for (int i = 0; i < numOfStocks; i++) {
        // calculate covariance matrix
        for (int j = 0; j < numOfStocks; j++) {
            ofs << 252*getCovariance(series[i], series[j], dataSize - 1) << " ";
        }
        // calculate volatility
        ofs1 << stockNames[i] << "      "
             << sqrt(252*getCovariance(series[i], series[i], dataSize - 1))
             << endl;
        ofs << endl;
    }
    for (int i = 0; i < numOfStocks; i++) {
        delete []series[i];
    }
    return 0;
}

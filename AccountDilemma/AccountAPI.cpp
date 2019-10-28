/****************************************************************************/
//
//  AccountAPI.cpp
//  Project: Account Dilemma
//
//  Created by GianLuka23 on 18/10/2019.
//  Copyright © 2019 MacBook. All rights reserved.
//   The problem, as stated, is similar in its description to the idea of the Subset Sum Problem. Connversely, the goal here is to find, if any, a combination among the input values which, summed up, give the target number.  The combinatorial approach is exploited in the proposed solution which computes the partial sum of all the possible combination and builds subsets of growing size among the available input data, by comparing the actual sum with the target value. For this purpose, a recursive function is designed with the goal in mind of finding, if any, the first combination meeting the target sum. The project has been written by respecting the standard C++11 with some additional features from C++14 and C++17. Developed in an Apple XCode IDE environment and built by a an Apple LLVM compiler version 10.0.1 (clang-1001.0.46.4)
//
/****************************************************************************/
/// @file    AccountAPI.cpp
/// @author  Gianluca Marano
/// @date    20.10.2019
///
// C++ AccountAPI.cpp implementation
/****************************************************************************/

#include "AccountAPI.hpp"

AccountAPI::AccountAPI(std::string filePath)
    : fileName(filePath), iBankTransfer(.00), iSolutionFound(false){}

void AccountAPI::printOUTFile(){
    std::ofstream file;
    file.open ("/Users/macbook/Desktop/output.txt");
        if (file.is_open()) {
            if(!getPaymentsListGivingBankTransfer().empty()){
                for (auto & payment : getPaymentsListGivingBankTransfer()){
                       file<<payment<<"\n";
                }
            } else {
                file<<"No solution";
            std::cout<<"Unable to create output file"<<std::endl;
            }
            file.close();
        }
}

void AccountAPI::readINFile()
{
    std::ifstream infile;
    infile.open(fileName);
    if (infile.is_open()) {
        infile >> iBankTransfer;
        double payment;
        while (infile >> payment)
        {
                iDuePaymentsList.push_back(payment);
            
        }
    }
    else {
        std::cout << "Unable to open the file: " << fileName << std::endl;
    }
    infile.close();
}

void AccountAPI::combinationUtil(std::vector<double> data, int start, int end, int index, int r)
{
    /** @brief the recursive stack reaches its end when the temporary index used to scan the sequence is increased up to the length of the input vector data. The flag is set to true if the sum of the elements included into the current combination sums up to the target
      */
    if (index == r)
    {
        double sum = std::accumulate(data.begin(),data.end(),.00);

        auto print = [](double& elem) { std::cout<<elem<<"\t"; };

        std::for_each(data.begin(), data.end(), print);
        std::cout <<" = "<< sum << std::endl;

        if (sum == iBankTransfer)
        {
            IPaymentsListGivingBankTrasfer=std::move(data);
            iSolutionFound = true;
        }
        return;
    }

    /** @brief Replaces index with all possible elements. The condition "end-i+1 >= r-index" makes sure that, by including one element at a time, we guarantee to perform all the combinations with the remaining elements at remaining positions
       */
    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data.at(index) = iDuePaymentsList.at(i);
        combinationUtil(data, i+1, end, index+1, r);
        if ( iSolutionFound )
        {
            return;
        }
    }
}

void AccountAPI::combination(int n, int r)
{
    /** @brief Progressively builds combination of growing size
     */
    std::vector<double> data(r);
    combinationUtil(data, 0, n-1, 0, r);
}


bool AccountAPI::findPaymentsGivingBankTransfer()
{

    /** @brief with n the number of elements in the sequence 
      */
    int n = static_cast<int> (iDuePaymentsList.size());

    /** @brief k is the number of element taken in the current combination
      */
    for ( int k = 1; k <= n; k++)
    {
        combination(n, k);
        if ( iSolutionFound )
        {
            return true;
        }
    }
    return false;
}

double AccountAPI::getBankTransfer()
{
    return iBankTransfer;
}

std::vector<double> AccountAPI::getDuePayments()
{
    return iDuePaymentsList;
}

std::vector<double> AccountAPI::getPaymentsListGivingBankTransfer()
{
    return IPaymentsListGivingBankTrasfer;
}

//possible enhancements: introduce a new support class in order to comply with the single responsability principle, add lambda functions

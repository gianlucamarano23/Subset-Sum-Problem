/****************************************************************************/
//
//  main.cpp
//  Project: Account Dilemma
//
//  Created by GianLuka23 on 18/10/2019.
//  Copyright © 2019 MacBook. All rights reserved.
//   The problem, as stated, is similar in its description to the idea of the Subset Sum Problem. Connversely, the goal here is to find, if any, at least a combination among the input values which, summed up, give the target number.  The combinatorial approach is exploited in the proposed solution which computes the partial sum of all the possible combination and builds subsets of growing size among the available input data, by comparing the actual sum with the target value. For this purpose, a recursive function is designed with the goal in mind of finding, if any, the first combination meeting the target sum. The project has been written by respecting the standard C++11 with some additional features from C++14 and C++17. Developed in an Apple XCode IDE environment and built by a an Apple LLVM compiler version 10.0.1 (clang-1001.0.46.4)
//
/****************************************************************************/
/// @file    main.cpp
/// @author  Gianluca Marano
/// @date    20.10.2019
///
// C++ main.cpp implementation
/****************************************************************************/

#include "AccountAPI.hpp"
#include <iostream>

int main(int argc, char *argv[])
{

   AccountAPI accountAPI("/Users/macbook/Desktop/prova.txt");
    accountAPI.readINFile();
    
    std::cout << "Target bank transfer value: "<< accountAPI.getBankTransfer() << std::endl;
    std::cout << "Due payments list: " ;

    for (auto & payment : accountAPI.getDuePayments()){
        std::cout << payment << " ";
        
    }
    std::cout<<std::endl;

    if ( accountAPI.findPaymentsGivingBankTransfer() )
    {
        std::cout << "Due payments combination giving the target bank transfer amount: " ;
        for (auto & payment : accountAPI.getPaymentsListGivingBankTransfer()){
            std::cout << payment << " ";
    
        }
        accountAPI.printOUTFile();
    }
    else
    {
        accountAPI.printOUTFile();
        std::cout << "No due payments combination found !" ;
    }

    std::cout << std::endl;

    return 0;
    
}

/****************************************************************************/
//
//  AccountAPI.hpp
//  Project: Account Dilemma
//
//  Created by GianLuka23 on 18/10/2019.
//  Copyright © 2019 MacBook. All rights reserved.
//   The problem, as stated, is similar in its description to the idea of the Subset Sum Problem. Connversely, the goal here is to find, if any, a combination among the input values which, summed up, give the target number.  The combinatorial approach is exploited in the proposed solution which computes the partial sum of all the possible combination and builds subsets of growing size among the available input data, by comparing the actual sum with the target value. For this purpose, a recursive function is designed with the goal in mind of finding, if any, the first combination meeting the target sum. The project has been written by respecting the standard C++11 with some additional features from C++14 and C++17. Developed in an Apple XCode IDE environment and built by a an Apple LLVM compiler version 10.0.1 (clang-1001.0.46.4)
//
/****************************************************************************/
/// @file    AccountAPI.hpp
/// @author  Gianluca Marano
/// @date    20.10.2019
///
// C++ AccountAPI.hpp implementation
/****************************************************************************/

#ifndef AccountAPI_hpp
#define AccountAPI_hpp

// ===========================================================================
// including modules
// ===========================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

// ===========================================================================
// class definition
// ===========================================================================
/** @class AccountAPI
 * @brief The class is meant to solve the account dilemma problem as stated in the project description
 *  */

class AccountAPI{
    
public:
    /** @brief Constructor
     */
    AccountAPI(std::string filePath);
    AccountAPI();
    
    /** @brief Destructor
     */
    virtual ~AccountAPI() {}
    
    /** @brief Method meant to trait input data file
      */
    void readINFile();
    
    /** @brief Method meant to print the solution in the outpuit file
      */
    void printOUTFile();

    /** @brief Method determining the existence of a solution
      */
    bool findPaymentsGivingBankTransfer();
    
    /** @brief Getter method for double iBankTransfer;
      */
    double getBankTransfer();
    
    /** @brief Getter method for std::vector<double> iDuePaymentsList{};
      */
    std::vector<double> getDuePayments();
    
    /** @brief Getter method for std::vector<double> IPaymentsListGivingBankTrasfer{};
     */
    std::vector<double> getPaymentsListGivingBankTransfer();

    
private:
    std::string fileName = " ";
    std::vector<double> iDuePaymentsList;
    std::vector<double> IPaymentsListGivingBankTrasfer;
    double iBankTransfer;
    bool iSolutionFound;

    /** @brief Utility private recursive method meant to check for the target eventually being met by the partial combinations
     * @param[in] data Input data sequence
     * @param[in] start Starting point
     * @param[in] end Ending point
     * @param[in] index Current index in the temp sequence
     * @param[in] r Length of the current combination
     */
    void combinationUtil(std::vector<double> data, int start, int end, int index, int r);
    
    /** @brief Utility private method computing successive combinations of size r out of a sequence of n elements
     * @param[in] n Number of elements in the sequence
     * @param[in] r Length of the current combination
     */
    void combination(int n, int r);

};

#endif /* AccountAPI.hpp */


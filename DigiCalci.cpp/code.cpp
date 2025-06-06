//DigiCalci : A digital calculator for solving mathematical calculations.
#include <iostream> //handles input and output
#include <vector> //allows the use of dynamic arrays
#include <cmath> //provides math functions
using namespace std;

int main(){
    int n;
    char op;

    cout<< "----------------Welcome to the Digital Calculator----------------" << endl ;
    cout<< "Enter number of operands : " << endl;
    cin>> n ;
    
    //Two numbers must be present for calculation
    if(n < 2){
        cout<< "Error! You need to enter atleast two numbers."<< endl ;
        return 0;
    }

    //Prints the below statement for the operator selection by user
    cout<< "Enter an operator(+, -, *, /, %, ^): "<< endl;
    cin>> op;

    //'%' operator is only performed with integer type
    if(op== '%'){
        vector<int> numbers(n);
           cout<<"Enter "<< n << " integers: " << endl;
           for(int i = 0; i < n; i++){
             cin>> numbers[i];
           }
        int result = numbers[0];
        for(int i=1 ; i<n ; i++){
          if(numbers[i]==0){
             cout<<"Error! (Division by zero)"<< endl;
             return 0;
          }
          result %= numbers[i];
        }
        cout << "Result: "<< result << endl;
    }
    //For rest of the operators type "double" is used
    else{
        vector<double> numbers(n);
        cout<<"Enter "<< n << " numbers: "<< endl;
        for(int i = 0; i < n; i++){
          cin >> numbers[i];
        }
    
        double result = numbers[0] ;
   
        //Predefined cases for operators
        switch(op){
          case '+':
            for(int i=1 ; i < n; i++){
                result += numbers[i];
            }
            break;

          case '-':
           for(int i=1; i < n; i++){
             result -= numbers[i];
           }
           break;

          case '*':
            for(int i=1; i<n; i++){
             result *= numbers[i];
           }
           break;

          case '/':
             for(int i=1; i<n; i++){
              if(numbers[i]==0){
                cout<<"Error : Division by zero"<<endl;
                return 0;
             }
             else{
                result /= numbers[i];
             }
          }
          break;

          case '^':
            for(int i=1; i<n; i++){
              result = pow(result, numbers[i]) ;
            }
            break ;

          default:
           cout<< "Invalid Operator entered!" << endl;
           return 0;
        }
        cout << "Result: " << result << endl; //Prints the result
      }
  return 0;
}

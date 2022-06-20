// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Custom exception
struct customException : public std::exception{
  virtual const char *what() const throw(){
    return "Custom exception works!";
  }
};

bool do_even_more_custom_application_logic(){
  // TODO: Throw any standard exception
  throw std::bad_exception();

  std::cout << "Running Even More Custom Application Logic." << std::endl;

  return true;
}

void do_custom_application_logic(){
  // TODO: Wrap the call to do_even_more_custom_application_logic()
  //  with an exception handler that catches std::exception, displays
  //  a message and the exception.what(), then continues processing
  std::cout << "Running Custom Application Logic." << std::endl;

  try{
    if(do_even_more_custom_application_logic()){
      std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
    }
  }

  catch(const std::exception &exception){
    std::cerr << "Exception Message: " << exception.what() << std::endl;
  }

  // TODO: Throw a custom exception derived from std::exception
  //  and catch it explictly in main
  throw customException();

  std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den){
  // TODO: Throw an exception to deal with divide by zero errors using
  //  a standard C++ defined exception
  if(den == 0){
    throw std::runtime_error("divide by zero is illegal");
  }

  return (num / den);
}

void do_division() noexcept{
  //  TODO: create an exception handler to capture ONLY the exception thrown
  //  by divide.
  float numerator = 10.0f;
  float denominator = 0;

  try{
    auto result = divide(numerator, denominator);
    std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
  }

  catch(const std::exception &exception){
    std::cerr << "Exception Message: " << exception.what() << std::endl;
  }
}

int main(){
  //Wrapping of whole main function via try catch
  try{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.

    do_division();
    do_custom_application_logic();
  }

  //Custom Exception - prints "Exception Message: " + what the exception is, then goes to a newline.
  catch (const customException& exception) {
      std::cerr << "Exception Message: " << exception.what() << std::endl;
  }

  //std::exception - prints "Exception Message: " + what the exception is, then goes to a newline.
  catch (const std::exception& exception) {
      std::cerr << "Exception Message: " << exception.what() << std::endl;
  }

  //Uncaught exceptions - prints "Enexpected exception caught!" and goes to a newline.
  catch (...) {
      std::cout << "Unexpected exception caught!" << std::endl;
  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
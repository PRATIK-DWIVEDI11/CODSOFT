#include <iostream>    
#include <fstream>     
#include <string>      
#include <sstream>    

int main() {
  std::ifstream inputFile("test.txt"); 

  if (inputFile.is_open()) {  
    std::string line;        
    int wordCount = 0;        
    while (std::getline(inputFile, line)) {  
      std::stringstream ss(line);  
      std::string word;  

      while (ss >> word) {  
        wordCount++;  
      }
    }

    inputFile.close();  

    std::cout << "Number of words in the said file: " << wordCount << std::endl;  
  } else {
    std::cout << "Failed to open the file." << std::endl; 
  }

  return 0;  
}


#ifndef DBOBSLUGIWACZBAZYDANYCH_H
#define DBOBSLUGIWACZBAZYDANYCH_H

#include <fstream>

class DBObslugiwaczBazyDanych {
public:
    DBObslugiwaczBazyDanych();
    ~DBObslugiwaczBazyDanych() {}
    
private:
    std::ifstream inputFileReader;
    std::ofstream outputFileReader;
};

#endif // DBOBSLUGIWACZBAZYDANYCH_H

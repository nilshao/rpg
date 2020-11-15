# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

int main(){
    std::ofstream outfile;

    outfile.open("PlayerSavings.csv", std::ios::out);
    outfile << "location" <<"," << " Name "<< "," << "HP" <<","<<"MP"<<',' << "process" << std::endl;
    outfile << "1" << std::endl;
    outfile << "2" << std::endl;
    outfile << "3" << std::endl;
    outfile << "4" << std::endl;
    outfile << "5" << std::endl;
    outfile << "6" << std::endl;
    outfile << "7" << std::endl;
    outfile << "8" << std::endl;
    outfile << "9" << std::endl;
    outfile.close();


    return 0;
}
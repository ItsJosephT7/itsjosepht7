#include <iostream>
#include <chrono>
#include <fstream>
#include <ctime>
#include <iomanip>

int main ()
{
 std::tm birth_tm = {};
 birth_tm.tm_year = 2007 - 1900; 
 birth_tm.tm_mon = 6; 
 birth_tm.tm_mday = 12;
 birth_tm.tm_hour = 0;
 birth_tm.tm_min = 0;
 birth_tm.tm_sec = 0;

 std::time_t birth_tm_t = std::mktime(&birth_tm);
 auto birth_date = std::chrono::system_clock::from_time_t(birth_tm_t);

 std::time_t current_time_t = std::time(nullptr);
 auto current_time = std::chrono::system_clock::from_time_t(current_time_t);
 auto now = std::chrono::system_clock::now();
 auto diff = std::chrono::duration_cast<std::chrono::seconds>(current_time - birth_date).count();
 long long total_seconds = diff;

 if (total_seconds < 0)
 {
    std::cout << "error" << std::endl;
    return 1;
 }



 long long total_days = total_seconds / (24 * 60 * 60);
 long long years = total_days / 365;
 total_days %= 365;

 long long months = total_days / 30;
 total_days %= 30;
 long long days = total_days;

 long long hours = (total_seconds % (24 * 60 * 60)) / (60 * 60);
 long long minutes = (total_seconds % (60 * 60)) / 60;
 long long seconds = total_seconds % 60;


 std::cout << " < " << years << " years, " << months << " months, " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" <<" > " << std::endl;
 std::cout<< std::endl;



 std::ofstream output_file("README.md");
 if (output_file.is_open())
 {
    output_file << "<div align=\"center\">\n\n";
    output_file << "<h1>عايش بقالي كام سنة ؟؟</h1>\n\n";
    output_file << "<p> < " << years << " years, " << months << " months, " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds > </p>\n\n";
    output_file << "</div>\n";
    output_file.close();
    std::cout << "written to README.md" << std::endl;
 }

 else
 {
    std::cerr << "error to open output file" << std::endl; 
    return 1;
 }

 return 0;


}

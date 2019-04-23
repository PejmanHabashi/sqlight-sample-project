#include <iostream>
#include <sqlite3.h>

class Problem {
    public:
        int Solution(int n) {
            using namespace std;

            sqlite3 * db;
            int error = sqlite3_open("test.db", &db);
            if ( error ) {
                std::cout << "There is a problem openning the databse. Error = " << sqlite3_errmsg(db) << " Exiting the application." << std::endl;
                sqlite3_close(db);
                return -1;
            }

            cout << "The dadabase openned successfully." << endl;

            // std::string createDatabase =  "CREATE DATABASE database_name";


            std::string createTable = 
                        "CREATE TABLE MyTable (     "
                        "    Columns1   Intiger     ,"
                        "    Columns2   varchar(255),      "
                        "    Columns3   varchar(255),      "
                        "    Columns4   varchar(255),      "
                        "    Columns5   varchar(255)       "
                        "               )"            ;
            sqlite3_stmt * stmt;
            error = sqlite3_prepare_v2(db, createTable.c_str(), -1, & stmt, NULL);

            if ( error ) {
                std::cout << "There is a problem parsing the sql command for creting the table. Error = " << sqlite3_errmsg(db) << " Exiting the application." << std::endl;
                sqlite3_close(db);
                return -1;
            }

            sqlite3_step(stmt);

            sqlite3_finalize(stmt);

            error = sqlite3_close(db);
            if(error) {
                std::cout << "There is a problem closing the databse. Error = " << sqlite3_errmsg(db) << std::endl;
                sqlite3_close(db);
                return -1;
            }
            cout << "The dadabase Closed successfully." << endl;
            return 0;
        }
};

int main( int argc, char* argv[] ) {
    using namespace std;

    Problem p;
    p.Solution(2);
    return 0;
}

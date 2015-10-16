#include <mysql/mysql.h>

#include <string>

class Flitter
{
  public:
    Flitter();
    
    void CreateUser();
                 
    void FleetMessage();
    
    void Follow();
    
    void SeeFleets();
    
    void Unfollow();
  private://Member functions
    void Connect();
    void Query(std::string);
    bool RequestAuth(std::string&, std::string&);
    void UserInput(const std::string, std::string&);
  private:
    //Connector for the database
    MYSQL* mConnector;
    //Results from the database
    MYSQL_RES* mRes;
    //Location of the server
    std::string mServer;
    //Temp variable to collect user input
    std::string mTemp, mHandle, mPassword;
};

#include <mysql/mysql.h>

#include <string>

class Flitter
{
  public:
    Flitter();
    
    void CreateUser(std::string, 
                    std::string, 
                    std::string, 
                    std::string, 
                    std::string);
                 
    void FleetMessage(std::string, std::string);
    
    void Follow(std::string);
    
    void SeeFleets(int);
    void SeeFleets(int, int);
    
    void Unfollow(std::string);
  private://Member functions
    void Connect();
  private:
    //Connector for the database
    MYSQL* mConnector;
};

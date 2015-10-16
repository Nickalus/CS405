#include "flitter.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>

Flitter::Flitter() 
: mConnector(mysql_init(NULL)), 
  mServer("mysql.cs.uky.edu"),
  mTemp()
{
  if(mConnector == NULL) 
  {
    std::cerr << mysql_error(mConnector);
    exit(1);
  }
  else
  {
	std::cout << "Connected!" << std::endl;
  }
  
  Flitter::Connect();
}

////////////////////////////////////////////////////////////////////////////////
// Description: Inserts the user into the table
// Inputs: std::strings for handle, password, first and last name, and location
// Output: Will return what the database returns
// Example: CreateUser("@paul" "Paul" "Linton" "Lexington, KY");
////////////////////////////////////////////////////////////////////////////////
void Flitter::CreateUser()
{
  std::string query = "REPLACE INTO Users(Handle, Password, FirstName, LastName, Location) VALUES('";  
  
  Flitter::UserInput("Enter your handle: ", mTemp);
  if(mTemp[0] != '@')
  {
    mTemp.insert(0, "@");
  }
  query.append(mTemp);
  query.append("', '");
   
  Flitter::UserInput("Enter your password: ", mTemp);
  query.append(mTemp);
  query.append("', '");
  
  Flitter::UserInput("Enter your first name: ", mTemp);
  query.append(mTemp);
  query.append("', '");
  
  Flitter::UserInput("Enter your last name: ", mTemp);
  query.append(mTemp);
  query.append("', '");
   
  Flitter::UserInput("Enter your Location: ", mTemp);
  query.append(mTemp);
  query.append("')");
    
  Flitter::Query(query);
}

////////////////////////////////////////////////////////////////////////////////
// Description: Inserts fleets into the fleet table. Fleets are only inserted
//              when the password and handle for a user are correct. (Password 
//              will be asked for)
// Inputs: std::strings for handle, and fleet
// Output: Will return what the database returns
////////////////////////////////////////////////////////////////////////////////

/* example of my query
 * INSERT INTO Fleets(user, fleet) SELECT @Nick, "Woot!",
        FROM dual
        WHERE(SELECT * FROM users
      WHERE user = @Nick AND item = 12345678)
*/
void Flitter::FleetMessage()
{
  if(Flitter::RequestAuth(mHandle, mPassword))
  {
    std::string query = "INSERT INTO Fleets(User_Handle, Fleet) VALUES('"; 
    
    query.append(mHandle);
    query.append("', '");
    
    Flitter::UserInput("Enter your fleet: ", mTemp);
    query.append(mTemp);
    query.append("')");
    
    Flitter::Query(query);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Description: Inserts the user to follow into the follows table. Later the 
//              user can see fleets from the users they follow
// Inputs: std::string for handle
// Output: Will return what the database returns
// Example: Follow("@paul");
////////////////////////////////////////////////////////////////////////////////
void Flitter::Follow()
{
  if(Flitter::RequestAuth(mHandle, mPassword))
  {
    Flitter::UserInput("Enter The handle of the user to follow: ", mTemp);
    
    std::string q = "REPLACE INTO Following VALUES('" + mHandle + "', '" + mTemp + "')";
    Flitter::Query(q);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Description: Shows the last x number of tweets from all flitters the user is 
//              following
// Inputs: ints for the x and y offsets
// Output: Will return what the database returns
// Example: SeeFleets(25, 25); //Show fleets number 25-50
////////////////////////////////////////////////////////////////////////////////
void Flitter::SeeFleets()
{
  if(Flitter::RequestAuth(mHandle, mPassword))
  {
    Flitter::UserInput("Enter the starting place for fleets: ", mTemp);
    Flitter::UserInput("Enter the ending place for fleets: ", mTemp);
	
	//Unable to get a query working correctly...
  }
}

////////////////////////////////////////////////////////////////////////////////
// Description: Allows the user to unfollow another user
// Inputs: std::string for the user to unfollow
// Output: Will return what the database returns
// Example: Unfollow("@paul");
////////////////////////////////////////////////////////////////////////////////
void Flitter::Unfollow()
{
  if(Flitter::RequestAuth(mHandle, mPassword))
  {
    Flitter::UserInput("Enter The handle of the user to unfollow: ", mTemp);
    std::string q = "DELETE FROM Following WHERE User_Handle = '" + mHandle + "' AND Following_Handle = '" + mTemp + "'";
    
    Flitter::Query(q);
  }
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Flitter::Connect()
{
  if(!mysql_real_connect(mConnector, mServer.c_str(), "ntyo222", "u0442840", "ntyo222", 0, NULL, 0)) 
  {
    std::cerr << mysql_error(mConnector);
    exit(1);
  }
}

void Flitter::Query(const std::string q)
{
  std::cout << q << std::endl;
  if(mysql_query(mConnector, q.c_str()))
  {
    std::cerr << mysql_error(mConnector);
    //mysql_close(mConnector);
    //exit(1);   
  }
}

void Flitter::UserInput(const std::string s, std::string& temp)
{
  std::cout << s;
  std::getline(std::cin, temp);
  //std::cout << "\n";
}

bool Flitter::RequestAuth(std::string& handle, std::string& password)
{
  Flitter::UserInput("Enter your handle: ", handle);
  Flitter::UserInput("Enter your password: ", password);
  std::string q = "SELECT * FROM Users WHERE BINARY Handle = '" + handle + "' AND Password = '" + password + "'";
  
  Flitter::Query(q);
  
  //Get the result
  mRes = mysql_use_result(mConnector);
  
  //ALWAYS RETURNS 0
  //Get number of rows
  //int rows = mysql_num_rows(mRes);
  //std::cout << rows << std::endl;
  
  //count rows
  int count = 0;
  MYSQL_ROW row;
  while((row = mysql_fetch_row(mRes)) != NULL)
  {
	count = count + 1;
  }
  
  if(count > 0)
  {
	std::cout << "returning true" << std::endl;
    return true;
  }
  else
  {
	std::cout << "returning false" << std::endl;  
    return false;
  }
}

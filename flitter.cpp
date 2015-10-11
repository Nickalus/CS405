#include "flitter.hpp"

Flitter::Flitter()
{
}


////////////////////////////////////////////////////////////////////////////////
// Description: Inserts the user into the table
// Inputs: std::strings for handle, password, first and last name, and location
// Output: Will return what the database returns
// Example: CreateUser("@paul" "Paul" "Linton" "Lexington, KY");
////////////////////////////////////////////////////////////////////////////////
void Flitter::CreateUser(std::string handle, std::string password, 
                         std::string fname, std::string lname, 
                         std::string location)
{
  
}

////////////////////////////////////////////////////////////////////////////////
// Description: Inserts fleets into the fleet table. Fleets are only inserted
//              when the password and handle for a user are correct. (Password 
//              will be asked for)
// Inputs: std::strings for handle, and fleet
// Output: Will return what the database returns
// Example: FleetMessage("@paul" "Heading to class to give an exam in CS405!");
////////////////////////////////////////////////////////////////////////////////

/* example of my query
 * INSERT INTO Fleets(instance, user, item) 
    SELECT 919191, 123, 456
        FROM dual
        WHERE NOT EXISTS (SELECT * FROM x_table
                             WHERE user = 123 
                               AND item = 456)
*/
void Flitter::FleetMessage(std::string handle, std::string fleet)
{
}

////////////////////////////////////////////////////////////////////////////////
// Description: Inserts the user to follow into the follows table. Later the 
//              user can see fleets from the users they follow
// Inputs: std::string for handle
// Output: Will return what the database returns
// Example: Follow("@paul");
////////////////////////////////////////////////////////////////////////////////
void Flitter::Follow(std::string handle)
{
  
}

////////////////////////////////////////////////////////////////////////////////
// Description: Shows the last x number of tweets from all flitters the user is 
//              following
// Inputs: ints for the x and y offsets
// Output: Will return what the database returns
// Example: SeeFleets(); Or SeeFleets(25) Or SeeFleets(25, 25)
////////////////////////////////////////////////////////////////////////////////
void Flitter::SeeFleets(int start = 0, int end = 25)
{
}

void Flitter::SeeFleets(int end = 25)
{
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void Flitter::Connect()
{
  if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0)) 
  {
    fprintf(stderr, "%s\n", mysql_error(mConnector));
    exit(1);
  }
}

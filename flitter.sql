CREATE TABLE IF NOT EXISTS Users
(
ID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
Handle varchar(255) UNIQUE,
Password varchar(255) NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255) NOT NULL,
Location varchar(255) NOT NULL
)

CREATE TABLE IF NOT EXISTS Fleets
(
Fleet_ID INT NOT NULL AUTO_INCREMENT,
User_Handle varchar(255) NOT NULL,
Fleet varchar(155),
PRIMARY KEY(Fleet_ID),
FOREIGN KEY(User_Handle) REFERENCES Users(Handle)
)

CREATE TABLE IF NOT EXISTS Following
(
User_Handle varchar(255) NOT NULL REFERENCES Users(Handle),
Following_Handle varchar(255) NOT NULL REFERENCES Users(Handle),
PRIMARY KEY(User_Handle, Following_Handle)
)

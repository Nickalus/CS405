CREATE TABLE IF NOT EXISTS Users
(
ID int NOT NULL AUTO_INCREMENT PRIMARY KEY,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Location varchar(255),
Handle varchar(255) UNIQUE,
)

CREATE TABLE IF NOT EXISTS Fleets
(
ID int NOT NULL AUTO_INCREMENT,
Body varchar(155),
FORIGN KEY (Handle) REFERENCES Users(Handle),
)

CREATE TABLE IF NOT EXISTS Following
(
)

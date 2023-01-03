# ContestEuromillions

This project intended to create a client/server system that allows registering and managing bets on the Euromillions game using the gRPC framework. Three programs were implemented
client and a server program using the C++ language and the gRPC framework. The set of RPC services implemented on the server and used by clients was also specified.

Server:
  • The functionalities necessary for users to register bets were implemented, and these functionalities were made available in the form of a gRPC service.
  • The functions necessary for the administrator to view current bets and file them were implemented, and these functions must be made available
    in the form of a gRPC service.
  • The functions necessary for the draw director to manage the Euromillions draw were implemented, receiving the winning key and identifying the winners.
    These functionalities were made available in the form of a gRPC service.
  • Identifies each player and the brackets he bets on.
  • Keeps track of current bets and bet archive from previous draws.
  • Each bet contains at least: user ID, key, bet date.
  • The persistent recording of information was carried out in a database: MS SQL Express
  
Client for Users:
  • Have it configured, receive as a parameter, or ask the user for the IP address of the server to be contacted.
  • Must identify the user.
  • Allows viewing the list of keys on which the user has already bet.
  • Allows you to register bets.
  • It was programmed as an application with a Windows graphical interface (Windows forms).

Client for system administration:
  • It has configured, receive as a parameter, or ask the user for the IP address of the server to be contacted.
  • Allows viewing the list of users and keys registered for the raffle.
  • Allows you to archive bets and start a new draw.
  • It was programmed as an application with a Windows graphical interface (Windows forms).
  
Customer for raffle management:
  • It has configured, receive as a parameter, or ask the user for the IP address of the server to be contacted.
  • Allows the registration of the winning key and the obtaining of winning bets.
  • It was programmed as an application with a Windows graphical interface (Windows forms).
  
Implementation:
  • Client and server implementation were done in Visual Studio (Core 3 or higher and C++) and gRPC.

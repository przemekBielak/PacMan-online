

## Multiplayer PacMan game

## Motivation
Server-Client Pacman game implemented in C++ Qt5.  
Game can be player by two people in local network.

## Tech/framework used

<b>Built with</b>
- [Qt5](https://www.qt.io/)


## Features
Two players can play this game in local network.  
User can select server mode and host a game, or join an existing game in client mode.
Game logic and state is updated on server side and sent to client. Client mode only sends requests to the servers and based on the response updates the local gui and game state.

Game can be run on Window, Linux and Mac.

## License
MIT © [Przemysław Bielak]()
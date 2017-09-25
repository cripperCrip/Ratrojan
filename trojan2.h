using namespace std;

//Connection
bool connect(std::string Ip, std::string Port, SOCKET& ConnectedSocket, WSADATA& wsaData);
//Disconnection
bool disconnect(SOCKET ConnectedSocket, WSADATA wsaData);
//Send
bool send(SOCKET ConnectedSocket, int option, System::String^ Message);
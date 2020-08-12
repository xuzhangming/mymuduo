#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{

 
    string ip = "127.0.0.1";
    uint16_t port = 8000;

    // 创建client端的socket
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == clientfd)
    {
        cout<<"clientfd : "<<clientfd<<endl;
        cerr << "socket create error" << endl;
        exit(-1);
    }

    // 填写client需要连接的server信息ip+port
    sockaddr_in server;
    
    memset(&server, 0, sizeof(sockaddr_in));

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip.c_str());

  
    // client和server进行连接
    if (-1 == connect(clientfd, (sockaddr *)&server, sizeof(sockaddr_in)))
    {
        cerr << "connect server error" << endl;
        close(clientfd);
        exit(-1);
    }
    
    
     

    
        int num = 0;
       cout<<"please enter a number:";
       cin>>num;
        char buf[52] = "hello word!";
        int len = send(clientfd, buf, sizeof(buf), 0);
        
        cin>>num;
        close(clientfd);
        cin>>num;
        cout<<len;
    
    
}
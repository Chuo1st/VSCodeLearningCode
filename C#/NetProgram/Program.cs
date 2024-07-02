using System.Net;
using System.Net.Sockets;
using System.Text;


while (true)
{
    if (Console.ReadLine() == "add")
    {
        Task.Run(()=>{
            Socket clientSocket = new Socket(SocketType.Stream, ProtocolType.Tcp);
            clientSocket.Connect(new IPEndPoint(IPAddress.Parse("127.0.0.1"), 666));
            while (true)
            {
                if (clientSocket > 0)
                {

                }
            }
        });
    }
        
    
}
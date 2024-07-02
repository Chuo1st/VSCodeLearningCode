using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
namespace test{
    public class Program{
        public static void Main(string[] args)
        {
            var client = CreateClient();
            Console.WriteLine("connection is connected");
            byte[] sendBuffer;
            while(true)
            {
                Console.WriteLine("send image to the server, enter the path: ");
                var msg = Console.ReadLine();
                if(msg != null && msg.Count() > 0)
                {
                    sendBuffer = Encoding.UTF8.GetBytes(msg);
                    client.Send(sendBuffer);
                }
            }
            //Console.ReadKey();
        }


        public static Socket CreateClient()
        {
            Socket clientSocket = new Socket(SocketType.Stream, ProtocolType.Tcp);
            clientSocket.Connect(new IPAddress(new byte[]{127, 0, 0, 1}), 888);
            return clientSocket;
        }
    }
}


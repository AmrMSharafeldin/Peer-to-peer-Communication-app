# **Peer-to-Peer Communication App**

## **Introduction**

This project establishes client-to-client connections in a peer-to-peer chat application using TCP sockets to facilitate direct message transfer between users without the need for a central server. 

Key features of the application include:
- **Modular Design**: Implemented a modular design for send/receive functionality, ensuring code clarity and separation of concerns.
- **Message Management**: Utilized linked lists to separately manage sent and received messages, maintaining data structure integrity.
- **Concurrent Processes**: Developed four concurrent processes: listen, send, receive, and add message, each running as independent threads.
- **Concurrency Control**: Concurrency issues were resolved using mutexes and condition variables to avoid race conditions and ensure data consistency across threads.

This design allows smooth and efficient real-time communication between two terminals in a peer-to-peer network.  



## **How It Works** 

This section explains the core algorithm of the application. Here's how it works:

- Each terminal has a **Send** thread and a **Receive** thread running simultaneously.
- **Send Thread**: Collects user input and sends it as a message via TCP.
- **Receive Thread**: Listens for incoming messages and displays them to the user.
- **Concurrency Management**: Locks and condition variables ensure there are no race conditions when accessing shared resources like message queues.
- The app runs in a continuous loop, allowing for real-time communication between peers.



![Diagram](Media/diagram.gif)
## **How to Run It**

1. **Build the project**:
   ```bash
   make
2. **Run the Application: Open two separate terminal windows (on the same or different machines within the same network):**:
- **Terminal 1**: Terminal 1: Start the application using the following command:
  ```bash
  ./S_Talk.c CLIENT_PORT IP_ADDRESS SERVER_PORT
- **Terminal 2**: Start the application on the second machine/terminal using:
  ```bash
  ./S_Talk.c CLIENT_PORT IP_ADDRESS SERVER_PORT
Note: Ensure the client port in Terminal 1 is the server port in Terminal 2, and vice versa.  
3. **Start Chatting**: Once the application is running on both terminals, you can start sending and receiving messages in real-time.  
4. **Quit the Application**: To quit one of the clients, simply type `!` and press Enter.  
5. **To Stop the App**: If you wish to stop the application entirely, use Ctrl+C to stop it on both terminals.  

## **Demo**
![Diagram](Media/demo.mp4)

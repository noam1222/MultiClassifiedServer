# MultiClassifiedServer
## Overview
This program implements a server and client for classified vectors using the KNN algorithm.</br>
The server work in parallelism (number of clients can communicate with the server at once).</br>
As will be expanded later, the clients upload file of classified objects and unclassified objects. Also, he can determine the K of the algorithm and the distance method used in it. And finally he can ask to classify the unclassified objects and receivethe data.

## Instructions
### Input to start the program
First input for server should be: `port`:
- port - the port number of the server's socket.

First input for client should be: `ip port`:
- ip - the server's ip address
- port - the port number of the server's socket.

If any of this inputs will be invalid, the program will terminate.

### User Input
The server will sent the client a menu and the client should choose one of the following:
- 1 - The server will ask the client to enter the classified object file path[^1].</br>
If the path is valid and the the upload has been done, the server will ask to upload the unclassified objects file.</br>
as before, if the path is valid and the the upload has been done the server wiil notify about it and the menu will appear again.
- 2 - The K and the distance method of the server algorithm will appear on the screen:</br>
  - k - the amount of neighbors the classification should be according to. </br>
  - distance - distance method to define "nearest". Should be in this pattern:
    - `AUC` - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance).
    - `MAN` - [Manhattan distance](https://en.wikipedia.org/wiki/Taxicab_geometry).
    - `CHB` - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance).
    - `CAN` - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)[^2].
    - `MIN` - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)[^3].
    
If this is ok, the client should press `Enter`.</br>
Otherwise enter the new settings for the algorithm in this pattern: `k distance_method` ant then `Enter`.</br>
- 3 - Order the server to classify the objects in the unclassified objects file.</br>
*Pay attention:* the clients should first upload the files.
- 4 - Will make the result of option number 3 to appear on the screen in this pattern:
`object_line_number_in_unclassified_file result` and in the end will appear `Done.`</br>
To return to menu press `Enter`.</br>
*Pay attention:* the clients should first upload the files and classify the unclassified file.
- 5 - The client should enter path to download the result (as described in option 4) to.</br>
*Pay attention:* the clients should first upload the files and classify the unclassified file.</br>
**pay attention:** if the user choose to use relative path, the path will be relative from the folder the client program has been launched from.
- 8 - Exit the program.

### Run
Clone this repsitory and then in the repo folder type `make` or `make run`, wait for the compilation to end and than type `./server.out port` as described in [user input](https://github.com/noam1222/MultiClassifiedServer/edit/main/README.md#input-to-start-the-program). </br>
Then, in **another terminal** that open the repo folder and type `./client.out ip port` as described in [user input](https://github.com/noam1222/MultiClassifiedServer/edit/main/README.md#input-to-start-the-program). </br>
Then, the menu should appear and the program should run as described in [user input](https://github.com/noam1222/MultiClassifiedServer/edit/main/README.md#user-input).</br>

## Requierments
- Linux Operation System.
- The make program.
- Classified objects file for the server.

[^1]: The files **have** to be in Unix format. the command `dos2unix file_path` can be helpfull.
[^2]: According to this distance algorithm if both parameters of the two vectors are 0, then it doesn't have any effect on the calculation of the sum.
[^3]: We defined the P of this distance algorithm to be the constant - 2.

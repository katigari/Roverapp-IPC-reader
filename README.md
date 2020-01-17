# Roverapp-IPC-reader
This program is an example to apply Inter Process Communication by shared memory. 
Roverapp API shares rover-data in a memry block of a single computer. Then every program like this example, within the same single computer, can access the rover-data.

you can compile the code and generate the rover-reader exe file by running the c file script.
also existing Dockerfile can build the container image.
To access the host machin memory from inside container, the --ipc flag shall be used to run the container.

```
docker run --ipc="host" -it <your builded image from rover-ipc-reader> /bin/bash
```

Inside the container, you can run the rover-reader binary to print the rover-data. Also you can edit the example code, build and run the new binary file.
If the reoverapp API with IPC is running, "DataSet" value shall change in every read.

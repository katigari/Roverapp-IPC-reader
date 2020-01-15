/* The Linux Channel
 * Code for Video Episode: 352 Linux user-space - Shared Memory IPC - Live Demo and Example
 * Author: Kiran Kankipati
 * Updated: 15-Jul-2018
 */
#include <stdlib.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <unistd.h> 
#define SHM_MAX 1024

struct roverData {
  int dataSet;
  int distanceHCSR04Front;//distance_sr04_front_shared;
  int distanceHCSR04Back;//distance_sr04_back_shared;
  float DistanceInfraredRearRight;
  float DistanceInfraredRearLeft;
  float DistanceInfraredFrontRight;
  float DistanceInfraredFrontLeft;
  float bearing;
  int accelAccelX;
  int accelAccelY;
  int accelAccelZ;
  float accelAngleX;
  float accelAngleY;
  float accelAngleZ;
  float temperature;
  float humidity;
  char keycommand;
  int driving_mode;
  int speed;
  int buzzer_status;
  int light_mode;
  char keyboard;

};


int main() { 
//Get shared memory id 
//shared memory key 
key_t ipckey = ftok("shmfile",65); //generate unique key//const key_t ipckey = 24568; 
//shared memory permission; can be //read and written by anybody 
const int perm = 0666; 
//shared memory segment size 
size_t shmSize = 4096; 
//Create shared memory if not 
//already created with specified 
//permission 
int shmId = shmget(ipckey,shmSize,perm|IPC_CREAT); if(shmId<0) { printf("shmget() error! \n"); return 0; } //get shared memory 
//Attach the shared memory segment
void* shmPtr = shmat(shmId,NULL,0);

struct roverData* dp = (struct roverData*)shmPtr;

    while(1)
    {	
		printf("Data Set: %d \n",dp->dataSet);
		printf("Distance(HCSR04Front): %d cm\n",dp->distanceHCSR04Front);
		printf("Distance(HCSR04Back): %d cm\n", dp->distanceHCSR04Back);
		printf("DistanceInfraredRearRight: %f cm\n",dp->DistanceInfraredRearRight);
		printf("DistanceInfraredRearLeft: %f cm\n", dp->DistanceInfraredRearLeft);
		printf("DistanceInfraredFrontRight: %f cm\n", dp->DistanceInfraredFrontRight);
		printf("DistanceInfraredFrontLeft: %f cm\n", dp->DistanceInfraredFrontLeft);
		printf("Bearing from QMC5883L/HMC5883L: %f\n",dp->bearing);
		printf("Accelerometer acceleration:\t%d\t\t%d\t\t%d\n", dp->accelAccelX,dp->accelAccelY,dp->accelAccelZ);
		printf("Accelerometer angles:\t\t%f\t%f\t%f\n", dp->accelAngleX,dp->accelAngleY,dp->accelAngleZ);
    	sleep(1);
    } 

//detach shared memory 
shmdt(shmPtr); ///shmdt(buf); //detach buf from shared memory
    shmctl(shmId, IPC_RMID, NULL); //destroy shared memory return 0;
return 0;
}

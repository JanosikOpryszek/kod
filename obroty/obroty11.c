#include <stdio.h>
#include <string.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions 	   */
#include <errno.h>   /* ERROR Number Definitions           */
#include <stdlib.h>

void main(void)
{

         /*------------------------------- Ask for data to write to serial port ------------------*/


printf("Podaj kod PID 4 cyfry np 0100: ");
char tempp[6];
fgets(tempp,6,stdin);
printf("\n");
tempp[4]='\r';
tempp[5]='\0';


	
	
int fd;/*File Descriptor*/

printf("\n +----------------------------------+");
printf("\n |        Serial Port read & write  |");
printf("\n +----------------------------------+");

/*------------------------------- Opening the Serial Port -------------------------------*/

/* Change /dev/ttyUSB0 to the one corresponding to your system */

fd = open("/dev/ttyUSB0",O_RDWR | O_NOCTTY );	                 //blocking mode 
/* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
/* O_RDWR   - Read/Write access to serial port       */
/* O_NOCTTY - No terminal will control the process   */

/* bez 3 parametru (read) - Open in blocking mode,read will wait              */

//write  dodany 3 parametr(o_sync byl probnie dodany przezemnie)
/* O_NDELAY -Non Blocking Mode,Does not care about-  */
/* -the status of DCD line,Open() returns immediatly */



       	if(fd == -1)						/* Error Checking */
       	   printf("\n  Error! in Opening tty  ");
	else
       	   printf("\n  tty Opened Successfully ");


/*---------- Setting the Attributes of the serial port using termios structure --------- */

struct termios SerialPortSettings;	/* Create the structure                          */

//memset(&SerialPortSettings,0,sizeof SerialPortSettings );    ////////////// dodane

tcgetattr(fd, &SerialPortSettings);	/* Get the current attributes of the Serial port */



/* Setting the Baud rate */
cfsetispeed(&SerialPortSettings,B38400); /* Set Read  Speed                       */
cfsetospeed(&SerialPortSettings,B38400); /* Set Write Speed                        */

/* 8N1 Mode */
SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
SerialPortSettings.c_cflag &= ~CSIZE;	 /* Clears the mask for setting the data size             */
SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */
//SerialPortSettings.c_iflag &= ICANON;                         //Cannonical mode 

SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

//fcntl(fd,F_SETFL,0);                                        ////////////// dodane            aktywuje VMIN i VTIME
       /* Setting Time outs no Blocking for writing*/
//	SerialPortSettings.c_cc[VMIN] = 0; /*  nr signs to  Read  */
//	SerialPortSettings.c_cc[VTIME] = 0; // 0.1 seconds read timeout

if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
	printf("\n  ERROR ! in Setting attributes");
else
	printf("\n  BaudRate = 38400 \n  StopBits = 1 \n  Parity   = none");




         /*------------------------------- Write data to serial port -----------------------------*/

char write_buffer[6];      //="ati\r\n";
for(int i=0;i<6;i++)      //="0100\n";	/* Buffer containing characters to write into port	     */
	write_buffer[i]=tempp[i];

int  bytes_written  = 0;  	/* Value for storing the number of bytes written to the port */

bytes_written = write(fd,write_buffer,sizeof(write_buffer)-1);/* use write() to send data to port                                            */

		printf("\n  %s written to tty",write_buffer);
		printf("\n  %d Bytes written to tty", bytes_written);
		printf("\n +----------------------------------+\n\n");


//usleep (100000);             // sleep enough to transmit the 4 plus
                                     // receive 15:  approx 100 uS per char transmit
tcdrain(fd);                                                        //czeka na wyslanie wszystkich danych




/*------------------------------- Read data from serial port -----------------------------*/

fcntl(fd,F_SETFL,0);                                        ////////////// dodane            aktywuje VMIN i VTIME
        /* Setting Time outs - Blocking for reading*/
	SerialPortSettings.c_cc[VMIN] = 0; // Read at least 1 characters 
	SerialPortSettings.c_cc[VTIME] = 1; // Wait indefinetly   

if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) // Set the attributes to the termios structure
	printf("\n  ERROR ! in Setting attributes");
else
	printf("\n  czytanie BaudRate = 38400 \n  StopBits = 1 \n  Parity   = none\n");



tcflush(fd, TCIFLUSH);   /* Discards old data in the rx buffer            */

char read_buffer[200];   /* Buffer to store the data received              */
int  bytes_read = 0;    /* Number of bytes read by the read() system call */


bytes_read = read(fd,&read_buffer,19); // Read the data                   
read_buffer[bytes_read]='\0';

printf("\n  Bytes Read  %d:\n", bytes_read); // Print the number of bytes read 

printf("\nodczytany string:\n%s\n",read_buffer);



/*
int licz=5;
int j=0;
do{

char read_buf[20];   // Buffer to store the data received              
int  bytes_r = 0;    // Number of bytes read by the read() system call 


bytes_r = read(fd,&read_buf,19); // Read the data                   

//printf("\n  Bytes Rxed przed pt %d:", bytes_r); // Print the number of bytes read 


for(int i=0;i<bytes_r;i++)	 //printing only the received characters
{
	printf("%c",read_buf[i]);
	read_buffer[j+i]=read_buf[i];
}
j+=bytes_r;


}while(licz--);



bytes_read=j;



printf("\n  Bytes Rxed za petla %d:\n  ", bytes_read); // Print the number of bytes read 


for(int i=0;i<bytes_read;i++)	 //printing only the received characters
	printf("%c",read_buffer[i]);

read_buffer[bytes_read]='\0';
printf("  ");

char A[3];
A[0]=read_buffer[0];
A[1]=read_buffer[1];
A[2]='\0';
int a=(int)strtol(A,NULL,16);


printf("pierwsza =: %d\n",a);


char B[3];
B[0]=read_buffer[3];
B[1]=read_buffer[4];
B[2]='\0';
int b=(int)strtol(B,NULL,16);


printf("  druga =: %d\n",b);

int obroty=(256*a+b)/100;

printf("  Twoje obroty to: %d\n",obroty);
*/
	printf("\n +----------------------------------+\n\n\n");

	close(fd); /* Close the serial port */


}

/* ==================================================================================

 * File: client.c

 * System: Host PC

 * Team: MUSCA

 * Course Info: CSE 423 Fall 2013

 * 

 * Author(s): Gunnar Gunnarsson

 * Email: N/A http://www.abc.se/~m6695/udp.html

 * ==================================================================================

 * Description: A simple server client for unix environment

 * ==================================================================================

 * Change History: None, implemented. 

 * ________________________________________________________________

 * || Author || Date || Description ||

 * ----------------------------------------------------------------

 * || Taylor Wood || 12/28/13 || Added the code from the provided site and made some
    modifications. ||

 * ----------------------------------------------------------------

 *

 * ==================================================================================*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 255
#define NPACK 10
#define PORT 2390	//must be the same value as server.c

//change this to whatever the host ip address is
#define SRV_IP "192.168.1.135"

void diep(char *s) {
	perror(s);
	exit(1);
}

int main(void) {

	struct sockaddr_in si_other;
	//s is the sender id
	//r is reciever id
	int s = 0, i = 0, slen=sizeof(si_other);
	char buf[BUFLEN];
	
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
		diep("socket s");
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	if (inet_aton(SRV_IP, &si_other.sin_addr) == 0) {
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}

	for (i = 0; i < NPACK; i++) {
		printf("Sending packet %d\n", i);
		sprintf(buf, "This is packet %d\n", i);
		if (sendto(s, buf, BUFLEN, 0, &si_other, slen) == -1)
			diep("sendto()");
		//we need to sleep for some time. If we don't, then the packets
		//are sent too fast to the shield and it doesn't know what the 
		//hell to do. I'm not sure how long it takes to send the packet,
		//but that can be for later to figure out.
		sleep(1);
	}

	close(s);
	return 0;
}

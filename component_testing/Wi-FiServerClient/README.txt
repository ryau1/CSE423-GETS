/* ==================================================================================

 * File: README.txt

 * System: Host PC

 * Team: MUSCA

 * Course Info: CSE 423 Fall 2013

 * 

 * Author(s): Taylor Wood

 * Email: Taylorwood67@gmail.com

 * ==================================================================================

 * Description: README text file for the client and server executables.

 * ==================================================================================

 * Change History: File created

 * ________________________________________________________________

 * || Author || Date || Description ||

 * ----------------------------------------------------------------

 * || Taylor Wood || 12/28/13 || Added README ||

 * ----------------------------------------------------------------

 *

 * ==================================================================================*/

				Sending Packets to Arduino

1. Open up the WiFiUdpSendReceiveString.ino file. Change ssid and pass to the values 
that they should be based on the ssid that you connect to. Verify the local port in 
this file is the same as the one in client.c, if not change them so they are.

2. Upload the sketch to the DUE. Use ctrl + shift + m to open the serial monitor. 
The executebale should output some information to the monitor.

3. Record the Wi-Fi shields ip address. You will need to take this value, and copy it
into client.c. Look for "SRV_IP" and replace the value there.

4. Run the make file to create two executables, you can ignore the server executable.

5. Run the client executable. It will output information of packets being sent. You 
should see the packets being recieved in the serial monitor. Depending on the speed
of the Wi-Fi, you may need to change the sleep parameter in client.c. 

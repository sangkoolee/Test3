******************************************************************************************************
MultiRDCViewer v-1.1
Arxtron Technologies Inc. 
2016-08-30
******************************************************************************************************


******************************************************************************************************
Scope
******************************************************************************************************
This program allows for connecting to 3 remote dekstops at once in the same window.


******************************************************************************************************
Installation
******************************************************************************************************
A valid license for the computer is necessary to use the program and must be located in the program's root directory.

Copy the folder 'MultiRDCViewer\bin\x86\Release' to the computer that will use the application and rename the folder to 'MultiRDCViewer'.

Under 'Control Panel\Network and Internet\Network Connections', open the Local Area Connection Properties, click on (TCP/IPv4),
 then click 'Propeties', and enter ip address
 PC -> 192.168.66.110
 sa1 -> 192.168.66.111
 sa2 -> 192.168.66.112
 sa3 -> 192.168.66.113

In 'Release\Remote-Desktop-Connection-Settings.xml', under <rdp_connections>, for the first 3 <rdp name> nodes, change the fields for <ip_address>, <username>, and <password> so that they match the spectrum analyzers in order. The <rdp name> attribute can be changed to any name such as: <rdp name="My Spectrum Analyzer">. Additional remote desktop connections can be added by copying an <rdp name> node and changing the corresponding fields.
******************************************************************************************************
Usage
******************************************************************************************************
To run the program, double click or right click and open the application 'MultiRDCViewer.exe'

The screens will connect to the first 3 connection settings in 'Remote-Desktop-Connection-Settings.xml' respectively upon starting the program. Screens can be connected to different remote desktop protocols using the screens menu located at the top of the window. Click on the remote desktop you wish to connect to in the dropdown menus that correspond to the screen names. 

Connecting to a remote desktop may not happen immediately, and may timeout if a connection cannot be made. A remote desktop can only be displayed on one screen at a time.

Click on "Disconnect Screen" to disconnect the screen corresponding to the screen dropdown. 


******************************************************************************************************
Copyright © 2016 Arxtron Technologies Inc.
******************************************************************************************************


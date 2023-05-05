#ifndef ARDUINO_C_ETHERNET_H
#define ARDUINO_C_ETHERNET_H

#include <inttypes.h>
#include "IPAddress.h"

#include <inttypes.h>
#include "IPAddress.h"
#include "CEthernetClient.h"
#include "CEthernetServer.h"


#include "CNetIf.h"
#include "lwipMem.h"

enum EthernetLinkStatus {
  Unknown,
  LinkON,
  LinkOFF
};

enum EthernetHardwareStatus {
  EthernetNoHardware,
  EthernetMbed = 6
};

class CEthernet {

  private:
    CNetIf *ni;
    
    uint8_t mac_address[6];
  public:
    // Initialise the Ethernet with the internal provided MAC address and gain the rest of the
    // configuration through DHCP.
    // Returns 0 if the DHCP configuration failed, and 1 if it succeeded
    int begin(unsigned long timeout = 60000, unsigned long responseTimeout = 4000);
    EthernetLinkStatus linkStatus();
    void begin(IPAddress local_ip);
    void begin(IPAddress local_ip, IPAddress subnet);
    void begin(IPAddress local_ip, IPAddress subnet, IPAddress gateway);
    void begin(IPAddress local_ip, IPAddress subnet, IPAddress gateway, IPAddress dns_server);
    // Initialise the Ethernet shield to use the provided MAC address and gain the rest of the
    // configuration through DHCP.
    // Returns 0 if the DHCP configuration failed, and 1 if it succeeded
    int begin(uint8_t *mac_address, unsigned long timeout = 60000, unsigned long responseTimeout = 4000);
    int begin(uint8_t *mac_address, IPAddress local_ip);
    int begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server);
    int begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
    int begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet, unsigned long timeout = 60000, unsigned long responseTimeout = 4000);
    EthernetHardwareStatus hardwareStatus();

    void setDNS(IPAddress dns_server); 

    int disconnect(void);
    int maintain();
    void schedule(void);

   
    uint8_t *MACAddress(void);
    IPAddress localIP();
    IPAddress subnetMask();
    IPAddress gatewayIP();
    IPAddress dnsServerIP();

    friend class EthernetClient;
    friend class EthernetServer;
};

extern CEthernet Ethernet;

#endif
#include "gtest/gtest.h"
#include "src/scanner/arp.cpp"




TEST(Arp, init)
{
    Arp *sut = new Arp();
    sut->getInfo();
    std::cout << sut->arp("98-54-1b-e3-92-a7", "192.168.31.68", "192.168.31.1", "", 1) << endl;
    EXPECT_EQ(1, true);
}

/*
 *
 * #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <libnet.h>
#include <pcap.h>

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

#ifndef IP_ALEN
#define IP_ALEN 4
#endif

static u_char eth_xmas[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
static u_char eth_null[ETH_ALEN] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static u_char eth_src[ETH_ALEN];
static u_char eth_dst[ETH_ALEN] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static u_char ip_src[IP_ALEN];
static u_char ip_dst[IP_ALEN] = {192,168,20,1};

int main(int argc, char **argv)
{
  libnet_t *libnet = NULL;
  char error[LIBNET_ERRBUF_SIZE];
  int i;

  if (getuid() && geteuid()) {
    fprintf(stderr, "must be run as root");
    exit(1);
  }

  // open libnet
  libnet = libnet_init(LIBNET_LINK, "eth0", error);

  // get dst ip address
  u_int32_t otherip;
  otherip = libnet_name2addr4(libnet, argv[1], LIBNET_RESOLVE);
  memcpy(ip_dst, (char*)&otherip, IP_ALEN);

  // get hwaddr
  struct libnet_ether_addr *mymac;
  mymac = libnet_get_hwaddr(libnet);
  memcpy(eth_src, mymac, ETH_ALEN);

  // get ipaddr
  u_int32_t myip;
  myip = libnet_get_ipaddr4(libnet);
  memcpy(ip_src, (char*)&myip, IP_ALEN);

  // print MAC address
  for (i = 0; i < ETH_ALEN - 1; i++) {
    printf("%.2x:", (u_int8_t)eth_src[i]);
  }
  printf("%.2x", (u_int8_t)eth_src[ETH_ALEN - 1]);

  static libnet_ptag_t arp=0, eth=0;

  arp = libnet_build_arp(
     ARPHRD_ETHER,
     ETHERTYPE_IP,
     ETH_ALEN, IP_ALEN,
     ARPOP_REQUEST,
     eth_src, ip_src,
     eth_dst, ip_dst,
     NULL, 0,
     libnet,
     arp);

  eth = libnet_build_ethernet(
     eth_dst, eth_src,
     ETHERTYPE_ARP,
     NULL, 0,
     libnet,
     eth);

  int c = libnet_write(libnet);

  libnet_destroy(libnet);
}

 */
#!/usr/bin/env python
# coding=utf-8

from scapy.all import *
import sys,getopt

def usage():
        print "Usage: sudo ./ArpScanner.py "

def main(argv):
        try:
                opts, args = getopt.getopt(argv, "")
        except getopt.GetoptError:
                usage()
                sys.exit(2)

        for ipFix in range(1,254):
                ip = "192.168.1."+str(ipFix)
                arpPkt = Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst=ip, hwdst="ff:ff:ff:ff:ff:ff")
                res = srp1(arpPkt, timeout=1, verbose=0)
                if res:
                        print "IP: " + res.psrc + "     MAC: " + res.hwsrc

if __name__ == "__main__":
        main(sys.argv[1:])
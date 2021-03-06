#!/usr/bin/env python
# coding=utf-8

''''' 
python3 安装scapy-python3 
注：linux，可能需要以root登陆，避免出现permission error 
Scapy还包含内建函数arping(),该函数实现的功能和以上的两个命令类似： 
arping("192.168.1.*") 
'''
from scapy.all import srp, Ether, ARP

IpScan = '192.168.13.1/24'
#IpScan = '166.111.130.1/24'
next_res=[]
try:
    ans, unans = srp(Ether(dst="FF:FF:FF:FF:FF:FF") / ARP(pdst=IpScan), timeout=2)
except Exception as e:
    print(e)
else:
	#print(dir(ans))
	pass
for send, rcv in ans:
	#ListMACAddr = rcv.sprintf("%Ether.src%---%ARP.psrc%")
	#print(ListMACAddr)
	next_res.append({'IP':rcv.psrc,'MAC':rcv.src})

for index in next_res:
	print(index)

#!/usr/bin/python
#Packet sniffer in python
#For Linux - Sniffs all incoming and outgoing packets :)
#Silver Moon (m00n.silv3r@gmail.com)


import socket, sys
from struct import *

import socket, sys
from struct import *
req_s_ip = sys.argv[1]
req_s_port = sys.argv[2]
req_protocol = sys.argv[3]
_protocol = req_protocol.lower()

#req_protocol
#Convert a string of 6 characters of ethernet address into a dash separated hex string
def eth_addr (a) :
  b = "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x" % (ord(a[0]) , ord(a[1]) , ord(a[2]), ord(a[3]), ord(a[4]) , ord(a[5]))
  return b

#create a AF_PACKET type raw socket (thats basically packet level)
#define ETH_P_ALL    0x0003          /* Every packet (be careful!!!) */
try:
	s = socket.socket( socket.AF_PACKET , socket.SOCK_RAW , socket.ntohs(0x0003))
except socket.error , msg:
	print 'Socket could not be created. Error Code : ' + str(msg[0]) + ' Message ' + msg[1]
	sys.exit()

# receive a packet
while True:
	packet = s.recvfrom(65565)
	#print(packet)
	#packet string from tuple
	packet = packet[0]
	#print("1111111111111")
	#print(packet)
	
	#parse ethernet header
	eth_length = 14
	eth_header = packet[:eth_length]
	eth = unpack('!6s6sH' , eth_header)
	eth_protocol = socket.ntohs(eth[2])
	#print 'Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol)
	#print(packet)
	#Parse IP packets, IP Protocol number = 8
	if eth_protocol == 8 :
		#Parse IP header
		#take first 20 characters for the ip header
		#tcp_data_start = 20 + eth_length
		ip_header = packet[eth_length:20+eth_length]
		#now unpack them :)
		#print(ip_header)
		iph = unpack('!BBHHHBBH4s4s' , ip_header)
		#print iph

		version_ihl = iph[0]
		#print version_ihl
		version = version_ihl >> 4
		ihl = version_ihl & 0xF

		iph_length = ihl * 4

		ttl = iph[5]
		protocol = iph[6]
		s_addr = socket.inet_ntoa(iph[8]);
		d_addr = socket.inet_ntoa(iph[9]);
		if s_addr == req_s_ip:
			#print 'Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol)
			#print 'Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr)
			#TCP protocol
			if protocol == 6 :
				if req_protocol == "tcp" or req_protocol == "http" or req_protocol == "ftp" or req_protocol == "telnet":
					t = iph_length + eth_length 
					tcp_header = packet[t:t+20]

					#now unpack them :)
					tcph = unpack('!HHLLBBHHH' , tcp_header)
			
					source_port = tcph[0]
					dest_port = tcph[1]
					sequence = tcph[2]
					acknowledgement = tcph[3]
					doff_reserved = tcph[4]
					tcph_length = doff_reserved >> 4
					print(s_addr, req_s_ip)
					if source_port == int(req_s_port):
						print 'Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol)
						print 'Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr)
						print 'Source Port : ' + str(source_port) + ' Dest Port : ' + str(dest_port) + ' Sequence Number : ' + str(sequence) + ' Acknowledgement : ' + str(acknowledgement) + ' TCP header length : ' + str(tcph_length)
						h_size = eth_length + iph_length + tcph_length * 4
						data_size = len(packet) - h_size
			
						#get data from the packet
						data = packet[h_size:]
						#print(data)
						buf = data.decode(encoding = 'ascii', errors = 'ignore')
						print 'Data : ',
						for i in buf:
							if ord(i) in range(47, 120):
								print i,
							else:
								print '.',
						print
						print
						print

				#else:
					#tcp_d = packet[54:]
					#prott = unpack('!4s', tcp_d)
					#print tcp_d
				

			#ICMP Packets
			elif protocol == 1 :
				u = iph_length + eth_length
				icmph_length = 4
				icmp_header = packet[u:u+4]

				#now unpack them :)
				icmph = unpack('!BBH' , icmp_header)
				
				icmp_type = icmph[0]
				code = icmph[1]
				checksum = icmph[2]
				
				print 'Type : ' + str(icmp_type) + ' Code : ' + str(code) + ' Checksum : ' + str(checksum)
				
				h_size = eth_length + iph_length + icmph_length
				data_size = len(packet) - h_size
				
				#get data from the packet
				data = packet[h_size:]
			
				print 'Data : ' + data

			#UDP packets
			elif protocol == 17 :
				if req_protocol == "udp":
					u = iph_length + eth_length
					udph_length = 8
					udp_header = packet[u:u+8]

					#now unpack them :)
					udph = unpack('!HHHH' , udp_header)
					source_port = udph[0]
					dest_port = udph[1]
					length = udph[2]
					checksum = udph[3]
					if source_port == int(req_s_port):
						print 'Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol)
						print 'Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr)
						print 'Source Port : ' + str(source_port) + ' Dest Port : ' + str(dest_port) + ' Length : ' + str(length) + ' Checksum : ' + str(checksum)
						
						h_size = eth_length + iph_length + udph_length
						data_size = len(packet) - h_size
						
						#get data from the packet
						data = packet[h_size:]
						
						print 'Data : ' + data

			#some other IP packet like IGMP
			else :
				print 'Protocol other than TCP/UDP/ICMP'
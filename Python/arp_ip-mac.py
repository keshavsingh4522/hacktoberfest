import subprocess
import re

def get_arp_table():
    # Get the arp table from the system.
    arp_table = []
    output = subprocess.check_output(['arp', '-a'])
    output = output.decode('utf-8')
    lines = output.split('\n')
    for line in lines:
        if re.search(r'^\S', line):
            arp_table.append(line)
    return arp_table

def get_ip_mac_dict(arp_table):
    # Get the ip and mac address from the arp table.
    ip_mac_dict = {}
    for line in arp_table:
        ip = re.search(r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}', line)
        mac = re.search(r'([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})', line)
        if ip and mac:
            ip_mac_dict[ip.group(0)] = mac.group(0)
    return ip_mac_dict

def get_ip_mac_table():
    # Get the ip and mac address table.
    arp_table = get_arp_table()
    ip_mac_dict = get_ip_mac_dict(arp_table)
    ip_mac_table = []
    for ip, mac in ip_mac_dict.items():
        ip_mac_table.append((ip, mac))
    return ip_mac_table

def main():
    ip_mac_table = get_ip_mac_table()
    for ip, mac in ip_mac_table:
        print(ip, mac)

if __name__ == '__main__':
    main()

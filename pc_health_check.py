# Check pc health status
# For a stable system,
# free space should be > 20% and,
# disk usage should be < 75%

# pip install psutil

import shutil
import psutil


def check_disk_usage(disk):
    du = shutil.disk_usage(disk)
    free = du.free / du.total * 100
    return free


def check_cpu_usage():
    usage = psutil.cpu_percent(1)
    return usage


a = check_disk_usage("/")
b = check_cpu_usage()
if a > 20 or b < 75:
    print("Pc is stable \nfree space: {:.2f}% \nCPU usage: {:.2f}%".format(a,b))
else:
    print("Error!!!\nAction required \nfree space: {:.2f}% \nCPU usage: {:.2f}%".format(a, b))

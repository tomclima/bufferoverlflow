# Buffer Overflow scripts

Link da apresentação [aqui](https://docs.google.com/presentation/d/1omiWkOC50N-gSLF6wKAvX2MVade4WXKxg4qwhdxSZyQ/edit?usp=sharing)

Scripts usados durante apresentação introdutória sobre buffer overflows

## Para compilar os scripts C de overflow como são apresentados na palestra
```sh
gcc -fno-stack-protector -fno-pie <scriptname>
```
`-fno-stack-protector` -> compila sem os canários
`-fno-pie` -> compila sem aleatorização de endereços

#!/usr/bin/python
# -*-coding:Utf-8 -*

"""module multipli contenant la fonction table"""
def table(nb, max=10):
    i = 0
    while i < max:
        print(i + 1, "*", nb, "=", (i + 1)* nb)
        i += 1


if __name__ == "__main__":
    table(4)

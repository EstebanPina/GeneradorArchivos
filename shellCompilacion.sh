#!/bin/sh
gcc `pkg-config gtk+-3.0 --cflags` GeneradorArchivos.c -o GeneradorArchivos `pkg-config gtk+-3.0 --libs` -lssl -lcrypto
./GeneradorArchivos

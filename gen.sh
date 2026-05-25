#!/bin/bash

# Verificar que se haya pasado la cantidad 'n' como argumento
if [ -z "$1" ]; then
    echo "Error: Debes indicar la cantidad de números a generar."
    echo "Uso: $0 <cantidad_n>"
    exit 1
fi

# Guardar el argumento n y definir el archivo de salida
N=$1
OUTPUT="args.txt"

# Explicación del combo:
# 1. shuf genera N números aleatorios entre 0 y 1,000,000 (el -r permite que se repitan).
# 2. awk toma cada número y le resta 500,000.
# 3. Al final se redirige todo a args.txt.
shuf -i 0-1000000 -n "$N" | awk '{print $1 - 500000}' > "$OUTPUT"

#!/bin/bash

# Uso:
# ./gen.sh N D
# N = cantidad de elementos
# D = índice de desorden (0.0 - 1.0)

N=$1
D=$2

MIN=-10000
MAX=10000

if [ -z "$N" ] || [ -z "$D" ]; then
    echo "Uso: $0 N D"
    exit 1
fi

RANGE=$((MAX - MIN + 1))

if [ "$N" -gt "$RANGE" ]; then
    echo "Error: N demasiado grande para el rango"
    exit 1
fi

# =========================
# 1. Generar números únicos seguros
# =========================
mapfile -t arr < <(seq $MIN $MAX | shuf -n "$N")

# ordenar base inicial
mapfile -t arr < <(printf "%s\n" "${arr[@]}" | sort -n)

# =========================
# 2. Calcular objetivo de inversiones
# =========================
MAX_INV=$((N*(N-1)/2))
TARGET=$(awk "BEGIN {printf \"%d\", (1 - $D) * $MAX_INV}")
# clamp
(( TARGET < 0 )) && TARGET=0
(( TARGET > MAX_INV )) && TARGET=$MAX_INV

# =========================
# 3. Construir permutación con EXACTO número de inversiones
# =========================
result=()
remaining=$TARGET

for ((i=0; i<N; i++)); do
    x=${arr[$i]}

    # cuántas inversiones crear al insertarlo
    pos=$remaining
    if [ "$pos" -gt "$i" ]; then
        pos=$i
    fi

    result=("${result[@]:0:$pos}" "$x" "${result[@]:$pos}")

    remaining=$((remaining - pos))
done

# =========================
# 4. Guardar salida
# =========================
printf "%s " "${result[@]}" > args.txt
echo >> args.txt

echo "Generados: $N números únicos"
echo "Rango: [$MIN, $MAX]"
echo "Desorden objetivo: $D"
echo "Inversiones: $TARGET / $MAX_INV"
echo "Salida: args.txt"
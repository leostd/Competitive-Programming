def number_to_excel_column(n):
    if n == 0:
        return "A"
    result = []
    while n > 0:
        n -= 1
        print(n)
        result.append(chr(n % 26 + ord('A')))
        n //= 26
    return ''.join(result[::-1])

def process_input(input_lines):
    output = []
    for line in input_lines:
        numbers = list(map(int, line.split()))
        if all(num == 0 for num in numbers):
            break
        output_line = " ".join(number_to_excel_column(num) for num in numbers)
        output.append(output_line)
    return output

# Ejemplo de entrada
input_lines = [
    "26 51 52 53 676 677 0",
    "0"
]

# Procesar la entrada
output_lines = process_input(input_lines)

# Imprimir la salida
for line in output_lines:
    print(line)

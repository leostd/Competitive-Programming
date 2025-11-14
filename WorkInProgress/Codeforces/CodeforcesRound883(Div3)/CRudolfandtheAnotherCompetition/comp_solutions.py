import subprocess
import sys

def compare_executables(executable1_path, executable2_path, input_data):
    try:
        # Run the first executable
        process1 = subprocess.Popen([executable1_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output1, error1 = process1.communicate(input=input_data.encode('utf-8'))
        output1 = output1.decode('utf-8')  # Decode the output bytes to a string

        # Run the second executable
        process2 = subprocess.Popen([executable2_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        output2, error2 = process2.communicate(input=input_data.encode('utf-8'))
        output2 = output2.decode('utf-8')  # Decode the output bytes to a string

        # Compare the outputs
        if output1 == output2:
            print("The outputs of the executables match.")
        else:
            print("The outputs of the executables differ.")

        # Display errors, if any
        if error1:
            print("Error from executable 1:")
            print(error1.decode('utf-8'))

        if error2:
            print("Error from executable 2:")
            print(error2.decode('utf-8'))
    except subprocess.CalledProcessError as e:
        print("An error occurred while executing the executables:")
        print(e)

# Check if the executable paths and input file path are provided as arguments
if len(sys.argv) < 4:
    print("Please provide the paths to two executables and an input file as arguments.")
else:
    executable1_path = sys.argv[1]
    executable2_path = sys.argv[2]
    input_file_path = sys.argv[3]

    # Read the input data from the file
    with open(input_file_path, 'r') as input_file:
        input_data = input_file.read()

    compare_executables(executable1_path, executable2_path, input_data)


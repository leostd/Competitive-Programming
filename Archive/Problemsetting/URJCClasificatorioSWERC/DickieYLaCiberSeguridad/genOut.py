import glob
import os

directory = 'testcases'

for filename in glob.iglob(f'{directory}/*.in'):
  output_file = filename[0:-2] + 'ans'
  command = './main < {} > {}'.format(filename, output_file)
  # print(output_file)
  # print(command)
  os.system(command)


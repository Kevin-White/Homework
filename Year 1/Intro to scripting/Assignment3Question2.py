import os.path
import re


def main(f1, f2, f3):
    final = open("final_file.txt", 'w')
    if os.path.exists(f1):
        f = open(f1, 'r')
        lines = f.readlines()
        for line in lines:
            final.write(line)
        f.close()
    if os.path.exists(f2):
        f = open(f2, 'r')
        lines = f.readlines()
        for line in lines:
            final.write(line)
        f.close()
    if os.path.exists(f3):
        f = open(f3, 'r')
        lines = f.readlines()
        for line in lines:
            final.write(line)
        f.close()
    final.close()
    print("Files have been merged into final_file.txt")






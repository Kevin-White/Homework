import re
import codecs
import sys




class Data:
    def __init__(self, infile):
        self.infile = infile

        self.poppercent = []
        self.pop = []
        self.cenyear = 0
        self.landsize = []
        self.citysize = []
        self.dates = []

    def inputdat(self):
        file = codecs.open(self.infile, "r", "utf-8")
        lines = file.readlines()

        for line in lines:
            self.dates += re.findall(r"\d+ United States Census", line)
            self.pop += re.findall(r"right;\">\d+,?\d+</td><td", line)
            self.poppercent += re.findall(r"right;\">\d?,?\d+\.\d%</td></tr>", line)
            self.landsize += re.findall(r"\w{4,5}<?/?a?>?</th><td>\d+.\d+&#160;sq&#160;mi \(\d?,?\d+.\d+&#160;km<sup>2</sup>\)", line)


        datadate = []
        for d in self.dates:
            datadate += re.findall(r"\d+", d)

        self.dates = datadate
        datapop = []

        for p in self.pop:
            datapop += re.findall(r"\d+,?\d+", p)

        self.pop = datapop
        datapopper = ["-"]
        for pp in self.poppercent:
            datapopper += re.findall(r"\d?,?\d+\.\d%", pp)

        datalandsize = []
        self.poppercent = datapopper
        for ls in self.landsize:
            datalandsize += re.findall("\w{4,5}", ls)
            datalandsize += re.findall("\d+\.\d+", ls)
            datalandsize += re.findall("\d+?,?\d+\.\d+", ls)
        self.landsize = datalandsize

        # print(datalandsize)
        # print(self.dates)
        # print(self.pop)
        # print(self.poppercent)

    def getdatadate(self):
        return self.dates

    def getdatapop(self):
        return self.pop

    def getdatapopper(self):
        return self.poppercent

    def getdatalandsize(self):
        return self.landsize


def main(test2):
    stuff = Data(test2)
    stuff.inputdat()
    data = stuff.getdatalandsize()
    print("*********************************************************************")
    print("{}: {} is Square Mile({} km2)".format(data[0], data[1], data[4]))
    print("{}: {} is Square Mile({} km2)".format(data[5], data[6], data[9]))
    print("{}: {} is Square Mile({} km2)".format(data[10], data[11], data[14]))
    pop = stuff.getdatapop()
    date = stuff.getdatadate()
    popper = stuff.getdatapopper()
    print("*********************************************************************")
    for i in range(len(pop) - 1):
        print("{}\t{}\t{}".format(date[i + 1], pop[i], popper[i]))


if __name__ == '__main__':
    test1 = sys.argv[1]
    main(test1)

import os.path
import re
import codecs
import sys


class HTMLinfo:
    def __init__(self, fname):
        self.fname = fname
        self.datelist = []
        self.poplist = []
        self.pGrowth = []
        self.spaceType = []
        self.dis = []

    def getData(self):
        file = codecs.open(self.fname, "r", "utf-8")
        lines = file.readlines()
        datelistHTML = []
        poplistHTML = []
        pGrowthHTML = []

        areaHTML = []
        spaceType = []
        self.dis = []

        #Uses given HTML for wiki_corpus_Cristi to search for dates
        for line in lines:
            datelistHTML += re.findall(r"Census\">\d+</a></", line)
            poplistHTML += re.findall(r"right;\">\d+\W?\d+</td><td", line)
            pGrowthHTML += re.findall(r"right;\">\d?,?\d+.\d%</td></tr>", line)#City</a></th><td>488.73&#160;sq&#160;mi (1,265.80&#160;km<sup>2</sup>
            areaHTML += re.findall(r"\w{4,5}<?/?a?>?</th><td>\d+.\d+&#160;sq&#160;mi \W\d?,?\d+.\d+&#160;km<sup>2</sup>\W", line)


        self.datelist = []
        for date in datelistHTML:
            self.datelist += re.findall(r"\d+", date)


        self.poplist = []
        for pop in poplistHTML:
            self.poplist += re.findall(r"\d+\W?\d+", pop)


        self.pGrowth = ['-']
        for p in pGrowthHTML:
            self.pGrowth += re.findall(r"\d?,?\d+.\d%", p)

        for a in areaHTML:
            self.spaceType += re.findall(r"\w{4,5}", a)
            self.dis += re.findall(r"\d?,?\d{3}.\d+", a)



    def getDate(self):
        return self.datelist

    def getPop(self):
        return self.poplist

    def getGrowth(self):
        return self.pGrowth

    def getSpace(self):
        return self.spaceType

    def getDis(self):
        return self.dis

def main(HTMLname):
    #HTMLname = sys.argv[1]
    info = HTMLinfo(HTMLname)
    info.getData()
    datelist = info.getDate()
    poplist = info.getPop()
    pGrowth = info.getGrowth()
    spaceType = info.getSpace()
    dis = info.getDis()
    print("{}: {} is Square Mile ({} km2)".format(spaceType[0], dis[0], dis[1]))
    print("{}: {} is Square Mile ({} km2)".format(spaceType[1], dis[2], dis[3]))
    print("{}: {} is Square Mile ({} km2)".format(spaceType[2], dis[4], dis[5]))

    print("-----------------------------------------------------")
    print("Census\t\tPop\t\t\t%+")
    print("-----------------------------------------------------")

    for i in range(len(datelist)):
        print("{}\t\t{}\t\t{}".format(datelist[i], poplist[i], pGrowth[i]))


if __name__ == '__main__':
    a = sys.argv[1]
    main(a)








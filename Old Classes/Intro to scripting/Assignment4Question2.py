import re
import codecs
import sys
import matplotlib.pyplot as plt


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

        # Uses given HTML for wiki_corpus_Cristi to search for dates
        for line in lines:
            datelistHTML += re.findall(r"Census\">\d+</a></", line)
            poplistHTML += re.findall(r"right;\">\d+\W?\d+</td><td", line)
            pGrowthHTML += re.findall(r"right;\">\d?,?\d+.\d%</td></tr>",
                                      line)  # City</a></th><td>488.73&#160;sq&#160;mi (1,265.80&#160;km<sup>2</sup>
            areaHTML += re.findall(
                r"\w{4,5}<?/?a?>?</th><td>\d+.\d+&#160;sq&#160;mi \W\d?,?\d+.\d+&#160;km<sup>2</sup>\W", line)

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


def wiki(HTMLname):
    info = HTMLinfo(HTMLname)
    info.getData()
    datelist = info.getDate()
    poplist = info.getPop()


    poplist.pop()
    for i in range(len(poplist)):
        poplist[i] = poplist[i].replace(',', '')
        poplist[i] = int(poplist[i])
        datelist[i] = int(datelist[i])



    plt.style.use('dark_background')

    plt.plot(datelist, poplist)
    plt.xlabel('Year')
    plt.ylabel('Pop')
    plt.grid(True)

    plt.show()
    plt.bar(datelist, poplist)
    plt.show()


def rain(WeatherName):
    file = codecs.open(WeatherName, "r", "utf-8")
    lines = file.readlines()
    rainInfo = []
    for line in lines:
        rainInfo += re.findall(r"\d{1,2}\.\d,\d{1,2}\.\d,\d{1,2}\.\d,NA,NA", line)
    rainInfoNums = []
    for i in range(len(rainInfo)):
        rainInfoNums += re.findall(r"\d{1,2}\.\d", rainInfo[i])

    for i in range(len(rainInfoNums)):
        rainInfoNums[i] = float(rainInfoNums[i])

    temp = []
    fall = []

    for i in range(len(rainInfoNums)-4):
        temp.append((rainInfoNums[i] + rainInfoNums[i + 1])/2)
        fall.append(rainInfoNums[i + 2])


    plt.style.use('dark_background')
    plt.scatter(temp, fall)
    plt.xlabel('Temp')
    plt.ylabel('Rain Fall')
    plt.show()
    
    minTemp = []
    maxTemp = []
    fall = []
    for i in range(len(rainInfoNums)-4):
        minTemp.append(rainInfoNums[i])
        i = i + 1
        maxTemp.append(rainInfoNums[i])
        i = i + 1
        fall.append(rainInfoNums[i])

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    ax.scatter(minTemp, maxTemp, fall)
    ax.set_xlabel('minTemp')
    ax.set_ylabel('maxTemp')
    ax.set_zlabel("Rain Fall")
    plt.show()





def main(fName):
    if "weatherAUS.csv" in fName:
        rain(fName)
    if "wiki_Corpus_Cristi_Texas.html" in fName:
        wiki(fName)

if __name__ == '__main__':
    a = sys.argv[1]
    main(a)

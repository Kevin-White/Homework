def showuser(words, h, m, s):
    m = m + (s // 60)
    s = s % 60
    h = h + (m // 60)
    m = m % 60
    print(words + "{}:{}:{}".format(h, m, s))


hours = 6
minu = 32
sec = 0
showuser("You will leave at: ", hours, minu, sec)
minu = minu + 8 * 1
sec = sec + 15 * 1
showuser("Time after 1 mile: ", hours, minu, sec)
minu = minu + 7 * 3
sec = sec + 15 * 3
showuser("Time after 4 mile: ", hours, minu, sec)
minu = minu + 8 * 1
sec = sec + 15 * 1
showuser("You get home at: ", hours, minu, sec)







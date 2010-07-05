#!/usr/bin/env python

import matplotlib.pyplot as mpl
import csv

class Question:
    def __init__(self, fname, title, answers):
        self.fname = fname
        self.title = title
        self.answers = answers
        self.full_fracs = [0, 0, 0, 0, 0]
        for val in self.answers:
            if val == -2: self.full_fracs[0] += 1
            elif val == -1: self.full_fracs[1] += 1
            elif val == 0: self.full_fracs[2] += 1
            elif val == 1: self.full_fracs[3] += 1
            elif val == 2: self.full_fracs[4] += 1
    
    def average(self):
        return sum(self.answers) / float(len(self.answers))
    
    def fracs(self):
        ret = []
        for val in self.full_fracs:
            if val != 0: ret.append(val)
        return ret
    
    def explode(self):
        ret = []
        for val in self.full_fracs:
            if val != 0: ret.append(0.05)
        return ret
    
    def labels(self):
        ret = []
        full_labels = ["Strongly\nDisagree", "Disagree", "Neutral", "Agree", "Strongly\nAgree"]
        for i in range(0, len(self.full_fracs)):
            if self.full_fracs[i] != 0: ret.append(full_labels[i])
        return ret
    
    def colors(self):
        ret = []
        full_colors = ["k", "r", "y", "g", "b"]
        for i in range(0, len(self.full_fracs)):
            if self.full_fracs[i] != 0: ret.append(full_colors[i])
        return ret
    
    def tostring(self):
        return "fname:[{0}] title:[{1}] answers:{2} avg:{3} fracs:{4}".format(self.fname, self.title, self.answers, self.average(), self.fracs())

questions = []

data = csv.reader(open("survey1.dat", "ru"))
for row in data:
    fname = row[0]
    title = row[1]
    answers = []
    for i in range(2,len(row)):
        answers.append(int(row[i]))
    questions.append(Question(fname, title, answers))

mpl.figure(1, figsize=(8,5))
#mpl.axes([0.1, 0.1, 0.8, 0.8])
mpl.rc('font', size=15)
for q in questions:
    mpl.clf()
    mpl.pie(q.fracs(), explode=q.explode(), labels=q.labels(), colors=q.colors(), autopct='%1.1f%%', shadow=True)
    mpl.title(q.title, bbox={'facecolor':'0.8', 'pad':10})
    mpl.savefig("img/{0}.png".format(q.fname))

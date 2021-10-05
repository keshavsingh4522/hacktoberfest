#! /usr/bin/env python

import os
import sys
import re
import xlrd
import openpyxl
from datetime import datetime

fileName = sys.argv[1]

# File-related variables
txt = '%s.txt' % (fileName[:-5])
txt = os.path.join(dataPath, txt)
txt = open(txt, 'w')

rows = util.fetchRows(os.path.join(dataPath, fileName))
wb = openpyxl.load_workbook(dataPath + fileName)
books = wb.get_sheet_names()
sh = wb.get_sheet_by_name(books[0])

for row in list(sh.rows):
    col = []
    cols = list(row)
    for s in cols:
        s = util.clean(s.value).replace("\n"," ")
        if s != 'NONE':
            detail.append(s)
        else:
            detail.append('')

        final_details.append('|'.join(detail))

txt.write('\n'.join(final_details))
txt.close()

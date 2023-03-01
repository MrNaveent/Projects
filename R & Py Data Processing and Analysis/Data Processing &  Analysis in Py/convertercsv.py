# Script for converting the xml files into csv
import xml.etree.ElementTree as ET
import pandas as pd

def xml2csv(dirname,fname, delcols=[]):
    tree = ET.parse(dirname+'/'+fname+'.xml')
    root = tree.getroot()
    d = pd.DataFrame([e.attrib for e in root])
    for name in delcols: del d[name]
    d.to_csv(dirname+'/'+fname+".csv", index=False)


for subdir in ['one','two']:
	dirname = '/Users/naveen/Downloads/'+subdir
	xml2csv(dirname,"Badges")
	xml2csv(dirname,"PostLinks")
	xml2csv(dirname,"Posts", ["Body", "Tags", "OwnerDisplayName", "LastEditorDisplayName"])
	xml2csv(dirname,"Tags")
	xml2csv(dirname,"Users", ["AboutMe", "WebsiteUrl", "ProfileImageUrl"])
	xml2csv(dirname,"Votes")
	xml2csv(dirname,"Comments", ["Text", "UserDisplayName"])

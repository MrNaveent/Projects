import pandas
import pymongo
import neo4j
import csv
import mysql.connector


m = []
m1 = []
m2 = []
m3 = []
n=[]
n1 = []
n2 = []
n3 = []
ma= []
ma1 = []
ma2 = []
ma3 = []

connect = pymongo.MongoClient("mongodb://localhost:27017")
mydb = connect["Lost_credit_card"]
for j in ('ft','kuchbhi','stf','tf'):
    xm = []
    xm1 = []
    xm2 = []
    xm3 = []
    csv_db = mydb[j]
    for i in range(0,31):
        mydoc = csv_db.find({}).explain()
        m1 = mydoc['executionStats']['executionTimeMillis']
        xm.append(m1)
        mydoc = csv_db.find({"Credit Card Type":"UnionPay"}).explain()
        m2 = mydoc['executionStats']['executionTimeMillis']
        xm1.append(m2)
        query3 = csv_db.find({'City':'Arlington'})
        query3_time = query3.explain()
        m3 = query3_time['executionStats']['executionTimeMillis']
        xm2.append(m3)
        query4_codes = csv_db.find({'Credit Card Number':3853-6481-4247-4031})
        query4_time = query4_codes.explain()
        m4 = query4_time['executionStats']['executionTimeMillis']
        xm3.append(m4)
    m3.append(xm3)
    m2.append(xm2)
    m1.append(xm1)
    m.append(xm)
connect.close()


conn = neo4j.GraphDatabase.driver("neo4j://localhost:7687",auth=('neo4j','1234'))
db = conn.session()
for j in ('ExportCSV1','75','50','25'):
    xn = []
    xn1 = []
    xn2 = []
    xn3 = []
    for i in range(0,31):
        num = db.run("MATCH (n:"+j+") return n")
        time = num.consume()
        xn.append(time.result_available_after)
        num = db.run("MATCH (n:"+j+") where n.Credit Card Type='UnionPay' return n")
        summ = num.consume()
        xn1.append(int(summ.result_available_after))
        num = db.run("MATCH (c:"+j+") where c.City = 'Arlington' return c")
        summ = num.consume()
        xn2.append(int(summ.result_available_after))
        num = db.run("match (u:"+j+") where u.Credit Card Number =3853-6481-4247-4031 return u")
        summ = num.consume()
        xn3.append(int(summ.result_available_after))
    n.append(xn)
    n1.append(xn1)
    n2.append(xn2)
    n3.append(xn3)
db.close()


conn = mysql.connector.connect(user='root',password='1234',port=3306)
curr = conn.cursor()
num_4_sql = 0
xma = []
xma1 = []
xma2 = []
xma3 = []
curr.execute("use Lost_credit_card;")
for j in ('ExportCSV1','75','50','25'):
    curr.execute("set profiling = 1;")
    for i in range(0,31):
        curr.execute("select * from "+j)
        curr.fetchall()
        curr.execute("show profiles;")
        cm = curr.fetchall()
        if num_4_sql < 14:
            xma.append(cm[i][1])
        elif num_4_sql == 14:
            xma.append(cm[14][1])
        else:
            xma.append(cm[14][1])
        num_4_sql += 1
    for i in range(0,31):
        curr.execute("select * from "+j+" where Credit Card Type = 'UnionPay'")
        curr.fetchall()
        curr.execute("show profiles;")
        cm = curr.fetchall()

        xma1.append(cm[14][1])
        num_4_sql += 1
    for i in range(0,31):
        curr.execute("select * from "+j+" where City = 'Arlington'")
        curr.fetchall()
        curr.execute("show profiles;")
        cm = curr.fetchall()
        #print(cm)
        xma2.append(cm[14][1])
        num_4_sql += 1
    for i in range(0,31):
        curr.execute("select * from "+j+" where Credit Card Number=3853-6481-4247-4031")
        curr.fetchall()
        curr.execute("show profiles;")
        cm = curr.fetchall()
        #print(cm)
        xma3.append(cm[14][1])
        num_4_sql += 1
    curr.execute("set profiling = 0")
curr.close()
funnum = 0
for i in range(4):
    ama = []
    ama1 = []
    ama2 = []
    ama3 = []
    for j in range(31):
        ama.append(int(xma[funnum]*1000))
        ama1.append(int(xma1[funnum]*1000))
        ama2.append(int(xma2[funnum]*1000))
        ama3.append(int(xma3[funnum]*1000))
        funnum += 1
    ma.append(ama)
    ma1.append(ama1)
    ma2.append(ama2)
    ma3.append(ama3)


print(m)
print(m1)
print(m2)
print(m3)
print(n)
print(n1)
print(n2)
print(n3)
print(ma)
print(ma1)
print(ma2)
print(ma3)


with open('Final runtime.csv','w',newline='') as file:
    mywrite = csv.writer(file, delimiter=',')
    mywrite.writerows(m)
    mywrite.writerows(m1)
    mywrite.writerows(m2)
    mywrite.writerows(m3)
    mywrite.writerows(n)
    mywrite.writerows(n1)
    mywrite.writerows(n2)
    mywrite.writerows(n3)
    mywrite.writerows(ma)
    mywrite.writerows(ma1)
    mywrite.writerows(ma2)
    mywrite.writerows(ma3)
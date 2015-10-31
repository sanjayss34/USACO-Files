# #Binary/Base-3 (digits)
# 
# fileIn = "digits.in"
# fileOut = "digits.out"
# 
# #strBin = getline(fileIn, 1)
# #strThr = getline(fileIn, 2)
# 
# strBin = raw_input()
# strThr = raw_input()
# power2 = len(strBin)- 1
# power3 = len(strThr) - 1
# 
# bin = int(strBin)
# thr = int(strThr)
# 
# flag = 0
# while flag == 0:
# 	for i in range(strBin.__len__()):
# 		if strBin[i] == 0:
# 			strBin[i] = "1"
# 		if strBin[i] == 1:
# 			strBin[i] = "0"
# 		bin = 0
# 		for y in range(strBin.__len__()):
# 			if y == 0:
# 				for n in strThr:
# 					bin += int(n) * (3**power2)
# 					power2 -= 1
# 				power2 = len(strBin) - 1
# 				for j in range(strThr.__len__()):
# 					if j == 0:
# 						for k in range(3):
# 							strThr.replace(strThr[j], str(k), 1)
# 							thr = 0
# 							for l in strThr:
# 								thr += int(l)*(3**power3)
# 								power3 -= 1
# 							power3 = len(strThr) - 1
# 							if bin == thr:
# 								flag = 1
# 					else:
# 						for k in range(3):
# 							strThr.replace(strThr[j], str(k), 1)
# 							thr = 0
# 							
# 							for l in strThr:
# 								thr += int(l)*(3**power3)
# 								power3 -= 1
# 							power3 = len(strThr) - 1
# 							if bin == thr:
# 								flag = 1
# 			else:
# 				for s in 
# 
# 
# 		if flag == 0:
# 			if strBin[i] == 1:
# 				strBin[i] = "0"
# 			if strBin[i] == 0:
# 				strBin[i] = "1"
# 
# num = 0
# for h in range(strBin.__len__()):
# 	if strBin[h] == 1:
# 		num += power2
# 	power2 -= 1
# 
# print strBin
# print strThr
# 
# print num
# #File2 = open(fileOut, w+)
# #File2.write(num)




possible2 (str):
	list2 = []
	poss2 = []
	
	for i in range(len2):
		list2[i] = 0
	
	for j in list2:
		j = 1
		if !(2**(list2.index(j)) in poss2):
			poss2.append(j)
		
		for 
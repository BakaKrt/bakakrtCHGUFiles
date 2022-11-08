A=("БЕЛИБЕРДА")
GL=("ЕИЕА")
SO=("БЛРД")
k=0
lp=[]
for a1 in A:
    for a2 in A:
        for a3 in A:
            for a4 in A:
                for a5 in A:
                    for a6 in A:
                        for a7 in A:
                            for a8 in A:
                                for a9 in A:
                                    res = a1+a2+a3+a4+a5+a6+a7+a8+a9
                                    for i in range(len(res)):
                                        try:
                                            if res[i]=="Б" and (res[i+1] in GL) and (res[i+2] in GL) and (res[i+3] in GL) and (res[i+4] in GL) and (res[i+5]=="Б" or res[i+6]=="Б" or res[i+7]=="Б") and (res[i+1] != res[i+2]) and (res[i+2]!=res[i+3]) and (res[i+1]!=res[i+3]):
                                                if res.count("Е")>2 or res.count("Б")>2 or res.count("Л")>1 or res.count("Р")>1 or res.count("Д")>1 or res.count("И")>1 or res.count("А")>1:
                                                    break
                                                k+=1
                                                print(res)
                                        except IndexError:
                                            x=0
print(k)
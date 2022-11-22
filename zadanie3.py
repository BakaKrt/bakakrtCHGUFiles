mast1=["61","71","81","91","10","v1","d1","k1","t1"]
mast2=["62","72","82","92","20","v2","d2","k2","t2"]
mast3=["63","73","83","93","30","v3","d3","k3","t3"]
mast4=["64","74","84","94","40","v4","d4","k4","t4"]
l=mast1+mast2+mast3+mast4
k=0

for i1 in mast1:
    for i2 in mast2:
        for i3 in mast3:
            for i4 in mast4:
                for i5 in l:
                    s=i1+i2+i3+i4+i5
                    if s.count("t")>=2 and s.count("1")==2:
                        for i in range(len(s)):
                            try:
                                if (s[i]+s[i+1] != (s[i+2]+s[i+3])) and (s[i]+s[i+1] != (s[i+4]+s[i+5])) and (s[i]+s[i+1] != (s[i+6]+s[i+7])) and (s[i]+s[i+1] != (s[i+8]+s[i+9])) :
                                    k+=1
                                    print(s)
                            except IndexError: zxc=0   
print(k)
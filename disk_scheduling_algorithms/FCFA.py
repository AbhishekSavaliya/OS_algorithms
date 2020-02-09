s = input("Enter the page order sepret(,):")
page_order=s.split(",")
print(page_order)
count_page_frame = int(input("Enter the number of frame :"))
p=[]
for i in range(count_page_frame):
    p.append(",");
index=0
for i in page_order:
    if i not in p:
        p[index]=i
        index+=1
        index%=count_page_frame
    print(p,index)
    
s = input("Enter the page order sepret(,):")
page_order=s.split(",")
print(page_order)
count_page_frame = int(input("Enter the number of frame :"))
p=[]
for i in range(count_page_frame):
    p.append(",");
temp=[]
temp1=[]
q=0
for i in page_order:
    if i not in p and temp!=[] and "," not in p:
        for j in p:
            temp1.append(temp.index(j))
        p[p.index(temp[max(temp1)])]=i
    elif i not in p and "," in p:
        p[q]=i
        q+=1
        q%=count_page_frame
    temp.insert(0,i)
    temp1=[]
    print(p)
       
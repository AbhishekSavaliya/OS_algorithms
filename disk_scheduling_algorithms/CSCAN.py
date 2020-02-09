request_track_string = input("Enter the need track(sep with ',') : ")
request_track_list = request_track_string.split(",")
track = int(input("Enter the total track:"))
head = int(input("Enter head : "))
for i in range(len(request_track_list)):
    request_track_list[i] = int(request_track_list[i])
request_track_list.sort()
total_head_movement = 0
temp1=[]
temp2=[]
for i in request_track_list:
    if i >= head:
        temp1.append(i)
    else:
        temp2.append(i)
temp1.append(track)
for i in temp1:
    print(i)
    total_head_movement+=i-head
    head = i   
total_head_movement+=track
head = 0
for i in temp2:
    print(i)
    total_head_movement+=i - head
    head = i
print("total movement : ",total_head_movement)
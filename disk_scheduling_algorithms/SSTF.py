request_track_string = input("Enter the need track(sep with ',') : ")
request_track_list = request_track_string.split(",")
head = int(input("Enter head : "))
for i in range(len(request_track_list)):
    request_track_list[i] = int(request_track_list[i])
if head not in request_track_list:
    request_track_list.append(head)
request_track_list.sort()
total_head_movement = 0
while len(request_track_list)!=1:
    print(head)
    if request_track_list.index(head)==0:
        dis = abs(head - request_track_list[request_track_list.index(head)+1])
        new_head = request_track_list[request_track_list.index(head)+1]
    elif request_track_list.index(head)==len(request_track_list)-1:
        dis = abs(head - request_track_list[request_track_list.index(head)-1])
        new_head = request_track_list[request_track_list.index(head)-1]
    else:
        dis = min(request_track_list[request_track_list.index(head)+1]-head,head - request_track_list[request_track_list.index(head)-1])
        if request_track_list[request_track_list.index(head)+1]-head < head - request_track_list[request_track_list.index(head)-1]:
            dis = request_track_list[request_track_list.index(head)+1]-head
            new_head = request_track_list[request_track_list.index(head)+1]
        else:
            dis = abs(head - request_track_list[request_track_list.index(head)-1])
            new_head = request_track_list[request_track_list.index(head)-1]
    request_track_list.remove(head)
    total_head_movement+=dis
    head = new_head
print(request_track_list[0])
print(total_head_movement)  
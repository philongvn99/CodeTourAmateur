# Ngày lập trình viên là ngày 256 của năm, tức là vào ngày 13/09 năm thường hoặc 12/09 năm nhuận.
# Năm nay Trường làng Big-O dự định sẽ tổ chức một kì thi lập trình dành cho tất cả các bạn học sinh trong trường cùng tham gia. 
# Ban tổ chức quyết định tổ chức M nội dung thi đấu cho các bạn học sinh tham gia. 
# Sau quá trình đăng ký ban tổ chức ghi nhận được N học sinh đăng ký dự thi.


# Vì số lượng các bạn học sinh tham gia có thể sẽ rất đông, 
# trong khi các phòng thực hành tin học của trường chỉ có tổng cộng K máy tính nên ban tổ chức quyết định sẽ chia các thí sinh thi đấu thành từng bảng đấu nhỏ. 
# Mỗi bảng không quá K thí sinh, các thí sinh đấu loại trực tiếp, người chiến thắng trong bảng đấu đó sẽ được vào vòng tiếp theo, 
# cứ như vậy cho đến khi tìm được người chiến thắng. 
# Nếu một bảng đấu mà chỉ có 1 thí sinh thì thí sinh đó sẽ được đặc cách vào vòng sau mà không cần thi đấu.

# Trường cần biết chính xác cần tổ chức ít nhất bao nhiêu trận đấu để hoàn thành được tất cả các nội dung thi đấu để có thể lên kế hoạch thời gian tổ chức cụ thể.

numOfTests = int(input())
for _ in range(numOfTests):
    numOfParti = int(input())
    contestComps = int(input())
    matches = 0
    while numOfParti > 1:
        newNoP = int(numOfParti / contestComps)
        mod_ = numOfParti % contestComps
        
        # CASE 1: Each group has more than 1 participant:
        #       Num of remaining participants is CEIL DIVISION of Num of Participants and Num of Contests Computer
        #       Num of matches is as same as "new" Num of participants
        if mod_ > 1:
            numOfParti = newNoP + 1
            matches += numOfParti
            
        # CASE 2: The last group has exactly 1 participant:
        #       Num of remaining participants is FLOOR (or normal) DIVISION of Num of Participants and Num of Contests Computer
        #       Num of matches is less than "new" Num of participants 1 unit
        elif mod_ == 1:
            numOfParti = newNoP + 1
            matches += newNoP
            
        # CASE 3: Num of remaining participants is divisible by num of computers
        #       Num of remaining participants is FLOOR (or normal) DIVISION of Num of Participants and Num of Contests Computer
        #       Num of matches is as same as "new" Num of participants
        else: 
            numOfParti = newNoP
            matches += numOfParti
    print(matches)            
# Left Or Right
# Thần số, thần số học hay còn gọi là số bí thuật là bất kỳ niềm tin vào mối quan hệ tín ngưỡng thần thánh và thần bí giữa các chữ số và sự kiện. 
# Tư tưởng này cũng điều tra về sự tương quan giữa số của các chữ cái trong danh xưng với những thứ mang tính tinh thần. 
# Tư tưởng này thông thường liên quan với siêu linh, cùng với thuật chiêm tinh và các nghệ thuật bói toán tương tự khác. (Wikipedia)
# Vào năm 2022, thần số học còn được xem là một bộ môn tràn đầy sự huyền bí và còn khá xa lạ với nhiều người. 
# Nhiều người còn xem đây như những câu chuyện có phần mê tín, nhưng cũng nhiều người xem nó thực sự là đức tin và nghiên cứu chúng như một bộ môn khoa học. 
# Trong bài toán này, chúng ta sẽ không bàn đến tính thực hư, cũng như tính đúng đắn của lĩnh vực này.

# Tuy nhiên, trong tương lai, vào năm 3022, ở xứ sở X, thần số học trở thành một ngành trọng tâm, được gây dựng bằng hàng ngàn công trình nghiên cứu đồ sộ, 
# đưa ra những định lý với phạm trù rộng lớn, bao hàm cả toán học, triết học, chiêm tinh học, lịch sử, ...
# Luôn muốn tìm tòi những điều mới lạ, sau khi tìm đọc hàng loạt tài liệu, Alice biết được về khái niệm tập sinh. 
# Tập sinh là một tập hợp những phần tử được sinh ra theo một quy luật nào đó từ một hoặc một dãy các con số. 
# Ngay lập tức, Alice đã tự nghĩ ra một tập sinh mới, đặt tên nó là LR và được định nghĩa như sau:

# Xuất phát từ một dãy S gồm các con số từ 0 tới 9.
# Tập sinh LR sẽ chứa tất cả các phần tử T được sinh ra theo cách sau:
# Xuất phát từ số đầu tiên của S, chèn số này vào T.
# Lần lượt các con số, từ số thứ hai, số thứ ba,..., ta được phép lựa chọn chèn số này vào bên trái hoặc phải số T.
# Trong lúc sinh, vì không cẩn thận nên Alice đã quên kiểm tra các số đã sinh trước đó, vậy nên hai số T_i và T_j
# ​​có giá trị giống nhau nhưng được sinh bởi hai thứ tự khác nhau thì vẫn được xem là khác nhau và xuất hiện hai lần trong tập hợp.
# Ví dụ, với dãy S = [1, 0, 1, 3], ta có thể sinh được số T = 1103 như sau:

# Xét số đầu tiên, T = 1.
# Xét số thứ hai, ta chèn 0 vào bên phải T, ta được T = 10.
# Xét số thứ ba, ta chèn 1 vào bên trái T, ta được T = 110.
# Xét số cuối cùng, ta chèn 3 vào bên phải T, ta thu được T = 1103.
# Tập sinh LR đầy đủ của dãy SS trên là {1013, 1103, 3110, 3101, 0113, 1013, 3011, 3101}.
# Lưu ý, ở dãy trên, số 1013 xuất hiện hai lần và được tính hai lần.

# Sau khi sinh xong, Alice đã viết toàn bộ những con số này lên bảng. 
# Bob thấy vậy bèn tự hỏi những số nào sẽ không vượt quá số B của mình. 
# Sau một chút bối rối, Bob đã tính xong tổng toàn bộ các số không vượt quá B.
# Là người được giao nhiệm vụ kèm cặp Bob học tập, bạn hãy tính lại tổng trên, lấy phần dư khi chia cho 10^9+7 giúp Bob nhé.

# Dữ liệu nhập
# Dòng đầu tiên chứa số nguyên Q là số lượng dãy số mà Alice đã dùng để sinh.
# Trong Q nhóm dòng tiếp theo, mỗi nhóm dòng chứa:

# Dòng đầu tiên chứa một dãy S gồm các số trong khoảng từ 0 tới 9, được viết liền nhau.
# Dòng thứ hai chứa số nguyên dương B, là số mà Bob muốn kiểm tra đối với dãy số này.
# Dữ liệu xuất
# Với mỗi dãy số của Alice, bạn hãy in ra phần dư của tổng các số sinh được từ tập sinh LR, không vượt quá số B tương ứng, khi chia cho 10^9+7.

# Ví dụ
# input
# 1
# 1013
# 3000
# output
# 3242 - {1013, 1103, 3̶̶1̶̶1̶̶0̶, 3̶̶1̶̶0̶̶1̶, 0113, 1013, 3̶̶0̶̶1̶̶1̶, 3̶̶1̶̶0̶̶1̶}.

numOfGroups = int(input())
for _ in range(numOfGroups):
    numList = input()
    testNum = int(input())
    initList = [numList[0], ]
    for idx in range(1, len(numList)):
        newList = []
        for val in initList:
            newList.extend([val + numList[idx], numList[idx] + val])
        initList = newList
    print(sum(int(x) for x in initList if int(x) < testNum))
    
    
    
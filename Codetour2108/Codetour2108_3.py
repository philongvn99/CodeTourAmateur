# Super Power
# Một đội gồm NN thành viên tham gia đánh Ải Viễn Chinh – Vương quốc gà, 
# mỗi người có một giá trị sức mạnh thể hiện khả năng chinh chiến trong trận đánh. 
# Khi 1 thành viên sử dụng búp thiên sứ XX cho đội thì sức mạnh của mỗi thành viên sẽ được tăng lên giá trị XX. 
# Khi Vua Gà dame lựu đạn X thì sức mạnh của mỗi thành viên sẽ giảm đi giá trị XX. 
# Đội trưởng là người có Super Power khi có thể tổng hợp sức mạnh của cả đội được tính bằng tổng giá trị tuyệt đối sức mạnh của từng thành viên để tung ra 1 đòn Power cực mạnh đánh Vua Gà. 
# Trong trận chiến có QQ lượt thay đổi giá trị sức mạnh của team khi thành viên sử dụng búp thiên sứ hoặc vua gà tung lựu đạn. 
# Do số lần sử dụng Power có hạn, hãy giúp đội trưởng tính sức mạnh của Super Power từ đầu đến cuối trận để đưa ra quyết định chọn tốt nhất.

# Dữ liệu nhập
# Dòng đầu tiên chứa số nguyên N là số lượng thành viên của đội và Q là số lượt thay đổi sức mạnh của đội.
# Dòng tiếp theo gồm NN số nguyên a_i là sức mạnh của từng thành viên.
# Q dòng tiếp theo, mỗi dòng gồm 1 kí tự, B nghĩa là thành viên dùng búp thiên sứ hoặc D nghĩa là Vua gà dame lựu đạn và 1 số nguyên X tương ứng giá trị thay đổi XX được cách nhau bởi khoảng trắng.

# Dữ liệu xuất
# In ra Q + 1 dòng, dòng đầu là sức mạnh của đội ban đầu và QQ dòng tiếp theo, mỗi dòng là sức mạnh ở Q lượt.

# VD:
# Input: 
# 4 3
# -1 0 2 -3
# D 1
# B 2
# D 3
# Output:
# 6 
# 8 - [-2 -1 1 -4]
# 6 - [0 1 3 -2]
# 10 - [-3 -2 0 -5]
mem, change = [int(x) for x in input().split()]
power = list(map(int, input().split()))
sum_ = 0
print(sum([-x if x < 0 else x for x in power]))
print(sum_)
for _ in range(change):
    type_, val = input().split()
    val = int(val) if type_ == "B" else -int(val)
    power = [x + val for x in power]
    print(sum([-x if x < 0 else x for x in power]))

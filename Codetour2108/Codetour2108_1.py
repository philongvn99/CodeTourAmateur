# Để kỷ niệm 2 năm ngày ra mắt trueID, nhóm nghiên cứu tổ chức một trò chơi để mọi người cùng vui với nhau trong buổi party. 
# Mỗi đội sẽ nhận được 1 con robot và ban tổ chức sẽ để một số tấm thẻ trên bàn. 
# Trên mỗi tấm thẻ sẽ ghi một số tiền tương ứng.
# Robot sẽ chọn một số thẻ liên tiếp nhau và nhận diện các con số trên thẻ. 
# Số tiền đội thắng cuộc sẽ nhận được là tổng số lớn nhất và nhỏ nhất ghi trên các tấm thẻ được chọn.

# Ví dụ, chọn các tấm thẻ 2, 6, 3, 82,6,3,8 thì số tiền nhận được là 8 + 2 = 108+2=10. 
# BTC cho bạn biết trước có những tấm thẻ với số tiền tương ứng nào và thứ tự của chúng khi đặt trên bàn. 
# Bạn hãy tính xem người chiến thắng sẽ nhận được số tiền tối đa là bao nhiêu để BTC có thể chuẩn bị tiền thưởng một cách chu đáo nhất 
# (ở đây quy ước chỉ có một người chiến thắng duy nhất).

numOfTest = int(input())

for _ in range(numOfTest):
  numOfCards = int(input())
  cardValueList = list(map(int, input().split()))
  max_ = 0
  for idx in range(numOfCards - 1):
    if cardValueList[idx] + cardValueList[idx + 1] > max:
        max_ = cardValueList[idx] + cardValueList[idx + 1]
  print(max_)
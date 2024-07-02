#lesson 2
from pickle import TRUE
from tkinter.tix import Tree
from unicodedata import east_asian_width
from unittest.util import sorted_list_difference


# begin

name ="chuo"
print(f"Hello {name.title},would you like to learn some python today?\t")

name_2 ="jack"
print(f"{name_2.lower()}\t")
print(f"{name_2.upper()}\t")
print(f"{name_2.title()}\t")

name_3 ="president Xi"
message="said china will be better in tomorrow\t"
print(f"{name_3.title()} {message}");

famous_saying =f"{name_3.title()} {message}"
print(famous_saying)

famous_person =" jonny demp "
print(famous_person.rstrip())
print(famous_person.lstrip())
print(famous_person.strip())



# lesson 3

eat_with = ["my grandpa","my little uncle","the girl"]
print(f"the pepole i want to have dinner together with is {eat_with[0]} {eat_with[1]} {eat_with[2]}")

print(f"{eat_with[1]} is busy")
eat_with[1] = "jack"
print(f"the pepole i want to have dinner together with is {eat_with[0]} {eat_with[1]} {eat_with[2]}")

bike = ["merida","giant","bmw"]
bike.insert(0,"phoniex")
print(bike)

print(sorted(bike))
print(bike)
print(sorted(bike,reverse=True))
print(bike)

bike.sort()
print(bike)
bike.sort(reverse=True)
print(bike)




# lesson 4

pizzas=["fruit pizza","meat pizza","vegetable pizza"]
for pizza in pizzas:
    print(f"i like {pizza}")
print("i realy like pizza!")
# 通过range来创建列表
value=list(range(1,21))
for num in value:
    print(f"{num} ")

ten_million=range(1,1000001)
print(f"the min of ten_million is {min(ten_million)},and the max is {max(ten_million)},sum is{sum(ten_million)}")

odd_num=list(range(1,21,2))
print(odd_num)

divded_by3=list(range(3,31,3))
print(divded_by3)

lifang=[num**3 for num in range(1,10)]
print(lifang)
# 分片
items=["cup","button","mouse","capbroad","books"]
print(items[:3])
print(items[1:4])
print(items[2:6])

array = ["jack", "tom", "lussy", "kit"]
array.insert(1, "chuo")
array.append("jakkk")


# lesson 5 条件判断语句 和 数学符

alien_color ="red"
if alien_color=="green":
    print("you got 5 points!")
elif alien_color!="green":
    print("you got 10 points")

age=32
if age<2:
    print("a baby")
elif 2<age<4:
    print("a big baby")
elif 4<age<13:
    print("a puiple")
elif 13<age<20:
    print("a teenager")
elif 20<age<64:
    print("an adult")
else:
    print("old people")




# lesson 6 字典

favorite_language = {
    "sanny" : "python",
    "jack" : "C",
    "chuo" : "C++", 
    "tom" : "java"
    }

chuo_prefer = favorite_language["chuo"]
print(f"chuo likes {chuo_prefer} best\n")

alp_table_py = {
    "del" : "to delete a member of a container",
    "f" : "to combine a variable with a string",
    "for in" : "loop sentence",
    "list()" : "to create a list by range()",
    "if elif" : "conditional statement"
    }
for technical_word, mean in alp_table_py.items():
    print(f"python术语:{technical_word} : {mean}\n")

print("添加前\n")

alp_table_py["[:]"] = "分片"
alp_table_py["set()"] = "哈希表"
alp_table_py["map.keys()"] = "返回键值对""返回key"
alp_table_py["map.items()"] = "返回键值对"

for technical_word, mean in alp_table_py.items():
    print(f"python术语:{technical_word} : {mean}\n")

# 6-7
ben = {
    "first_name" : "肖",
    "last_name" : "zb",
    "age" : "24",
    "city" : "英德"
}
neymar = {
    "first_name" : "刘",
    "last_name" : "gb",
    "age" : "24",
    "city" : "大湾"  
}
jane = {
    "first_name" : "邓",
    "last_name" : "zw",
    "age" : "24",
    "city" : "广州"  
}
fang = {
    "first_name" : "黄",
    "last_name" : "zw",
    "age" : "25",
    "city" : "深圳" 
}
chris = {
    "first_name" : "吴",
    "last_name" : "wj",
    "age" : "24",
    "city" : "英德" 
}
my_real_friends = [ben, neymar, jane, fang, chris]
for info in my_real_friends:
    for key, val in info.items():
        print(f"{key} : {val}")
    print("\n")
# 6-8 略
# 6-9 省略了。。
favorite_places ={}
favorite_places["ben"] = ["Tokyo", "singopore", "Thailand"]
# 6-10
cities = {}
cities["Tokyo"] = {"country" : "JP", "popularity" : "1 billion", "fact" : "rich and modern and cold"}
cities["NewYork"] = {"country" : "USA", "popularity" : "2 billion", "fact" : "rich and modern and free"}
cities["HongKong"] = {"country" : "CN", "popularity" : "14 billion", "fact" : "rich and modern and small"}
for dictionary in cities.items():
    print(dictionary)
# lesson 7 循环







# lesson 8 function
def display_message():
    print("this section is taught about function in Python")
def favorite_book(book_name):
    print(f"my favorite book is {book_name.title()}")

display_message()
favorite_book("walking in the daynight")

def make_album(singer_name, album_name, nums = 0):
    res = {}
    if nums:
        res["singer_name"] = singer_name
        res["album_name"] = album_name
        res["num of songs"] = nums
    else :
        res["singer_name"] = singer_name
        res["album_name"] = album_name
    return res

singer_name = ""
album_name = ""


tmp_str = "asdfasf"
print(type(tmp_str))



#文件读写
f = open("to_be_copyed.txt", "r", encoding = "UTF-8")
cpy = open("副本", "a", encoding = "UTF-8")
dict_tmp = {}
for line in f:
    words = line.split()
    for element in words:
        ++dict_tmp[element]

print(dict_tmp)
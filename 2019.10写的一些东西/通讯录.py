import json
info = [] #创建一个列表用于存放字典
def Traverse():
    if len(info):
        for people in info[:]:
            print(people)
    else:
        print("当前无数据")
            
def Search():
    if len(info):
        target = input("请输入你想要查找的姓名")
        for people in info[:]:
            if people['name'] == target:
                print(people)
            else :
                print("未找到！")
    else:
         print("无数据！")

def Add():
    new_people = {}
    new_people['name'] = input("请输入名字")
    new_people['tel'] = int(input("请输入手机号"))
    new_people['type'] = input("请输入类别")
    info.append(new_people)

def Summary():
    if len(info):
        sign = 0
        choice = int(input("A类请按1，B类请按2，C类请按3"))
        if choice == 1:
            for people in info[:]:
                if people['type'] == 'A' or people['type'] == 'a':
                    print(people)
                    sign = 1;

        if choice == 2:
            for people in info[:]:
                if people['type'] == 'B' or people['type'] == 'b':
                    print(people)
                    sign = 1;

        if choice == 3:
            for people in info[:]:
                if people['type'] == 'C' or people['type'] == 'c':
                    print(people)
                    sign = 1
        if(sign):
            print("已全部显示")
        elif sign == 0:
            print("该类别下无数据")

    else:
        sign = 0
        print("当前无数据！")


def Del():
    sign = 0;
    i = 0;#说明要删除的数据在第几个位置
    if(len(info)):
        target = input("请输入你想要删除的名字")
        for people in info[:]:
            if people['name'] == target:#如果找到了跳出循环
                sign = 1
                break
            else:#当前数据不是则继续循环，i++，位置后移
                i+=1
        del info[i]#删除
        if sign == 0:
            print("删除失败")
        else:
            print("删除成功")
    else:
        print("当前无数据")

def Modify():
    if len(info):
        Traverse()
        target = input("请输入你想要修改的姓名")
        for people in info[:]:
            if people['name'] == target:
                people['name'] = input("请输入修改过后的姓名")
                people['tel'] = int(input("请输入修改过后的手机号"))
                people["type"] = input("请输入修改过后的类别")
    else:
         print("没数据怎么改啊？？？")

def save():
    filename = '通讯录.json'
    with open(filename,'w') as f_obj:
        for people in info[:]:
            json.dump(people,f_obj)

def read():
    filename = '通讯录.json'
    with open(filename) as f_obj:
        new_people = json.load(f_obj)
        info.append(new_people)
    
q = 1
read()
while(q):
    print("通讯录管理系统   produced by zyh\n")
    print("遍历联系人请按1")
    print("输入联系人信息请按2")
    print("查找联系人请按3")
    print("查询某一类别请按4")
    print("删除联系人请按5")
    print("修改联系人请按6")
    print("存储联系人请按7")
    print("退出系统请按0")
    choice = int(input("请输入你的选择"))
    if choice == 1:
        Traverse();

    elif choice == 2:
        Add()
        
    elif choice == 3:
        Search()

    elif choice == 4:
        Summary()

    elif choice == 5:
        Del()
        Traverse()

    elif choice == 6:
        Modify()

    elif choice == 7:
        save()
        
    elif choice == 0:
        break

    q = int(input("还想继续使用系统吗？继续请按1，退出请按0"))


